/*
 * @Auth: Do not edit
 * @Date: 2020-08-10 14:32:34
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-25 11:07:00
 * @Description: 
 */
#include "test_tree.h"
#include "base.h"
#include <vector>
#include <list>
#include <memory>
using namespace std;
#include "print_tree.h"
namespace nm_test_tree
{
    // 满二叉树 > 完全二叉树
    void test(){
        vector<int> v{11,9,7,5,3,1,2,4,6,8,10};
        /*
        binary_sort_tree st;
        for(int it = 1; it< 20;it++){
            st.insert(it);
        }
        */
        binary_avl_tree st_avl;
        for(int it = 1; it< 20;it++){
            st_avl.insert(it);
        }
        using node_ptr = Node*;
        nm_print_tree::tree_print<Node> tprint(
            [](node_ptr n){return n->left_.get();},
            [](node_ptr n){return n->right_.get();},
            [](node_ptr n){return n->value_;});
            
        tprint.print(st_avl.head.get());
        
        st_avl.erase(12);
        tprint.print(st_avl.head.get());
    }
    int get_height(shared_ptr<Node> n){
        if(!n)return 0;
        return 1+max(get_height(n->left_), get_height(n->right_));
    }
}