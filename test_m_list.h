/*
 * @Auth: lionelzhang
 * @Date: 2020-12-08 11:17:14
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-12-10 17:24:52
 * @Description: 
 */
#ifndef __TEST_M_LIST_H__
#define __TEST_M_LIST_H__
#include "base.h"
#include <list>
#include <memory>
namespace nm_m_list
{
    enum MLISTFLAG{
        MLISTFLAG_EMPTY = 0,
        MLISTFLAG_WRITING = 1,
        MLISTFLAG_READING = 2,
        MLISTFLAG_DONE = 3,
    };

    template<typename T>
    struct mListNode{
        using node_t = struct mListNode<T>;
        using node_ptr_t = node_t*;
        public:
        mListNode(shared_ptr<T> value_ptr):
        _value_ptr(value_ptr), _flag(0), _next(nullptr), _isBad(0)
        {
        }
        shared_ptr<T> _value_ptr;
        MLISTFLAG _flag;
        node_ptr_t _next;
        bool _isBad;
    };
    template<typename T>
    class mList{
        using node_t = struct mListNode<T>;
        using node_ptr_t = node_t*;
        public:
        mList():m_head(nullptr), m_size(0){}
        ~mList(){}
        /*
        template<typename... _Args>
        void
        emplace(_Args&&... __args)
        { //c.emplace_back(std::forward<_Args>(__args)...); 
            node_ptr_t node = make_shared<node_t>();
        }
        */
        bool empty() const{
            return m_size == 0;
            /*
            bool isEmpty = true;
            node_ptr_t node = m_head;
            while(node){
                if(!node->_isBad){
                    isEmpty = false;
                    break;
                }
                node = node->next;
            }
            return isEmpty;
            */
        }

        void pop(){
            m_size --;
        }


        size_t size() const
        {

        }

        T& top(){

        }

        void swap(mList<T>& other){

        }
        
        private:
        node_ptr_t m_head;
        size_t m_size;

    };

    void test();
}

#endif