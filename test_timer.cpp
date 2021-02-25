/*
 * @Auth: lionelzhang
 * @Date: 2021-02-01 17:11:17
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-02-02 16:00:19
 * @Description: 
 */

#include "test_timer.h"
#include "uv.h"
namespace nm_timer
{
    void test(){
        uv_timer_t tick_timer;
        uv_timer_init(uv_default_loop(), &tick_timer);
        cout<<"begin"<<endl;
        const int count = 100000;
        printnow();
        for(int i = 0; i< count; i++){
            WHEEL_TIMER_MGR::me()->add_timer(2, 2, 4, [](TIMER_HANDLE* handle, void *cb_data, size_t cb_data_len){
                //std::cout<<"cb"<<endl;
            }, nullptr, 0);
        }
        printnow("WHEEL_TIMER_MGR add_timer:");
        for(int i = 0; i< count; i++){
            RBTREE_TIMER_MGR::me()->add_timer(2, 2, 4, [](TIMER_HANDLE* handle, void *cb_data, size_t cb_data_len){
                //std::cout<<"cb"<<endl;
            }, nullptr, 0);
        }
        printnow("RBTREE_TIMER_MGR add_timer ");
        for(int i = 0; i< count; i++){
            HEAP_TIMER_MGR::me()->add_timer(2, 2, 4, [](TIMER_HANDLE* handle, void *cb_data, size_t cb_data_len){
                //std::cout<<"cb"<<endl;
            }, nullptr, 0);
        }
        printnow("HEAP_TIMER_MGR add_timer ");
        uv_timer_start(&tick_timer, [](uv_timer_t *handle){
            struct timeval tv;
            gettimeofday(&tv, NULL);
            int32_t now = tv.tv_sec;
            printnow();
            {
                int32_t tick_count = WHEEL_TIMER_MGR::me()->tick(now);
                cout<<tick_count<<endl;
                printnow("WHEEL_TIMER_MGR tick:");
            }
            {
                int32_t tick_count = RBTREE_TIMER_MGR::me()->tick(now);
                cout<<tick_count<<endl;
                printnow("RBTREE_TIMER_MGR tick:");
            }
            {
                int32_t tick_count = HEAP_TIMER_MGR::me()->tick(now);
                cout<<tick_count<<endl;
                printnow("HEAP_TIMER_MGR tick:");
            }
            if(WHEEL_TIMER_MGR::me()->empty()){
                uv_stop(uv_default_loop());
            }
        }, 1000, 1000); // ms
        
        uv_run(uv_default_loop(), UV_RUN_DEFAULT);
        uv_close((uv_handle_t *)&tick_timer, nullptr);
    }
}