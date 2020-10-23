/*
 * @Auth: lionelzhang
 * @Date: 2020-08-18 20:38:33
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-22 15:14:05
 * @Description: 
 */

#include "print_tree.h"
//#include "rank_tree.h"
#include "base.h"
#include "test_comp.h"
#include "rank_tree_v1.h"
namespace nm_test_rbtree{

//using namespace nm_rank_tree;
using namespace nm_print_tree;
using namespace nm_rank_tree_v1;

// 定义数据类型
using rank_data_key_t = uint64_t;
struct RANK_DATA
{
public:
    RANK_DATA(){}
    RANK_DATA(rank_data_key_t uid, int32_t score, int32_t ts): _uid(uid), _score(score), _ts(ts){}

    rank_data_key_t key() const{
        return _uid;
    }
//private:
    rank_data_key_t _uid;
    int32_t _score;
    int32_t _ts;
    
};
using rank_data_value_t = RANK_DATA;
using comp_t = KEY_COMP<rank_data_value_t>; 

// 定义排序树类型

using tree_t = rank_tree<rank_data_key_t, rank_data_value_t, comp_t > ;
// 定义比较函数
static bool comp(const rank_data_value_t& a, const rank_data_value_t& b) {
    if(a._score < b._score)return true;
    if(a._score == b._score){
        return a._ts > b._ts;
    }
    return false;
}

void test()
{
    srand(time(NULL));
    using tree_node_t = tree_t::node;
    
    tree_print<tree_node_t > tprint(
        [](tree_node_t* n){return n->children[0];},
        [](tree_node_t* n){return n->children[1];}, 
        [](tree_node_t* n){return n->value._score;},
        [](tree_node_t* n){return n->color == 0;});
        
    printnow();
    comp_t mycomp(comp, true/*true|false default: true(降序)*/);
    tree_t rank_tree(mycomp);
    const int test_size = 100000;
    cout<<"排行榜测试数量："<<test_size<<endl;
    // insert
    for(int i = 1; i<= test_size; i++){
        auto it = rank_tree.insert(rank_data_value_t(i, /*rand()%100*/i, time(NULL))); 
        //auto it = rank_tree.insert(std::make_pair(i, rank_data_value_t(i, /*rand()%100*/i, time(NULL)))); 
    }
    printnow("插入");
    printf("rank_tree size: %d\n", rank_tree.size());
   // tprint.print(rank_tree.m_root);
    // chaxun
    
    for(int i = 1; i<= test_size+100; i++){
        auto it = rank_tree.find_by_rank(i); 
    }
    printnow("根据排名查询");
    // chaxun
    
    for(int i = 1; i<= test_size+100; i++){
        auto it = rank_tree.find_by_key(i); 
        //cout<<"rank: "<<rank_tree.rank(it)<<" id: "<<it->second._uid<<" value: "<<it->second._score<<" ts: "<<it->second._ts<<endl;
    }
    printnow("根据uid查询数据");

    for(uint64_t i = 1; i<= test_size+100; i++){
        auto it = rank_tree.rank_by_key(i); 
        //cout<<"rank: "<<rank_tree.rank(it)<<" id: "<<it->second._uid<<" value: "<<it->second._score<<" ts: "<<it->second._ts<<endl;
    }
    printnow("根据uid查询排名");
    // delete
    for(int i = 1; i<= test_size+100; i++){
        auto it = rank_tree.find_by_key(i); 
        if(it != rank_tree.end())
            rank_tree.erase(it);
    }
    printnow("删除");
    printf("rank_tree size: %d\n", rank_tree.size());
/*

    tprint.print(rank_tree.m_root);
*/
    

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