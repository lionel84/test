/*
 * @Auth: lionelzhang
 * @Date: 2020-10-27 11:16:01
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-29 21:27:15
 * @Description: 
 */
#include "skiplist_tree.h"
#include "base.h"
#include "test_comp.h"
// 定义数据类型
using rank_data_key_t = uint64_t;
struct RANK_DATA
{
    RANK_DATA(rank_data_key_t uid, int32_t score, int32_t ts): _uid(uid), _score(score), _ts(ts), _name("name"){
        //end[1023] = 0;
    }
    const bool operator < (const RANK_DATA& other) const{
        if(_score < other._score)return true;
        if(_score == other._score){
            if(_ts > other._ts)return true;
            if(_ts == other._ts)
                return _uid < other._uid;
            //return _ts > other._ts;
        }
        return false;
    }

    const bool operator > (const RANK_DATA& other) const{
        if(_score > other._score)return true;
        if(_score == other._score){
            if(_ts < other._ts)return true;
            if(_ts == other._ts)
                return _uid < other._uid;
        }
        return false;
    }
    
    bool operator == (const RANK_DATA& other) const{
        return _uid == other._uid;
    }
    
    ~RANK_DATA(){
    }
/*
    inline rank_data_key_t key() const{
        return _uid;
    }
    */
//private:
    rank_data_key_t _uid;
    int32_t _score;
    int32_t _ts;
    string _name;
    int32_t _level;
   // char end[1024];
};

using rank_data_value_t = RANK_DATA;

namespace nm_skiplist {
    void test(int count ){
        cout<<"begin skiplist"<<endl;
        srand(time(NULL));
        printnow();
        cout<<"排行榜测试数量："<<count<<endl;
        //CSkipList<rank_data_key_t, rank_data_value_t, comp_t> list;
        zskiplist<rank_data_key_t, rank_data_value_t, std::greater<rank_data_value_t> > list;
        for(int i = 0; i< count; i++){
            list.zslInsert(i, std::make_shared<rank_data_value_t>(i, i+1, i));
        }
        printnow("插入");
        cout<<"memory: "<<list.GetMem()<<endl;
        cout<<"排行榜节点数: "<<list.size()<<endl;
        for(int i = 0; i< count; i++){
            auto it = list.getNodeByRank(i);
        }
        printnow("根据排名查询节点");
        for(int i = 0; i< count; i++){
            auto it = list.getRankByKey(i);
        }
        printnow("根据uid查询排名");
        cout<<"uid[3] ,排名: "<<list.getRankByKey(3)<<endl;;
        cout<<"uid[1] ,排名: "<<list.getRankByKey(1)<<endl;;
        
        for(uint64_t i = 1; i<= count+100; i++){
            auto it = list.getNodeByKey(i); 
            if(it != list.end())
            {
                it->_score += 1;
                list.zslUpdateScore(it->_uid, *it);
            }
        }
        printnow("根据uid修改积分");
        cout<<"uid: "<<list.getNodeByRank(3)->_uid<<" 积分: "<<list.getNodeByRank(3)->_score<<endl;;
        uint64_t loop =  0;
        for(auto it = list.begin(); it != list.end(); it++){
            loop ++;
        }
        cout<<"顺序迭代次数："<<loop<<" size: "<<list.size()<<endl;
        printnow("顺序迭代");
        auto first = list.begin();
        if(first != list.end()){
            printf("第一名：uid: %llu, 分数: %llu\n", first->_uid, first->_score);
        }
        auto last = list.back();
        if(last != list.end()){
            printf("最后一名 ：uid: %llu, 分数: %llu\n", last->_uid, last->_score);
        }
        for(int i = 0; i< count; i++){
            auto it = list.zslDelete(i);
            if(it == false){
                cout<<i<<endl;
                auto node = list.getNodeByKey(i);
                if(node != list.end()){
                    cout<<node->_score<<endl;
                }
            }
        }
        printnow("根据uid删除");
        cout<<"memory: "<<list.GetMem()<<endl;
        cout<<"uid[3] ,排名: "<<list.getRankByKey(3)<<endl;
        cout<<"排行榜节点数:: "<<list.size()<<endl;
        //cout<<"uid: "<<list.getNodeByRank(0)->key()<<" 积分: "<<list.getNodeByRank(3)->_score<<endl;;
        
    }

}