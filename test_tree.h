/*
 * @Auth: Do not edit
 * @Date: 2020-08-10 14:32:13
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-21 20:52:58
 * @Description: 
 */
#ifndef _TEST_TREE_H_
#define _TEST_TREE_H_
#include <vector>
#include <list>
#include <map>
#include <memory>
#include<cstdlib>
#include<cstdio>
#include "string.h"
#include "stdlib.h"
#include <cmath>
using namespace std;
namespace nm_test_tree
{
    struct Node{
        shared_ptr<Node> left_;
        shared_ptr<Node> right_;
        public:
        int value_;
        Node(int v){
            value_ = v;
        }
    };
    using node_ptr = shared_ptr<Node> ;


    int get_height(node_ptr n);

    class binary_sort_tree{
        // xianxu root left right
        // zhongxu left root right
        // houxu left right root
        public:
        binary_sort_tree(){
            head = nullptr;
        }
        bool insert(int key){
            node_ptr cur = make_shared<Node>(key);
            if(!head){
                head = cur;
                return true;
            }
            node_ptr n = find(key);
            if(n){
                // update data
                return true;
            }
            insert(head, cur);

            return false;
        }
        bool insert(node_ptr n, node_ptr cur){
            if(!n || !cur)return false;
            if(cur->value_ <= n->value_){
                if(n->left_ == nullptr){
                    return _insert(n, cur, true);
                }else{
                    return insert(n->left_, cur);
                }
            }else{
                if(n->right_ == nullptr){
                    return _insert(n, cur, false);
                }else{
                    return insert(n->right_, cur);
                }
            }
            return false;
        }
        bool _insert(node_ptr n, node_ptr cur, bool left){
            if(!n || !cur)
                return false;
            if(left){
                cur->left_ = n->left_;
                n->left_ = cur;
            }else{
                cur->right_ = n->right_;
                n->right_ = cur;
            }
            return true;
        }
        bool erase(int key){
            if(!head){
                return false;
            }
            
            if(head->value_ == key){
                head = _erase(head);
                
                return true;
            }
            return erase(head, key);
        }
        bool erase(node_ptr n, int key){
            if(!n)return false;
            if(key< n->value_ && n->left_ ){
                if(n->left_->value_ == key){
                    n->left_ = _erase(n->left_);
                    return true;
                }else{
                    return erase(n->left_, key);
                }
            }
            else if(n->right_ && key > n->value_){
                if(n->right_->value_ == key){
                    n->right_ = _erase(n->right_);
                    return true;
                }else {
                    return erase(n->right_, key);
                }
            }
            return false;
        }
        // 右子节点上升，左子树挂到右子树的左叶子节点
        node_ptr _erase(node_ptr n){
            if(!n)
                return nullptr;
            if(n->right_){
                node_ptr cur = n->right_;
                while(cur){
                    if(!cur->left_)break;
                    cur = cur->left_;
                }
                cur->left_ = n->left_;
                return n->right_;
            }else{
                return n->left_;
            }
            return nullptr;
        }
        node_ptr find(int key){
            return find(head, key);
        }
        node_ptr find(node_ptr n, int key){
            if(!n)return nullptr;
            if(key == n->value_)
                return n;
            if(key > n->value_){
                return find(n->right_, key);
            }else{
                return find(n->left_, key);
            }
        }
        int calc_dep(node_ptr n){
            if(!n)return 0;
            if(n->left_ || n->right_){
                return 1+max(calc_dep(n->left_), calc_dep(n->right_));
            }
            return 1;
        }
        void xianxu_print(node_ptr n){
            if(!n)return;
            printf("%d\n", n->value_);
            xianxu_print(n->left_);
            xianxu_print(n->right_);
        };    
        void zhongxu_print(node_ptr n){
            if(!n)return;
            zhongxu_print(n->left_);
            printf("%d\n", n->value_);
            zhongxu_print(n->right_);
        };   
        void houxu_print(node_ptr n){
            if(!n)return;
            houxu_print(n->left_);
            houxu_print(n->right_);
            printf("%d\n", n->value_);
        };
        node_ptr head;
    };

    class binary_avl_tree : public binary_sort_tree{
        public:
        node_ptr L(node_ptr n){
            if(!n || !n->left_)return n;
            node_ptr t = n->left_;
            n->left_ = t->right_;
            t->right_ = n;
            return t;
        }
        node_ptr R(node_ptr n){
            if(!n || !n->right_)return n;
            node_ptr t = n->right_;
            n->right_ = t->left_;
            t->left_ = n;
            return t;
        }
        node_ptr LR(node_ptr n){
            if(!n)return n;
            n->left_ = R(n->left_);
            return L(n);
        }
        node_ptr RL(node_ptr n){
            if(!n)return n;
            n->right_ = L(n->right_);
            return R(n);
        }
        bool erase(int key){
            if(!head){
                return false;
            }
            node_ptr n = find(key);
            if(!n){
                // update data
                return false;
            }
            head =  erase(head, key);
            return true;
        }
        node_ptr reput(node_ptr n){
            if(!n)return nullptr;
            n->left_ = reput(n->left_);
            n->right_ = reput(n->right_);
            while(get_height(n->right_)- get_height(n->left_) >= 2){
                if(get_height(n->right_->right_) > get_height(n->right_->left_))
                    n = R(n);
                else
                {
                    n = RL(n);
                }
            }
            while(get_height(n->left_)- get_height(n->right_) >= 2){
                if(get_height(n->left_->left_) > get_height(n->left_->right_))
                    n = L(n);
                else
                {
                    n = LR(n);
                }
            }
            return n;
        }
        node_ptr erase(node_ptr n, int key){
            if(n->value_ == key){
                if(n->right_ && n->left_){
                    n->right_ = insert(n->right_, n->left_);
                }else if(n->right_){
                    n->right_ = n->right_;
                }else{
                    n->right_ = n->left_;
                }
                n->right_ = reput(n->right_);
                
                return n->right_;
            }else if(key < n->value_){
                n->left_ = erase(n->left_, key);
            }else{
                n->right_ = erase(n->right_, key);
            }
            while(get_height(n->left_)- get_height(n->right_) == 2){
                if(get_height(n->left_->left_) > get_height(n->left_->right_))
                    n = L(n);
                else
                {
                    n = LR(n);
                }
            }
            while(get_height(n->right_)- get_height(n->left_) == 2){
                if(get_height(n->right_->right_) > get_height(n->right_->left_))
                    n = R(n);
                else
                {
                    n = RL(n);
                }
            }
            return n;
            
        }
        
        bool insert(int key){
            node_ptr cur = make_shared<Node>(key);
            if(!head){
                head = cur;
                return true;
            }
            node_ptr n = find(key);
            if(n){
                // update data
                return true;
            }
            head = insert(head, cur);

            return false;
        }
        node_ptr insert(node_ptr n, node_ptr cur){
            if(!n)return cur;
            if(cur->value_ <= n->value_){
                n->left_ = insert(n->left_, cur);
                while(get_height(n->left_)- get_height(n->right_) == 2){
                    if(cur->value_ < n->left_->value_){
                        n = L(n);
                    }else{
                        n = LR(n);
                    }
                }
            }else{
                n->right_ = insert(n->right_, cur);
                while(get_height(n->right_)- get_height(n->left_) == 2){
                    if(cur->value_ < n->right_->value_){
                        n = RL(n);
                    }else{
                        n = R(n);
                    }
                }
            }
            return n;
        }
    };    

   // template <typename key_t, typename value_t, typename comp_t = std::less<key_t> >
    class heap_tree{ //min
        public:
            //typedef std::pair<key_t, value_t>   value_type;
            heap_tree(){}
            bool push(int value){
                shared_ptr<Node> n = make_shared<Node>(value);
                if(!n)
                    return false;
                root.push_back(n);
                up();
                return true;
            }
            node_ptr pop(){
                if(root.empty())return nullptr;
                shared_ptr<Node> n = root[0];
                root[0] = root[root.size()-1];
                root.pop_back();
                down();
                return n;
            }
            bool empty(){return root.empty();}
            void print(){
                if(root.empty())return;
                for(auto n : root){
                    printf("%d ", n->value_);
                }
                printf("\n");
            }
            void test(const std::vector<int>& v){
                for(auto value: v){
                    push(value);
                }
                print();
                while(!empty()){
                    shared_ptr<Node> n = pop();
                    if(n){
                        printf("%d\n", n->value_);
                    }
                    
                }
                print();
            }
        private:
            void up(){
                int cur = root.size() -1;
                while(cur >= 0){
                    int parent = (cur-1)/2;
                    if(parent < 0)break;
                    if(root[parent]->value_ > root[cur]->value_){
                        swap(root[parent], root[cur]);
                        cur = parent;
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
            void down(){
                int cur = 0;
                while(cur < root.size())
                {
                    int left = cur*2+1;
                    int right = (cur+1)*2;
                    int min_child_idx = cur;
                    if(right < root.size()){
                        if(root[left]->value_ < root[right]->value_){
                            min_child_idx = left;
                        }else{
                            min_child_idx = right;
                        }
                    }else if(left < root.size()){
                        min_child_idx = left;
                    }
                    if(min_child_idx != cur){
                        if(root[cur]->value_ > root[min_child_idx]->value_){
                            swap(root[cur], root[min_child_idx]);
                            cur = min_child_idx;
                            continue;
                        }else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        
        vector<node_ptr > root;
    };

    void test();
}

#endif //_TEST_TREE_H_