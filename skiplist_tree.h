/*
 * @Auth: lionelzhang
 * @Date: 2020-10-27 11:07:08
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-29 21:28:43
 * @Description: 
 */
#ifndef __SKIPLIST_TREE_H__
#define __SKIPLIST_TREE_H__

#include <random>

#include <ctime>
#include <initializer_list>
#include <iostream>
#include <random>
#include <climits>  
#include <unordered_map>
#include <memory>

#define SKIP_LIST_MEM_MONITER
namespace nm_skiplist {

#define ZSKIPLIST_MAXLEVEL 64 /* Should be enough for 2^64 elements */
#define ZSKIPLIST_P 0.25  

using rank_t = int64_t ;

#pragma pack(1)
template <typename rank_data_value_t> // 需要定义操作符 == 和 <
struct zskiplistNode
{
    using node_t = zskiplistNode<rank_data_value_t>;
    using rank_t = int64_t ;
    using rank_data_type = std::shared_ptr<rank_data_value_t>;

    struct zskiplistNode *backward;
    rank_data_type _rank_data;
    
#ifdef SKIP_LIST_MEM_MONITER
    size_t _mem;
#endif
    //每层的节点信息
    struct zskiplistLevel
    {
        node_t *forward;  //当前层当前节点下一个节点
        rank_t span;
    } _level[]; // 这里按需分配，可以节约极大空间

#ifdef SKIP_LIST_MEM_MONITER
    zskiplistNode(int mem):_mem(mem), backward(nullptr) {}
    zskiplistNode(int mem, rank_data_type rank_data):_mem(mem), _rank_data(rank_data), backward(nullptr){}
#else
    zskiplistNode():backward(nullptr) {}
    zskiplistNode(rank_data_type rank_data):_rank_data(rank_data), backward(nullptr){}
#endif
};

template <typename rank_data_key_t, typename rank_data_value_t , typename comp_less_t = std::less<rank_data_value_t> >
class zskiplist
{
    using node_t = zskiplistNode<rank_data_value_t>;
    using node_pointer_t = zskiplistNode<rank_data_value_t>* ; 

    using rank_t = int64_t;
    using rank_data_type = std::shared_ptr<rank_data_value_t>; //std::pair<rank_data_key_t, std::shared_ptr<rank_data_value_t> >; //
    using pointer = rank_data_type;
    using const_pointer = const rank_data_type;
    using reference = rank_data_type&;
    using const_reference = const rank_data_type&;
public:
    /**
     * 注意初始化的时候调表的头部指针已经存在但是长度为0
     */
    void init()
    {
#ifdef SKIP_LIST_MEM_MONITER
        m_memory = 0;
#endif
        m_level = 1;
        m_length = 0;
        m_header = zslCreateNode(ZSKIPLIST_MAXLEVEL); // new node_t(ZSKIPLIST_MAXLEVEL);
        
        for (int j = 0; j < ZSKIPLIST_MAXLEVEL; j++) {
            m_header->_level[j].forward = NULL;
            m_header->_level[j].span = 0;
        }

        m_tail = nullptr;
    }
    zskiplist()
    {
        init();
    }
    ~zskiplist()
    {
        node_t *node = m_header->_level[0].forward, *next;
        zslFreeNode(m_header);
        while(node) {
            next = node->_level[0].forward;
            zslFreeNode(node);
            node = next;
        }
    }
 /*
    skiplist_t &GetMskiplist()
    {
        return mskiplist;
    }
*/
    inline uint64_t GetMem(){
#ifdef SKIP_LIST_MEM_MONITER
        return m_memory;
#else
        return 0;
#endif
    }
    
    static node_pointer_t prev(node_pointer_t h)
    {
        return h->backward;
    }

    static node_pointer_t next(node_pointer_t h)
    {
        return h->_level[0].forward;
    }
    class iterator
    {
    public:
        iterator(node_pointer_t p):m_p(p){}
        iterator():m_p(nullptr){}
        iterator operator--()
        {
            m_p = prev(m_p);
            return *this;
        }
        iterator operator++()
        {
            m_p = next(m_p);
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --*this;
            return tmp;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
        
        reference operator*()
        {
            return m_p->_rank_data;
        }
        
        pointer operator->()
        {
            return pointer(m_p->_rank_data);
        }
        bool operator==(iterator other) const
        {
            return m_p == other.m_p;
        }
        bool operator !=(iterator other) const
        {
            return !(*this == other);
        }
    private:
        node_pointer_t m_p;
        friend class zskiplist;
    };

    iterator begin(){
        return iterator(m_header->_level[0].forward);
    }
    iterator end(){
        return iterator(nullptr);
    }
    iterator back(){
        return iterator(m_tail);
    }
    size_t size(){
        return m_length;
    }
private:
    /**
     * 创建一个节点
     * @param level
     * @param score
     * @param value
     * @return
     */
    node_t* zslCreateNode(int level,rank_data_type rank_data = rank_data_type()){
        //node_t *p = new node_t(level, rank_data);
        size_t need_mem = sizeof(node_t)+level*sizeof(struct node_t::zskiplistLevel);
        void *p_m = malloc(need_mem);
        if(!p_m)return nullptr;
#ifdef SKIP_LIST_MEM_MONITER
        node_t *p = new(p_m)node_t(need_mem, rank_data);
        m_memory += need_mem;
#else
        node_t *p = new(p_m)node_t(rank_data);
#endif
        return p;
    }

    void zslFreeNode(node_t*& p){
#ifdef SKIP_LIST_MEM_MONITER
        m_memory -= p->_mem;
#endif
        if(p == nullptr)return;
        delete p;
        p = nullptr;
    }
 
    //随机跳表的层数
    int zslRandomLevel(void)
    {
        int level = 1;
        while ((random() & 0xFFFF) < (ZSKIPLIST_P * 0xFFFF))
            level += 1;
        return (level < ZSKIPLIST_MAXLEVEL) ? level : ZSKIPLIST_MAXLEVEL;
    }
public:
    // std::pair<rank_data_key_t, std::shared_ptr<rank_data_value_t> >
    iterator zslInsert(const rank_data_key_t& key, rank_data_type  rank_data){
        if(m_cache.find(key) != m_cache.end()){
            return iterator(nullptr);
        }
        node_t *update[ZSKIPLIST_MAXLEVEL] = {0}; //每一层需要修改的结点,在每层中，新的节点需要插入在该节点的后面
        rank_t rank[ZSKIPLIST_MAXLEVEL];
        node_t *tmpNode;
        int i, level;
    
        tmpNode = m_header;
        for (i = m_level-1; i >= 0; i--)
        {
            rank[i] = i == (m_level-1) ? 0 : rank[i+1];
            //如果当前节点的下一个节点is not null，且他的下一个节点的score小于插入节点的score，或者他们积分相等但是ele小于插入节点的ele，则继续往后找，直到
            //找到条件不满足的跳出循环，则新插入的节点需要插入该层的当前节点后面，把此节点记录到update数组中
            while (tmpNode->_level[i].forward && m_comp_less(*tmpNode->_level[i].forward->_rank_data , *rank_data))
            {
                rank[i] += tmpNode->_level[i].span;
                tmpNode = tmpNode->_level[i].forward;
            }
            update[i] = tmpNode;
        }
    
        //随机层数
        level = zslRandomLevel();
        //如果随机的层数比当前skiplist的层数要大，则补充高出的层的每层update节点信息
        if (level > m_level)
        {
            for (i = m_level; i < level; i++)
            {
                rank[i] = 0;
                update[i] = m_header; //当前节点初始化为header
                update[i]->_level[i].span = m_length;
            }
            m_level = level;  //更新skiplist的层数
        }
    
        //创建节点
        tmpNode = zslCreateNode(level,rank_data);
        for (i = 0; i < level; i++)
        {
            //修改创建节点tmpNode,需要修改的节点的forward指针(从每层来看上是一个链表的插入操作即把tmpNode插入到update[i]后面)
            tmpNode->_level[i].forward = update[i]->_level[i].forward;
            update[i]->_level[i].forward = tmpNode;
            /* update span covered by update[i] as x is inserted here */
            tmpNode->_level[i].span = update[i]->_level[i].span - (rank[0] - rank[i]);
            update[i]->_level[i].span = (rank[0] - rank[i]) + 1;
        }
        /* increment span for untouched levels */
        for (i = level; i < m_level; i++) {
            update[i]->_level[i].span++;
        }

        tmpNode->backward = (update[0] == m_header) ? nullptr : update[0];

        if (tmpNode->_level[0].forward == nullptr)
        {
            m_tail = tmpNode;
        }else{
            tmpNode->_level[0].forward->backward = tmpNode;
        }
        m_length++;
        m_cache.insert(std::make_pair(key, tmpNode));
        return iterator(tmpNode);
    }

    void _zslDeleteNode(node_t* x, node_t **update){
        int i;
        for (i = 0; i < m_level; i++) {
            if (update[i]->_level[i].forward == x) {
                update[i]->_level[i].span += x->_level[i].span - 1;
                update[i]->_level[i].forward = x->_level[i].forward;
            } else {
                update[i]->_level[i].span -= 1;
            }
        }
        if (x->_level[0].forward) {
            x->_level[0].forward->backward = x->backward;
        } else {
            m_tail = x->backward;
        }
        while(m_level > 1 && m_header->_level[m_level-1].forward == nullptr)
            m_level--;
        m_length--;
    }

    bool zslDelete(iterator it){
        if(it == end())return false;
        return zslDelete(it->key());
    }
    
    bool zslDelete(const rank_data_key_t& key){
        auto it = m_cache.find(key);
        if(it == m_cache.end())
            return false;
        rank_data_type rank_data = it->second->_rank_data;
        node_t *update[ZSKIPLIST_MAXLEVEL] = {0}; //每一层需要修改的结点,在每层中，新的节点需要插入在该节点的后面
        node_t * tmpNode;
        int i;
    
        tmpNode = m_header;
        for (i = m_level-1; i >= 0; i--)
        {
            //如果当前节点的下一个节点is not null，且他的下一个节点的score小于插入节点的score，或者他们积分相等但是ele小于插入节点的ele，则继续往后找，直到
            //找到条件不满足的跳出循环，则每层要删除的节点的前一个节点都存在update数组中
            while (tmpNode->_level[i].forward && m_comp_less(*tmpNode->_level[i].forward->_rank_data , *rank_data))
            {
                tmpNode = tmpNode->_level[i].forward;
            }

            update[i] = tmpNode;
        }
    
        tmpNode = tmpNode->_level[0].forward;
        if(tmpNode == it->second) //&& tmpNode->_rank_data->key() == key)
        {
            _zslDeleteNode(tmpNode, update);
            m_cache.erase(it);
            zslFreeNode(tmpNode);
            return true;
        }
    
        return false; /* not found */
    }
    
    iterator zslUpdateScore(const rank_data_key_t& key, rank_data_type rank_data) {
        node_t *x = nullptr;
        auto it = m_cache.find(key);
        if(it != m_cache.end()){
            x = it->second;
        }
        
        if(x){
            zslDelete(key);
        }
        
        iterator newnode = zslInsert(key, rank_data);
        if(newnode.m_p){
            m_cache[key] = newnode.m_p ;
        }
        return newnode;
    }

    iterator getNodeByKey(const rank_data_key_t& key){
        auto it = m_cache.find(key);
        if(it != m_cache.end()){
            if(it->second){
                return iterator(it->second);
            }
            return iterator(it->second);
        }
        return iterator(nullptr);
    }

    /* Finds an element by its rank. The rank argument needs to be 1-based. */
    iterator getNodeByRank(rank_t rank) {
        node_t *x;
        rank_t traversed = 0;
        int i;

        x = m_header;
        for (i = m_level-1; i >= 0; i--) {
            while (x->_level[i].forward && (traversed + x->_level[i].span) <= rank)
            {
                traversed += x->_level[i].span;
                x = x->_level[i].forward;
            }
            if (traversed == rank) {
                return iterator(x);
            }
        }
        return iterator(nullptr);
    }

    //using rank_t = int64_t;
    rank_t getRankByKey(rank_data_key_t key){
        auto it = m_cache.find(key);
        if(it == m_cache.end())
            return -1;
        rank_data_type rank_data = it->second->_rank_data;
        
        node_t *x;
        rank_t rank = 0;
        int i;

        x = m_header;
        for (i = m_level-1; i >= 0; i--) {
            while (x->_level[i].forward && m_comp_less(*x->_level[i].forward->_rank_data , *rank_data )) {
                rank += x->_level[i].span;
                x = x->_level[i].forward;
            }
            if(x->_level[i].forward == it->second){ //x->_level[i].forward->_rank_data->key() == key){
                rank += x->_level[i].span;
                //x = x->_level[i].forward;
                return rank;
            }
        }
        return 0;
    }
    
private:
    //skiplist_t mskiplist;
    std::unordered_map<rank_data_key_t, node_t*> m_cache;
    comp_less_t  m_comp_less;
#ifdef SKIP_LIST_MEM_MONITER
    uint64_t m_memory;
#endif
    node_t *m_header, *m_tail; //header和tail分别指向头结点和尾结点，
    rank_t m_length; //结点数量，
    int m_level; //level为表中结点的最高等级。
};
 
void test(int count = 100000);
}

#endif