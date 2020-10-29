/*
 * @Author: lionel
 * @Date: 2020-07-22 17:33:50
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-29 21:29:35
 * @Description: main
 */ 

//#include "test_find_if.h"
//#include "redis_test.h"
//#include "coroutine_test.h"
//#include "cache.h"
#include "test_using.h"
#include "test_pair.h"
#include "base.h"
#include "test_tree.h"
#include "test_template.h"
#include "test_map.h"
#include "test_rbtree.h"
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
#include "test_rbtree.h"
#include "redis_test.h"

#include "rank_tree.h"
#include "rank_tree_v1.h"
#include "rank_tree_v3.h"
#include "test_auto_ptr.h"
#include "skiplist_tree.h"
map< int, int> map_;
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
int main(int argc, char** argv) {
    int ret = 0;
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(ret);

    //redis_test();
    
   // nm_rank_tree_v1::test(1000000);
    nm_rank_tree::test(10000000); 
  //  nm_rank_tree_v3::test(1000000);
  nm_skiplist::test(10000000);
    //nm_ptr::test();
    //nm_test_aes_cbc::test();

    //nm_test_popen::test();
    return 0;
}


