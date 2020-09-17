/*
 * @Author: lionel
 * @Date: 2020-07-22 18:30:59
 * @LastEditors: lionel
 * @LastEditTime: 2020-07-29 10:17:50
 * @Description: 
 */ 


#include <iostream>
#include <vector>
#include <sstream>
#include "HiredisHelper.h"
#include <stddef.h>
#include <assert.h>
#include <string.h>

using namespace std;

bool HiredisHelper::init(const string &ip, int port, const string &auth_str, int timeout)
{
    _ip = ip;
    _port = port;
    _timeout = timeout;
    _redis_async_context = NULL;
    _redis_context = NULL;
    _authstring = auth_str;

    _event_base = event_base_new();    // 创建libevent对象
    if (NULL == _event_base)
    {
        printf(": Create redis event failed.\n");
        return false;
    }

    memset(&_event_sem, 0, sizeof(_event_sem));
    int ret = sem_init(&_event_sem, 0, 0);
    if (ret != 0)
    {
        printf(": Init sem failed.\n");
        return false;
    }

    return true;
}

bool HiredisHelper::uninit()
{
    _event_base = NULL;

    sem_destroy(&_event_sem);   
    return true;
}

bool HiredisHelper::Connect()
{
    _redis_context = redisConnect(_ip.c_str(), _port);
    if(nullptr == _redis_context)
    {
        printf(": Connect redis failded.\n");
        return false;
    }
    // connect redis
    _redis_async_context = redisAsyncConnect(_ip.c_str(), _port);    // 异步连接到redis服务器上，使用默认端口
    if (NULL == _redis_async_context)
    {
        printf(": Async Connect redis failed.\n");
        return false;
    }

    if (_redis_async_context->err)
    {
        printf(": Connect redis error: %d, %s\n", 
            _redis_async_context->err, _redis_async_context->errstr);    // 输出错误信息
        return false;
    }

    // 设置连接回调，当异步调用连接后，服务器处理连接请求结束后调用，通知调用者连接的状态
    redisAsyncSetConnectCallback(_redis_async_context, 
        &HiredisHelper::connect_callback);

    // 设置断开连接回调，当服务器断开连接后，通知调用者连接断开，调用者可以利用这个函数实现重连
    redisAsyncSetDisconnectCallback(_redis_async_context,
        &HiredisHelper::disconnect_callback);

    // attach the event
    redisLibeventAttach(_redis_async_context, _event_base);    // 将事件绑定到redis context上，使设置给redis的回调跟事件关联

    if(_authstring.size() != 0)
    {
        ExecutevAsyncCmd(nullptr, nullptr, "AUTH %s", _authstring.c_str());
    }
/*
    // 创建事件处理线程
    int ret = pthread_create(&_event_thread, 0, &HiredisHelper::event_thread, this);
    if (ret != 0)
    {
        printf(": create event thread failed.\n");
        disconnect();
        return false;
    }
    */
    // 启动事件线程
    sem_post(&_event_sem);
    
    return true;
}

bool HiredisHelper::disconnect()
{
    if (_redis_async_context)
    {
        redisAsyncDisconnect(_redis_async_context);
        redisAsyncFree(_redis_async_context);
        _redis_async_context = NULL;
    }
    if(_redis_context)
    {
        //redisConnect
        redisFree(_redis_context);
        _redis_context = NULL;
    }
 
    return true;
}

int HiredisHelper::ExecuteAsyncCmd(redisCallbackFn* fn, void *privdata, const char *cmd) {
    int ret = 0;
    if(!fn)
    {
        fn = HiredisHelper::command_callback;
    }
    if(!privdata)
    {
        privdata = this;
    }
    ret = redisAsyncCommand(_redis_async_context, 
        fn, privdata, cmd); 

    return ret;
}

int HiredisHelper::ExecutevAsyncCmd(redisCallbackFn* fn, void *privdata, const char *format, ...) {
    int ret = 0;

    va_list valist;
    va_start(valist, format);
    if(!fn)
    {
        fn = HiredisHelper::command_callback;
    }
    if(!privdata)
    {
        privdata = this;
    }
    ret = redisvAsyncCommand(_redis_async_context, 
        fn, privdata, format, valist); 

    va_end(valist);

    return ret;
}

void* HiredisHelper::ExecuteCmd(const char *cmd) {
    void* ret = nullptr;
    ret = redisCommand(_redis_context,cmd); 

    return ret;
}

void* HiredisHelper::ExecutevCmd(const char *format, ...) {
    void* ret = nullptr;

    va_list valist;
    va_start(valist, format);

    ret = redisvCommand(_redis_context, 
        format, valist); 

    va_end(valist);

    return ret;
}

void HiredisHelper::connect_callback(const redisAsyncContext *redis_context,
    int status)
{
    if (status != REDIS_OK)
    {
        printf(": Error: %s\n", redis_context->errstr);
    }
    else
    {
        printf(": Redis connected!\n");
    }
}
 
void HiredisHelper::disconnect_callback(
    const redisAsyncContext *redis_context, int status)
{
    if (status != REDIS_OK)
    {
        // 这里异常退出，可以尝试重连
        printf(": Error: %s\n", redis_context->errstr);
    }
}
 
// 消息接收回调函数
void HiredisHelper::command_callback(redisAsyncContext *redis_context,
    void *reply, void *privdata)
{
    if (NULL == reply || NULL == privdata) {
        return ;
    }
 
    // 静态函数中，要使用类的成员变量，把当前的this指针传进来，用this指针间接访问
    redisReply *redis_reply = reinterpret_cast<redisReply *>(reply);
    
    // 订阅接收到的消息是一个带三元素的数组
    if (redis_reply->type == REDIS_REPLY_ERROR)
    {
        // do something
    }
}
 
void *HiredisHelper::event_thread(void *data)
{
    if (NULL == data)
    {
        printf(": Error!\n");
        assert(false);
        return NULL;
    }
 
    HiredisHelper *self_this = reinterpret_cast<HiredisHelper *>(data);
    return self_this->event_proc();
}
 
void *HiredisHelper::event_proc()
{
    sem_wait(&_event_sem);
    
    // 开启事件分发，event_base_dispatch会阻塞
    event_base_dispatch(_event_base);
 
    return NULL;
}

void HiredisHelper::print_replay(redisReply* redis_reply)
{
    if(redis_reply == nullptr)
    {
        return ;
    }
    printf("type: %d\n", redis_reply->type);
    printf("integer: %lld\n", redis_reply->integer);
    printf("dval: %lf\n", redis_reply->dval);
    printf("str: %s\n", redis_reply->str);
    printf("elements: %lu\n", redis_reply->elements);
    for(unsigned int i = 0; i< redis_reply->elements; i++)
    {
        print_replay(redis_reply->element[i]);
    }
}
