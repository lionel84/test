/*
 * @Author: lionel
 * @Date: 2020-07-30 11:14:57
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-11-12 10:41:50
 * @Description: 
 */ 

#include <iostream>
#include <vector>
#include <sstream>
//#include "HiredisHelper.h"
#include "coroutine.h"
#include "base.h"
using namespace std;
#include  <sys/time.h>
typedef unsigned long long cycles_t;

cycles_t currentcycles1()
{
    cycles_t result;
    __asm__ __volatile__ ("rdtsc" : "=A" (result));
        
    return result;
}
static inline unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

void get_zhupin(unsigned long long & pinlv){
    FILE *fp;
    char str[81];
    memset(str,0,81);
    fp=popen("cat /proc/cpuinfo|grep cpu\\ MHz|sed -e 's/.*:[^0-9]//'","r");
    if(fp<0){
        printf("无法读取 CPU主频信息\n");
        exit(1);
    }
    fgets(str,80,fp);
    fclose(fp);
    double spd=atof(str);
    printf("您 CPU的 主频是%fMHz\n",spd);
    pinlv = spd;
}

void printnow(string desc){
    static unsigned long long time=0;
    static unsigned long long time_c = 0;
    static unsigned long long pinlv = 0;
    if(pinlv == 0){
        get_zhupin(pinlv);
    }
    timeval tm;
    gettimeofday(&tm,NULL);
    unsigned long long time_c_c = rdtsc();
    if(time !=0 && desc != ""){

        printf(
            "%s cost time : %llu us cycles: %llu us %llu %llu %llu\n",desc.c_str(), (tm.tv_sec*1000000+tm.tv_usec - time)
        , (time_c_c - time_c)/pinlv, time_c_c - time_c, time_c_c, time_c);
    }
    time = tm.tv_sec*1000000+tm.tv_usec;
    time_c = time_c_c;
}
