/*
 * @Author: lionel
 * @Date: 2020-07-22 17:33:50
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-23 10:06:35
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
    
    nm_rank_tree_v1::test(1000000);
    nm_rank_tree::test(1000000);
    nm_rank_tree_v3::test(1000000);
    //nm_ptr::test();
    //nm_test_aes_cbc::test();

    //nm_test_popen::test();
    /*
    int mod = atoi(argv[1]);
    if(mod == 1){
        nm_socket_test::recv_test();
    }else if(mod ==2){
        nm_socket_test::send_test();
    }else{
        nm_socket_test::test_send_curl();
    }*/
    
  // nm_test_json_pack::test();
    //test(static_cast<EN_TEST>(3)); 
    //nm_test_template::test();
   // NM_TEST_MAP::test();
    //nm_test_rbtree::test();
    
    //int a = -123;
    //stringstream s ;
    //s<<a;
    //printf("%s", *s);

/*
    long long nCount;
    ret = scanf("%lld", &nCount);
    if(ret != 1)return -1;
    for(int i = 0; i< nCount; i++)
    {
        int total , luyong ;
        vector<person >db;
        ret = scanf("%d %d", &total, &luyong);
        if(ret == 2){
            for(int j = 0; j< total; j++){
                person p ;
                int ret = scanf("%d %d %d %d", &(p.chenben), &(p.shouru), &(p.chenben_p), &(p.shouru_p));
                if(ret == 4){
                    db.push_back(p);
                    //cout<<52<<" "<<44<<endl;
                }
            }
        }else{
            break;
        }
        // find max
        int max = INT32_MIN;
        //int max_idx = -1;
        //vector< std::pair<int , int> > max_p_v;
        //vector< std::pair<int, int> > max_v;
        sort(db.begin(), db.end(), comp_shouru_p);
        

        //cout<<max_idx<<endl;
        int total_shouru = 0;
        int total_chenben = 0;
        total_shouru += db[0].shouru + db[0].shouru_p;
        total_chenben += db[0].chenben + db[0].chenben_p;
        luyong --;
        
        db[0].shouru = 0;
        db[0].shouru_p = 0;
        db[0].chenben = 0;
        db[0].chenben_p = 0;
        sort(db.begin(), db.end(), comp_shouru);
        
        for(auto it : db){
            total_shouru += it.shouru;
            total_chenben += it.chenben;
            luyong --;
            if(luyong == 0)break;
        }
        cout<<total_shouru<<" "<<total_chenben<<endl;

        
    }*/
    return 0;
}


