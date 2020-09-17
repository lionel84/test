/*
 * @Auth: lionelzhang
 * @Date: 2020-08-18 20:38:33
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-25 11:17:53
 * @Description: 
 */

#include "print_tree.h"
#include "rank_tree.h"
#include "base.h"
namespace nm_test_rbtree{
    
typedef bool (*COMP_FUNC_TYPE)(const int&, const int&);

static bool comp(const int& a, const int& b) {
    return a<b;
}

using namespace nm_rank_tree;
using namespace nm_print_tree;

void test()
{
    rank_tree<int, int, COMP_FUNC_TYPE> test_tree(comp);
    srand(time(NULL));
    printnow();
    for(int i = 0; i< 50; i++){
        test_tree.insert(std::pair<int, int>(i, rand()%100));
    }
    //auto it = test_tree.find_by_rank(10);
    //printf("%d %d\n", 1234 , test_tree.find_by_rank(50000)->first);
    using tree_node_ptr = rank_tree<int, int, COMP_FUNC_TYPE>::node*;
    tree_print<rank_tree<int, int, COMP_FUNC_TYPE>::node > tprint(
        [](tree_node_ptr n){return n->children[0];},
        [](tree_node_ptr n){return n->children[1];}, 
        [](tree_node_ptr n){return n->value.first;},
        [](tree_node_ptr n){return n->color == 0;});
    //tprint.print(test_tree.m_root);
    //printf("%d\n", it->first);
    //test_tree.erase(test_tree.find_by_rank(9));
    //test_tree.erase(test_tree.find_by_rank(7));
    //auto it = test_tree.find_by_rank(15);
    /*
    for(int i = 0; i< test_tree.size();i++)
    printf("%d %d\n", i , test_tree.find_by_rank(i)->first);
    */
   #define del_ 5
   printnow();
   auto it = test_tree.begin();
   for(auto it = test_tree.begin(); it != test_tree.end(); it ++)
   {
       printf("%d %d\n", it->first , it->second);
   }
   auto it_e = test_tree.end();
   /*
    while(test_tree.size() >del_){
        if(test_tree.find_by_rank(0) != test_tree.end()){
            test_tree.erase(test_tree.find_by_rank(del_));
            //tprint.print(test_tree.m_root);
        }else{
            for(int i = 0; i< test_tree.size();i++)
    printf("%d %d\n", i , test_tree.find_by_rank(i)->first);
        }
    }
    */
    printnow();
    
    //tprint.print(test_tree.m_root);
}
}