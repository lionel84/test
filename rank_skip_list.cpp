/*
 * @Auth: lionelzhang
 * @Date: 2020-10-27 11:16:01
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-11-06 15:12:24
 * @Description: 
 */
#include "rank_skip_list.h"

#include <unistd.h>

#include "base.h"
int global_init_count = 0;
int global_uninit_count = 0;
int fail_count =0;

// 定义数据类型
using rank_data_key_t = uint64_t;

struct RANK_DATA
{
    RANK_DATA(rank_data_key_t uid, int32_t score, int32_t ts): _uid(uid), _score(score), _ts(ts), _name("name"){
        _level = 1;
        global_init_count ++;
        //end[1023] = 0;
    }
    const bool operator < (const RANK_DATA& other) const{
        if(_score < other._score)return true;
        if(_score == other._score){
            return _ts > other._ts;
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
            return _ts < other._ts;
            if(_ts < other._ts)return true;
            if(_ts == other._ts)
                return _uid < other._uid;
        }
        return false;
    }
    ~RANK_DATA(){
        if(_level != 1){
            fail_count ++;
        }
        global_uninit_count ++;
        if(global_uninit_count == global_init_count){
            printf("success\n");
        }
    }
    rank_data_key_t _uid;
    long _score;
    long _ts;
    string _name;
    int32_t _level;
   // char end[1024];
};

using rank_data_value_t = RANK_DATA;

namespace nm_rank_skip_list {
    extern void _test(int nMaxCount );
    void test(int nMaxCount){
        _test(nMaxCount);
        // 打印次数，检测shared_ptr是否存在内存泄漏
        printf("构造次数：%d, 析构次数: %d, 失败次数: %d\n", global_init_count, global_uninit_count, fail_count);
    }
    void _test(int nMaxCount ){
#if 0
        printf("begin test RankSkipList>>>\n");
        srand(time(NULL));
        //vector<std::shared_ptr<rank_data_value_t> > test_data;
        vector<rank_data_value_t* > test_data;
        for(int i = 0; i< nMaxCount; i++){
            //test_data.push_back(std::make_shared<rank_data_value_t>(i,random(), random())); //, random()));
            test_data.push_back(new rank_data_value_t(i,random(), random())); //, random()));
        }
        printnow();
        RankSkipList<rank_data_key_t, rank_data_value_t, std::greater<rank_data_value_t> > list(nMaxCount);
        printnow("初始化");
        printf("排行榜测试数量： %d\n", nMaxCount);
        for(const auto& it : test_data){
            list.zslInsert(std::make_pair(it->_uid, it));
        //for(int i = 0; i< nMaxCount; i++){
        //    list.zslInsert(i, std::make_shared<rank_data_value_t>(i, random()%100000000, random())); //std::make_shared<rank_data_value_t>(i, i+1, i));
        }
       // for(int i = 0; i< nMaxCount; i++){
       //     list.zslInsert(i, test_data[i]); //std::make_shared<rank_data_value_t>(i, i+1, i));
            //list.zslInsert(i, new rank_data_value_t(i, i+1, i));
        //}
        printnow("插入", nMaxCount);
        printf("构造次数：%d, 析构次数: %d, 失败次数: %d\n", global_init_count, global_uninit_count, fail_count);
        //list.printlist();
        printf("memory: %d\n", list.mem());
        printf("排行榜节点数: %d\n", list.size());
        printnow();
        for(int i = 0; i< nMaxCount; i++){
            auto it = list.getNodeByRank(i);
        }
        printnow("根据排名查询节点", nMaxCount);
        for(int i = 0; i< nMaxCount; i++){
            auto it = list.getRankByKey(i);
        }
        printnow("根据uid查询排名", nMaxCount);
        printf("uid[3] ,排名: %d\n",list.getRankByKey(3));
        printf("uid[1] ,排名: %d\n",list.getRankByKey(1));
        {
            auto first = list.begin();
            if(first != list.end()){
                printf("第一名：uid: %llu, 分数: %llu\n", first->second->_uid, first->second->_score);
            }
            auto first_v1 = list.getNodeByRank(1);
            if(first_v1 != list.end()){
                printf("第一名：uid: %llu, 分数: %llu\n", first_v1->second->_uid, first_v1->second->_score);
            }
        }
        {
            auto last = list.back();
            if(last != list.end()){
                printf("最后一名 ：uid: %llu, 分数: %llu\n", last->second->_uid, last->second->_score);
            }
        }
        /*
        {
            uint64_t loop_count =  0;
            for(auto it = list.begin(); it != list.end(); it++){
                if(it != list.end()){
                    printf("uid: %llu, 分数: %llu\n", it->_uid, it->_score);
                }
                loop_count ++;
            }
        }
        */
        printnow();
        for(uint64_t i = 0; i<nMaxCount; i++){
            auto it = list.getNodeByKey(i); 
            if(it != list.end())
            {
                list.zslDelete(i);
                test_data[i]->_score = random();
                list.zslInsert(std::make_pair(i, test_data[i]));
                
                //it->_score = random();
                //list.zslUpdateScore(it->_uid, std::make_shared<rank_data_value_t>(it->_uid, random()%100000000, random()));
            }
        }
        printnow("根据uid修改积分", nMaxCount);
        
        printf("构造次数：%d, 析构次数: %d, 失败次数: %d\n", global_init_count, global_uninit_count, fail_count);
        {
            auto it = list.getNodeByRank(3);
            if(it != list.end()){
                printf("uid: %llu, 积分: %d\n", it->second->_uid, it->second->_score);
            }
        }
        /*
        printnow();
        {
            uint64_t loop_count =  0;
            for(auto it = list.begin(); it != list.end(); it++){
                if(it != list.end()){
                    printf("uid: %llu, 分数: %llu\n", it->_uid, it->_score);
                }
                loop_count ++;
            }
            printf("顺序迭代次数：%llu, 节点数: %d\n", loop_count, list.size());
        }
       
        printnow("顺序迭代", nMaxCount);
        {
            auto first = list.begin();
            if(first != list.end()){
                printf("第一名：uid: %llu, 分数: %llu\n", first->_uid, first->_score);
            }
        }
        {
            auto last = list.back();
            if(last != list.end()){
                printf("最后一名 ：uid: %llu, 分数: %llu\n", last->_uid, last->_score);
            }
        }
        */
        printnow();
        for(int i = 0; i< nMaxCount; i++){
            auto it = list.zslDelete(i);
            if(it == false){
                cout<<i<<endl;
                auto node = list.getNodeByKey(i);
                if(node != list.end()){
                    cout<<node->second->_score<<endl;
                }
            }
        }
        printnow("根据uid删除", nMaxCount);
        printf("构造次数：%d, 析构次数: %d, 失败次数: %d\n", global_init_count, global_uninit_count, fail_count);
        test_data.clear();
       // while(global_uninit_count != global_init_count){
       //     sleep(1);
            
       // }
        printnow("等待析构完成");
        list.printlist();
        printf("构造次数：%d, 析构次数: %d, 失败次数: %d\n", global_init_count, global_uninit_count, fail_count);
        printf("memory: %d\n", list.mem());
        printf("排行榜节点数: %d\n", list.size());
        printf("uid[3] ,排名: %d\n",list.getRankByKey(3));
        printf("uid[1] ,排名: %d\n",list.getRankByKey(1));        
        #endif
        
    }

}