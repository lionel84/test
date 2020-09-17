/*
 * @Auth: lionelzhang
 * @Date: 2020-08-18 15:05:19
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-18 16:39:37
 * @Description: 
 */
#include "test_template.h"
#include <vector>
#include "base.h"
#include <iostream>
using namespace std;
namespace nm_test_template{
    template<class T>
    void check(const T& lists){
        for(const auto & it: lists){
        switch (it.type)
        {
        case 1:
            cout<<1<<endl;
            break;
        
        default:
            break;
        }
    }
    }

void test(){
    std::vector<nm_test_template::TESTS> v;
    nm_test_template::check(v);
}

}