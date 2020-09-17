/*
 * @Auth: Do not edit
 * @Date: 2020-08-04 15:31:00
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-04 18:49:30
 * @Description: 
 */
#ifndef _TEST_FIND_IF_H_
#define _TEST_FIND_IF_H_
#include "base.h"
#include <iostream>
using namespace std;

void test_find_if()
{
    vector< int> db_{10, 20, 30, 50};

    auto func_ = [](vector<int> & v_, int32_t value_){ 
        auto it = std::find(v_.begin(), v_.end(), value_);
        //cout<<"func_ ";
        if(v_.end() != it)
        {
            return true;
            cout<<"find: "<<value_<<endl;
        }else
        {
            return false;
            cout<<"not find: "<<value_<<endl;
        }
    };
    const int count = 10000;
    bool find = false;
    find = func_(db_, 20);
    printnow();
    for(int i = 0; i< count; i++){
        auto it = std::find(db_.begin(), db_.end(), 30);
        if(it != db_.end()){
            find = true;
        }
    }
        
    cout<<find<<endl;
    printnow();
    
    for(int i = 0; i< count; i++){
        for(auto v_: db_){
            if(v_ == 30){
                find = true;
                break;
            }
        }
    }
    cout<<find<<endl;
    printnow();
        find = func_(db_, 30);

    auto func_1 = [](vector<int> & v_, int32_t value_){ 
        auto it = std::find_if(v_.begin(), v_.end(), [value_](const int& loop){return loop/10==(value_/10);});
        cout<<"func_1 ";
        if(v_.end() != it)
        {
            cout<<"find suc: "<<value_<<endl;
        }else
        {
            cout<<"find failed: "<<value_<<endl;
        }
    };
    func_1(db_, 22);
    func_1(db_, 33);
    func_1(db_, 44);
}

#endif //_TEST_FIND_IF_H_