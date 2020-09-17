/*
 * @Author: lionel
 * @Date: 2020-07-30 13:56:23
 * @LastEditors: lionel
 * @LastEditTime: 2020-07-30 14:04:33
 * @Description: 
 */ 

#include "coroutine.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "base.h"
#include "redis_test.h"
using namespace std;
/*
static void
test(struct schedule *S, struct args& arg1) {
    int co1 = coroutine_new(S, get_key, &arg1);
    arg1.s_ = S;
    arg1.col_ = co1;
    arg1.result_ = false;
    coroutine_resume(arg1.s_, arg1.col_);
}
*/
void coroutine_test()
{
    struct schedule * S = coroutine_open();


    char end_;
    cin>>end_;

    coroutine_close(S);
}
