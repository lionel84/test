/*
 * @Author: lionel
 * @Date: 2020-07-30 11:14:47
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-21 17:16:59
 * @Description: 
 */ 
#ifndef __BASE_H__
#define __BASE_H__

#include <vector>
#include <algorithm>
#include  <sys/time.h>
#include <functional>
#include <assert.h>
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

void printnow();
#define ASSERT(sentence)\
    do{\
        assert((sentence));\
    }while(0)
    
#define assert_retval(sentence, val)\
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
#endif
