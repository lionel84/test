/*
 * @Auth: lionelzhang
 * @Date: 2020-08-18 20:38:33
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-20 15:08:31
 * @Description: 
 */

#include "print_tree.h"
#include "rank_tree.h"
#include "base.h"
#include "test_comp.h"
namespace nm_test_rbtree{

using namespace nm_rank_tree;
using namespace nm_print_tree;

// 定义数据类型
struct KEY_TYPE{
public:
    KEY_TYPE(){}
    KEY_TYPE(int32_t score, int32_t ts):_value(score), _ts(ts){}
    int32_t _value;
    int32_t _ts;
};

struct VALUE_TYPE{
public:
    VALUE_TYPE(){}
    VALUE_TYPE(uint64_t id):_id(id){} 
    uint64_t _id;
};

// 定义比较函数
static bool comp(const KEY_TYPE& a, const KEY_TYPE& b) {
    if(a._value < b._value)return true;
    if(a._value == b._value){
        return a._ts > b._ts;
    }
    return false;
}
using KEY_COMP_T = nm_comp::KEY_COMP<KEY_TYPE>;
KEY_COMP_T descending_order(comp, true);
KEY_COMP_T ascending_order(comp, false);

// 定义排序树类型
using tree_t = rank_tree<KEY_TYPE, VALUE_TYPE, KEY_COMP_T>;
using map_t = std::unordered_map<uint64_t, tree_t::iterator>;

void print_by_uid(tree_t& tree, map_t& uids, uint64_t uid){
    auto it1 = uids.find(uid);
    if(it1 != uids.end()){
        auto it = it1->second;
        uint64_t rank = tree.rank(it);
        cout<<"rank: "<<rank<<" id: "<<it->second._id<<" value: "<<it->first._value<<" ts: "<<it->first._ts<<endl;
    }
    else{
        cout<<"not found by id: "<<uid<<endl;
    }
}
void print_by_rank(tree_t& tree, uint64_t rank){
    auto it = tree.find_by_rank(rank);
    if(it != tree.end()){
        cout<<"rank: "<<rank<<" id: "<<it->second._id<<" value: "<<it->first._value<<" ts: "<<it->first._ts<<endl;
    }
    else{
        cout<<"not found by rank: "<<rank<<endl;
    }
}
void test()
{
    srand(time(NULL));
    printnow();
    
    map_t uids;
    tree_t rank_tree(descending_order);
    
    for(int i = 1; i<= 20; i++){
        auto it = rank_tree.insert(std::pair<KEY_TYPE, VALUE_TYPE>(KEY_TYPE(i, time(NULL)), VALUE_TYPE(i)));
        uids[i] = it;
    }

    using tree_node_t = tree_t::node;
    tree_print<tree_node_t > tprint(
        [](tree_node_t* n){return n->children[0];},
        [](tree_node_t* n){return n->children[1];}, 
        [](tree_node_t* n){return n->value.first._value;},
        [](tree_node_t* n){return n->color == 0;});
    tprint.print(rank_tree.m_root);

    
    for(int i = 0; i< 10; i++)
        print_by_rank(rank_tree, i);
    for(int i = 0; i< 10; i++)
        print_by_uid(rank_tree, uids, i);
    /*
    auto it = rank_tree.find_by_rank(50);
    if(it != rank_tree.end())
        cout<<"value: "<<it->first._value<<" ts: "<<it->first._ts<<endl;

    

    auto it1 = uids.find(1);
    if(it1 != uids.end()){
        cout<<"id: "<<it1->first._id<<" value: "<<it1->second->first._value<<" ts: "<<it1->second->first._ts<<endl;
        int rank = rank_tree.rank(it1->second);
        cout<<"rank: "<<rank<<endl;
    }
    */
    

}
}