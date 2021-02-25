/*
 * @Author: lionel
 * @Date: 2020-07-30 11:12:59
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-05 14:12:35
 * @Description: 
*/ 
#include "base.h"

struct schedule;
struct schedule;
#pragma pack(1)
struct args {
    schedule* s_;
    int col_;
    bool result_;
};

#pragma pack()
void get_key(struct schedule* S, void *ud);
void redis_test();

int redis_test_init();
void redis_test_uninit();

void redis_test_proc();
/*
#define REDIS_REPLY_STRING 1
#define REDIS_REPLY_ARRAY 2
#define REDIS_REPLY_INTEGER 3
#define REDIS_REPLY_NIL 4
#define REDIS_REPLY_STATUS 5
#define REDIS_REPLY_ERROR 6
#define REDIS_REPLY_DOUBLE 7
#define REDIS_REPLY_BOOL 8
#define REDIS_REPLY_MAP 9
#define REDIS_REPLY_SET 10
#define REDIS_REPLY_ATTR 11
#define REDIS_REPLY_PUSH 12
#define REDIS_REPLY_BIGNUM 13
#define REDIS_REPLY_VERB 14
*/