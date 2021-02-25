/*
 * @Author: lionel
 * @Date: 2020-07-22 17:33:50
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-02-01 17:13:10
 * @Description: main
 */ 

//#include "test_find_if.h"
//#include "redis_test.h"
//#include "coroutine_test.h"
//#include "cache.h"
#define P(a,b)=strcpy(a,b)
#include "test_using.h"
#include "test_pair.h"
#include "base.h"
#include "test_tree.h"
#include "test_template.h"
#include "test_map.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
 #include <unistd.h>
using namespace std;
enum EN_TEST
{
    EN_1 = 1,
    EN_2 = 2
};
void test(EN_TEST value){
    cout<<value<<endl;
}
#include "socket_test.h"
#include "test_json_pack.h"
#include "test_popen.h"
#include "test_aes_cbc.h"

#include "test_state_mechine.h"
#include "test_test.h"
#include "redis_test.h"

#include "rank_rbtree.h"
#include "test_auto_ptr.h"
#include "rank_skip_list.h"
#include "rank_test.h"
map< int, int> map_;
#include "test_rand.h"
#include "test_function.h"
class TEST_CLASS{
public:
    TEST_CLASS(){
        cout<<"gouzao"<<endl;
    }
    ~TEST_CLASS(){
        cout<<"xigou"<<endl;
    }
public:
    int val(){
        return _val;
    }
    int _val;
};
#include "test_m_list.h"
template<typename RT, typename P0, typename IP0>
int foo(RT (*func)(P0), IP0& param){
    func(param);
}
/*
template<typename RT, typename P0, typename IP0>
int foo(RT (*func)(P0), IP0 param){
    func(param);
}
*/
template<typename RT, typename P0, typename IP0>
int foo(RT (*func)(P0), IP0&& param){
    func(param);
}
/*
template<typename RT, typename P0>
int foo(RT (*func)(P0&), P0 param){
    func(param);
}
*/

#include "test_timer.h"
int main(int argc, char** argv) {
    int ret = 0;
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(ret);

    nm_timer::test();
    return 0;
}


