/*
 * @Author: lionel
 * @Date: 2020-07-30 11:14:47
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-11-06 21:29:45
 * @Description: 
 */ 
#ifndef __BASE_H__
#define __BASE_H__

#include <vector>
#include <algorithm>
#include  <sys/time.h>
#include <functional>
#include <assert.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <iostream> 
#include <unordered_map>
#include <memory>
//#include <ext/hash_map>
//using namespace __gnu_cxx;
using namespace std;
#ifndef UNUSED
#define UNUSED(x) ((void)x)
#endif
struct schedule;
#pragma pack(1)
struct args {
    schedule* s_;
    int col_;
    bool result_;
};
#pragma pack()

void printnow(string desc = "");
#define ASSERT(sentence)\
    do{\
        assert((sentence));\
    }while(0)
    
#define assert_retval(sentence, val) \
    do{                     \
        if (sentence) break;\
        ASSERT(sentence);   \
        return val;         \
    }while(0)
            
#define assert_retnone(sentence) \
    do{                     \
        if (sentence) break;\
        ASSERT(sentence);   \
        return;             \
    }while(0) 

    template<typename T>
    void printv(T& v){
        for(auto i:v){
            printf("%d ", i);
        }
        printf("\n");
    }
    /*
    template<typename T>
        void printv(T v){
        for(auto i:v){
            printf("%d ", i);
        }
        printf("\n");
    }
    */
#endif

