/*
 * @Author: lionel
 * @Date: 2020-07-30 11:14:57
 * @LastEditors: lionel
 * @LastEditTime: 2020-07-30 11:15:22
 * @Description: 
 */ 

#include <iostream>
#include <vector>
#include <sstream>
//#include "HiredisHelper.h"
#include "coroutine.h"
#include "base.h"
using namespace std;

void printnow(){
    static unsigned long long time=0;
    timeval tm;
    gettimeofday(&tm,NULL);
    if(time !=0)
        printf("cost time = %llu us\n",(tm.tv_sec*1000000+tm.tv_usec - time));
    time = tm.tv_sec*1000000+tm.tv_usec;
}
