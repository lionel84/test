/*
 * @Auth: lionelzhang
 * @Date: 2021-02-01 17:11:24
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-02-02 16:06:56
 * @Description: 
 */
 #include "base.h"

 #define TIMER_HANDLE_CB_DATA_LEN (64)
namespace nm_timer
{
    template<typename T>
    struct LINKHEAD
    {
        LINKHEAD():head_obj(nullptr), tail_obj(nullptr){};
        T* head_obj; //如果链表为空该值为0
        T* tail_obj; //如果链表为空该值为0
    };

    template<typename T>
    struct LINKNODE
    {
        LINKNODE():prev_obj(nullptr), next_obj(nullptr){}
        T* prev_obj; //如果是链表首节点该值为0
        T* next_obj; //如果是链表尾节点该值为0
    };
    template<typename T>
    int add_head(LINKHEAD<T> *head, T* obj)
    {
        if(!head){
            return -1;
        }
        if(!obj){
            return -1;
        }

        auto node_1st = head->head_obj;
        if (node_1st == NULL)
        {
            obj->next_obj = nullptr;
            obj->prev_obj = nullptr;
            head->head_obj = obj;
            head->tail_obj = obj;
        }
        else
        {
            obj->next_obj = head->head_obj;
            obj->prev_obj = 0;
            node_1st->prev_obj = obj;
            head->head_obj = obj;
        }
        
        return 0;
    }

    template<typename T>
    int add_tail(LINKHEAD<T> *head, T* obj)
    {
        if(!head){
            return -1;
        }
        if(!obj){
            return -1;
        }

        auto node_last = head->tail_obj;
        if (node_last == NULL)
        {
            obj->next_obj = 0;
            obj->prev_obj = 0;
            head->head_obj = obj;
            head->tail_obj = obj;
        }
        else
        {
            obj->next_obj = 0;
            obj->prev_obj = head->tail_obj;
            node_last->next_obj = obj;
            head->tail_obj = obj;
        }

        return 0;
    }

    template<typename T>
    int del_node(LINKHEAD<T> *head, T* obj)
    {
        if(!head){
            return -1;
        }
        if(!obj){
            return -1;
        }

        auto prev = obj->prev_obj;
        auto next = obj->next_obj;

        if (prev != NULL)
        {
            prev->next_obj = obj->next_obj;
        }

        if (next != NULL)
        {
            next->prev_obj = obj->prev_obj;
        }

        if (head->head_obj == obj)
        {
            head->head_obj = obj->next_obj;
        }

        if (head->tail_obj == obj)
        {
            head->tail_obj = obj->prev_obj;
        }

        return 0;
    }
    struct TIMER_HANDLE;
    using TIMEOUT_FUNC = std::function<void(TIMER_HANDLE* handle, void *cb_data, size_t cb_data_len)> ;
    struct TIMER_HANDLE:public LINKNODE<TIMER_HANDLE>{
        uint64_t timer_id;
        int32_t expires;    // 首次超时时间
        int32_t interval;   // 间隔时间
        int32_t repeats;    // 执行次数
        bool is_forever; // 永久执行
        bool is_running; 

        TIMEOUT_FUNC timeout_funcs;
        char cb_data[TIMER_HANDLE_CB_DATA_LEN];
        int32_t cb_data_len;
    };
    class RBTREE_TIMER_MGR{
    public:
        static RBTREE_TIMER_MGR* me(){
            static RBTREE_TIMER_MGR mgr;
            return &mgr;
        }
        RBTREE_TIMER_MGR():default_timer_id(0){
            
        };
        int32_t tick(int32_t now){
            int32_t tick_count = 0;
            while(true){
                auto it = timer_.begin();
                if(it == timer_.end())break;
                if(now < it->first){
                    break;
                }
                for(TIMER_HANDLE* handle = it->second.head_obj; handle != nullptr; handle= it->second.head_obj){
                    handle->timeout_funcs(handle, handle->cb_data, handle->cb_data_len);
                    tick_count ++;
                    if(handle->repeats){
                        handle->repeats --;
                    }
                    del_timer(handle);
                    if(handle->is_forever || handle->repeats){
                        handle->expires += handle->interval;
                        add_timer(handle);
                    }else{
                        delete handle;
                    }
                }
                //clear
                timer_.erase(it);
                
            }
            return tick_count;
        }
        TIMER_HANDLE* add_timer(uint32_t firstcall_interval // timer第一次被唤醒的延迟时间(单位:tick)
            , uint32_t repeat_interval    // timer第二次之后(含第二次)的超时间隔(单位:tick)
            , uint32_t repeat_num         // 重复次数，无限调用使用REPEAT_FOREVER
            , TIMEOUT_FUNC fn
            , const void *cb_data
            , size_t cb_data_len){
            if(repeat_interval == 0 && repeat_num != 0)return nullptr;
            struct timeval tv;
            gettimeofday(&tv, NULL);
            int32_t now = tv.tv_sec;
            TIMER_HANDLE* handle = new TIMER_HANDLE();
            handle->timer_id = default_timer_id ++;
            handle->expires = now + firstcall_interval;
            handle->interval= repeat_interval;
            handle->repeats = repeat_num;
            handle->is_forever = repeat_interval != 0 && repeat_num == 0;
            handle->timeout_funcs = fn;
            if(cb_data_len && cb_data_len <= TIMER_HANDLE_CB_DATA_LEN)
                memcpy(handle->cb_data, cb_data, cb_data_len);
            handle->cb_data_len = cb_data_len;
            add_timer(handle);
            return handle;
        }

        void add_timer(TIMER_HANDLE* handle)
        {
            auto it = timer_.find(handle->expires);
            if(it == timer_.end()){
                LINKHEAD<TIMER_HANDLE> head ;
                add_tail(&head, handle);
                timer_.insert(std::make_pair(handle->expires, std::move(head)));
            }else{
                add_tail(&(it->second), handle);
            }
        }
        
        int32_t del_timer(TIMER_HANDLE* handle){
            if(!handle)return 0;
            auto it = timer_.find(handle->expires);
            if(it == timer_.end())return 0;
            del_node(&(it->second), handle);
            return 0;
        }

        uint64_t default_timer_id;
        std::map<int32_t, LINKHEAD<TIMER_HANDLE> > timer_;
    };
    template<typename K_T, typename V_T>
    class HEAP{
        using K_V_T = std::pair<K_T, V_T>;
        public:
        int32_t up(int32_t i){
            while(i > 0){
                if(db_[i].first < db_[i/2].first){
                    swap(db_[i], db_[i/2]);
                    i = i/2;
                    continue;
                }else{
                    break;
                }
            }
            return i;
        }
        int32_t down(int32_t i){
            while(i < db_.size()){
                int32_t check_idx = i*2 +1;
                if(check_idx >= db_.size())break;
                if(check_idx + 1 < db_.size()){
                    if(db_[check_idx].first > db_[check_idx + 1].first){
                        check_idx += 1;
                    }
                }
                swap(db_[i], db_[check_idx]);
                i = check_idx;
            }
            return i;
        }
        void push(K_V_T kv){
            db_.push_back(std::move(kv));
            up(db_.size() -1 );
        }
        K_V_T* top(){
            if(db_.size() == 0)return nullptr;
            return &db_[0];
        }
        void pop(){
            // 
            if(db_.size() == 0 )return;
            swap(db_[0], db_.back());
            db_.pop_back();
            if(db_.size() == 0)return;
            down(0);
        }
        bool empty(){
            return db_.size() == 0;
        }
        vector<std::pair<K_T, V_T> > db_;
    };
    class HEAP_TIMER_MGR{
    public:
        static HEAP_TIMER_MGR* me(){
            static HEAP_TIMER_MGR mgr;
            return &mgr;
        }
        HEAP_TIMER_MGR():default_timer_id(0){
            
        };
        int32_t tick(int32_t now){
            int32_t tick_count = 0;
            while(true){
                auto it = timer_.top();
                if(!it)break;
                if(now < it->first){
                    break;
                }
                TIMER_HANDLE* handle = it->second;
                
                handle->timeout_funcs(handle, handle->cb_data, handle->cb_data_len);
                tick_count ++;
                if(handle->repeats){
                    handle->repeats --;
                }
                timer_.pop();
                // del_timer(handle);
                if(handle->is_forever || handle->repeats){
                    handle->expires += handle->interval;
                    add_timer(handle);
                }else{
                    delete handle;
                }
            }
            return tick_count;
        }
        TIMER_HANDLE* add_timer(uint32_t firstcall_interval // timer第一次被唤醒的延迟时间(单位:tick)
            , uint32_t repeat_interval    // timer第二次之后(含第二次)的超时间隔(单位:tick)
            , uint32_t repeat_num         // 重复次数，无限调用使用REPEAT_FOREVER
            , TIMEOUT_FUNC fn
            , const void *cb_data
            , size_t cb_data_len){
            if(repeat_interval == 0 && repeat_num != 0)return nullptr;
            struct timeval tv;
            gettimeofday(&tv, NULL);
            int32_t now = tv.tv_sec;
            TIMER_HANDLE* handle = new TIMER_HANDLE();
            handle->timer_id = default_timer_id ++;
            handle->expires = now + firstcall_interval;
            handle->interval= repeat_interval;
            handle->repeats = repeat_num;
            handle->is_forever = repeat_interval != 0 && repeat_num == 0;
            handle->timeout_funcs = fn;
            if(cb_data_len && cb_data_len <= TIMER_HANDLE_CB_DATA_LEN)
                memcpy(handle->cb_data, cb_data, cb_data_len);
            handle->cb_data_len = cb_data_len;
            add_timer(handle);
            return handle;
        }

        void add_timer(TIMER_HANDLE* handle)
        {
            timer_.push(std::make_pair(handle->expires, handle));
            
        }

        uint64_t default_timer_id;
        HEAP<int32_t, TIMER_HANDLE* > timer_;
    };
    class WHEEL_TIMER_MGR{
    public:
        #define TVN_BITS 6
        #define TVR_BITS 8
        #define TVN_SIZE (1 << TVN_BITS)
        #define TVR_SIZE (1 << TVR_BITS)
        #define TVN_MASK (TVN_SIZE - 1)
        #define TVR_MASK (TVR_SIZE - 1)

        #define TV1_MAX TVR_SIZE
        #define TV2_MAX (1 << (TVR_BITS + 1 * TVN_BITS))
        #define TV3_MAX (1 << (TVR_BITS + 2 * TVN_BITS))
        #define TV4_MAX (1 << (TVR_BITS + 3 * TVN_BITS))

        #define TV1_IDX(tick) ((tick) & TVR_MASK)
        #define TV2_IDX(tick) (((tick) >> TVR_BITS) & TVN_MASK)
        #define TV3_IDX(tick) (((tick) >> (TVR_BITS + 1 * TVN_BITS)) & TVN_MASK)
        #define TV4_IDX(tick) (((tick) >> (TVR_BITS + 2 * TVN_BITS)) & TVN_MASK)
        #define TV5_IDX(tick) (((tick) >> (TVR_BITS + 3 * TVN_BITS)) & TVN_MASK)
        struct TIMER_VECTOR
        {
            LINKHEAD<TIMER_HANDLE> vec[TVN_SIZE];
        };

        struct TIMER_VECTOR_ROOT
        {
            LINKHEAD<TIMER_HANDLE> vec[TVR_SIZE];
        };
        static WHEEL_TIMER_MGR* me(){
            static WHEEL_TIMER_MGR mgr;
            return &mgr;
        }
        WHEEL_TIMER_MGR():default_timer_id(0), timer_handle_count(0){
            cur_tick = get_cur_tick();
        };
        bool empty(){
            return timer_handle_count == 0;
        }
        static int64_t get_cur_tick(){
            struct timeval tv;
            gettimeofday(&tv, NULL);
            return tv.tv_sec;
        }
        LINKHEAD<TIMER_HANDLE>* find_handle_list(int64_t expires)
        {
            uint64_t idx = expires - cur_tick;

            if (idx < TV1_MAX)
            {
                return &tv1.vec[TV1_IDX(expires)];
            }
            else if (idx < TV2_MAX)
            {
                return &tv2.vec[TV2_IDX(expires)];
            }
            else if (idx < TV3_MAX)
            {
                return &tv3.vec[TV3_IDX(expires)];
            }
            else if (idx < TV4_MAX)
            {
                return &tv4.vec[TV4_IDX(expires)];
            }
            else
            {
                /* If the timeout is larger than 0xffffffff on 64-bit
                    * architectures then we use the maximum timeout:
                    */
                if (idx > 0xffffffffUL)
                {
                    idx = 0xffffffffUL;
                    expires = idx ;
                }
                return &tv5.vec[TV5_IDX(expires)];
            }
        }
        void cascade(LINKHEAD<TIMER_HANDLE> *src)
        {
            TIMER_HANDLE* handle = src->head_obj;
            while (handle)
            {
                auto next_handle = handle->next_obj;
            
                LINKHEAD<TIMER_HANDLE> *dst = find_handle_list(handle->expires);       
                add_tail(dst, handle);

                handle = next_handle;
            }

            src->head_obj = nullptr;
            src->tail_obj = nullptr;
        }

        int32_t tick(int32_t now){
            int32_t tick_count = 0;
            int32_t tick_num = get_cur_tick() - cur_tick;
            for(int32_t i = 0; i< tick_num; i++){
                int tv1_idx = TV1_IDX(cur_tick);

                do {
                    if (tv1_idx != 0) break;

                    int tv2_idx = TV2_IDX(cur_tick);
                    cascade(&tv2.vec[tv2_idx]);
                    if (tv2_idx != 0) break;

                    int tv3_idx = TV3_IDX(cur_tick);
                    cascade(&tv3.vec[tv3_idx]);
                    if (tv3_idx != 0) break;

                    int tv4_idx = TV4_IDX(cur_tick);
                    cascade(&tv4.vec[tv4_idx]);
                    if (tv4_idx != 0) break;

                    int tv5_idx = TV5_IDX(cur_tick);
                    cascade(&tv5.vec[tv5_idx]);

                } while(0);
            

                LINKHEAD<TIMER_HANDLE> *head = &tv1.vec[tv1_idx];
                
                while (head->head_obj)
                {
                    auto handle = head->head_obj;
                    del_node(head, handle);
                    timer_handle_count --;

                    handle->is_running = 1;
                    handle->repeats--;
                    
                    if(handle->timeout_funcs)
                        handle->timeout_funcs(handle, handle->cb_data, handle->cb_data_len);
                    tick_count ++;
                    
                    handle->is_running = 0;
                    
                    if(handle->is_forever || handle->repeats){
                        handle->expires += handle->interval;
                        add_timer(handle);
                    }else{
                        delete handle;
                        continue;
                    }

                }
                cur_tick++;
            }
            return tick_count;
        }
        TIMER_HANDLE* add_timer(uint32_t firstcall_interval // timer第一次被唤醒的延迟时间(单位:tick)
            , uint32_t repeat_interval    // timer第二次之后(含第二次)的超时间隔(单位:tick)
            , uint32_t repeat_num         // 重复次数，无限调用使用REPEAT_FOREVER
            , TIMEOUT_FUNC fn
            , const void *cb_data
            , size_t cb_data_len){
            if(repeat_interval == 0 && repeat_num != 0)return nullptr;
            struct timeval tv;
            gettimeofday(&tv, NULL);
            int32_t now = tv.tv_sec;
            TIMER_HANDLE* handle = new TIMER_HANDLE();
            handle->timer_id = default_timer_id ++;
            handle->expires = now + firstcall_interval;
            handle->interval= repeat_interval;
            handle->repeats = repeat_num;
            handle->is_forever = repeat_interval != 0 && repeat_num == 0;
            handle->timeout_funcs = fn;
            if(cb_data_len && cb_data_len <= TIMER_HANDLE_CB_DATA_LEN)
                memcpy(handle->cb_data, cb_data, cb_data_len);
            handle->cb_data_len = cb_data_len;
            add_timer(handle);
            return handle;
        }

        void add_timer(TIMER_HANDLE* handle)
        {
            LINKHEAD<TIMER_HANDLE> *list = find_handle_list(handle->expires);
            add_tail(list, handle);
            timer_handle_count ++;
        }
        
        int32_t del_timer(TIMER_HANDLE* handle){
            if(!handle)return 0;
            LINKHEAD<TIMER_HANDLE> *list = find_handle_list(handle->expires);
            del_node(list, handle);
            timer_handle_count -- ;
        }
        int32_t timer_handle_count;
        uint64_t default_timer_id;
        TIMER_VECTOR_ROOT tv1;
        TIMER_VECTOR tv2;
        TIMER_VECTOR tv3;
        TIMER_VECTOR tv4;
        TIMER_VECTOR tv5;
        int64_t cur_tick;
    };
    void test();
}