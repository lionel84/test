/*
 * @Author: lionel
 * @Date: 2020-07-30 11:13:12
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-05 14:07:35
 * @Description: 
 */ 
#include <iostream>
#include <vector>
#include <sstream>
#include "HiredisHelper.h"
#include "coroutine.h"
#include "redis_test.h"
#include "cache.h"
#include "base.h"
using namespace std;

void redis_setnx_cb(struct redisAsyncContext* ctx, void* reply, void* pri_data)
{
    UNUSED(ctx);
//    cout<<"redis_setnx_cb"<<endl;
    if(!reply)
    {
        return ;
    }
    redisReply *redis_reply = reinterpret_cast<redisReply *>(reply);
    //print_replay(redis_reply);
    struct args* args = (struct args*)pri_data;
    if(redis_reply->integer == 1)//true
    {
        args->result_ = true;
    }else // false
    {
    }
    coroutine_resume(args->s_, args->col_);
}

void redis_del_cb(struct redisAsyncContext* ctx, void* reply, void* pri_data)
{
    UNUSED(ctx);
//    cout<<"redis_del_cb"<<endl;
    if(!reply)
    {
        return ;
    }
    redisReply *redis_reply = reinterpret_cast<redisReply *>(reply);
    struct args* args = (struct args*)pri_data;
    if(redis_reply->integer == 1)//true
    {
        //cout<<"del key suc"<<args->col_<<endl;
    }else // false
    {
        cout<<"del key fail"<<args->col_<<endl;
    }
}


//static HiredisHelper redis_conn;

void
get_key(struct schedule* S, void *ud){
    struct args* args = (struct args*)ud;
    while(true)
    {
        redis_conn.ExecutevAsyncCmd(redis_setnx_cb, ud, "SETNX %s %d", "test_key", 1);
        coroutine_yield(S);
        if(args->result_ == true)
        {
            cout<<"get key suc "<<args->col_<<endl;
            break;
        }
        else
        {
            cout<<"get key fail "<<args->col_<<endl;
        }
    }

    redis_conn.ExecutevAsyncCmd(redis_del_cb, ud, "DEL %s", "test_key");
}

int redis_test_init()
{
   int ret = 0;
#if 0
    string redis_ip = "9.134.42.250";
    int redis_port = 6380;
    string redis_auth = "FvBKZ*3872wz";
#else
    string redis_ip = "127.0.0.1";
    int redis_port = 6379;
    string redis_auth = "1";
#endif
    ret = redis_conn.init(redis_ip, redis_port, redis_auth);
    if(!ret)return ret;
    ret = redis_conn.Connect();
    if(!ret)return ret;
    return ret;
}
void redis_test_uninit()
{
    redis_conn.disconnect();
    redis_conn.uninit();
    return;
}

void redis_test_proc()
{
    while(true)
    {
        redis_conn.event_proc();
        sleep(1);
    }
    return;
}

void redis_test()
{
    printf("write 1\n");
    bool result = cache::instance().write("test_key", 1);
    
    result = cache::instance().check("test_key", 1);
    printf("checked 1 %d\n", result);
    result = cache::instance().check("test_key", 2);
    printf("checked 2 %d\n", result);

    printf("write 2\n");
    result = cache::instance().write("test_key", 2);

    result = cache::instance().check("test_key", 1);
    printf("checked 1 %d\n", result);
    result = cache::instance().check("test_key", 2);
    printf("checked 2 %d\n", result);

    redis_test_proc();
    /*
    printnow();
    for(int i = 0; i< count; i++)
    {
        //redisReply* reply = (redisReply*)redis_conn.ExecutevCmd("DEL test_key_%d", i);
        char key[64];
        sprintf(key, "test_key_%d", i);
        redisReply* reply = (redisReply*)redis_conn.ExecutevCmd("eval %s 1 %s", 
        "local r  r = redis.call('DEL',KEYS[1]) return r", 
        key);
        //"eval \"local r  r = redis.call(\'get\',\'test\') return r\" 0"
        if(reply != nullptr && REDIS_REPLY_INTEGER == reply->type && 1 == reply->integer)
        {
            suc += 1;
        }
        //redisReply* reply1 = (redisReply*)redis_conn.ExecutevCmd("DEL test_async_key_%d", i);
        char key1[64];
        sprintf(key1, "test_async_key_%d", i);
        redisReply* reply1 = (redisReply*)redis_conn.ExecutevCmd("eval %s 1 %s", 
        "local r \
        r = redis.call('DEL',KEYS[1]) \
        if r == nil then return -3 end \
        if r == 1 then return 0 end \
        return -1"
         , key1);
        if(reply1 != nullptr && REDIS_REPLY_INTEGER == reply1->type && 1 == reply1->integer)
        {
            suc += 1;
        }
    }
    cout<<"del suc count: "<<suc<<endl;
    */
   /*
    printnow();
    suc = 0;
    for(int i = 0; i< count; i++)
    {
        char key1[64];
        sprintf(key1, "test_key_%d", i);
        redisReply* reply = (redisReply*)redis_conn.ExecutevCmd("eval %s 1 %s %d", 
        "local r  = {} \
        r[1] = false \
        r[2] = ARGV[1] \
        local result \
        result = redis.call('GET', KEYS[1]) \
        if result then \
            if result == ARGV[1] then \
                r[1] = true \
            else    \
                r[2] = result \
            end \
        else    \
            result = redis.call('SET', KEYS[1], ARGV[1]) \
            if result then \
                r[1] = true \
            end \            
        end \
        return r", 
            key1, i+1);
        //redisReply* reply = (redisReply*)redis_conn.ExecutevCmd("SETNX test_key_%d %d", i, 1);
        if(reply != nullptr && REDIS_REPLY_ARRAY == reply->type && 2 == reply->elements )
        {
            if(REDIS_REPLY_INTEGER == reply->element[0]->type 
            && reply->element[0]->integer )
            {
                suc += 1;
            }
            else
            {
                int addr = atoi(reply->element[1]->str);
                cout<<addr<<endl;
            }
        }
    }
    cout<<"add suc count: "<<suc<<endl;
    printnow();
    suc = 0;
    for(int i = 0; i< count; i++)
    {
        char key1[64];
        sprintf(key1, "test_async_key_%d", i);
        ret = redis_conn.ExecutevAsyncCmd(nullptr, nullptr, "eval %s 1 %s %d", 
        "local r  = {} \
        local result \
        result = redis.call('GET', KEYS[1]) \
        if result then \
            if result == ARGV[1] then \
                r[1] = 'key has exsit check value ok' \
            else    \
                r[1] = 'key has exsit check value not ok' \
            end \
        else    \
            result = redis.call('SET', KEYS[1], ARGV[1]) \
            if result then \
                r[1] = 'key not exsit, insert ok' \
            else    \
                r[1] = 'key not exsit, insert not ok' \
            end \            
        end \
        return r", 
            key1, i);
        //int ret = redis_conn.ExecutevAsyncCmd(nullptr, nullptr, "SETNX %s %d", "test_async_key_%d 1", i);
        if(ret == 0)
        {
            suc += 1;
        }
    }
    cout<<"add suc count: "<<suc<<endl;
    printnow();
    */
    /*
    for(
    struct args arg[count];
    printf("main start, count: %d\n", count);

    for(int i = 0; i< count; i++)
    {
        struct args& arg1 = arg[i];
        test(S, arg1);
    }

    */
    //printnow();
}
