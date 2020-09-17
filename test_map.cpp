/*
 * @Auth: lionelzhang
 * @Date: 2020-08-18 19:21:20
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-18 19:25:32
 * @Description: 
 */
#include "test_map.h"
#include <map>
#include <iostream>
using namespace std;
namespace NM_TEST_MAP{
    void test(){
        map<int, TESTS> map_;
        map_.insert(std::make_pair(1, TESTS(1)));
        auto it = map_.find(1);
        it->second.value = 2;
        if(it != map_.end()){
            cout<<it->second.value<<endl;
        }
        auto it1 = map_.find(1);
       // it->second.value = 2;
        if(it1 != map_.end()){
            cout<<it1->second.value<<endl;
        }
    }
}