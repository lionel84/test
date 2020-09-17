/*
 * @Author: lionel
 * @Date: 2020-07-22 18:30:31
 * @LastEditors: lionel
 * @LastEditTime: 2020-07-29 10:16:36
 * @Description: 
 */ 


#ifndef _HIREDISHELPER_H_
#define _HIREDISHELPER_H_

#include <stdlib.h>
#include <hiredis/async.h>
#include <hiredis/adapters/libevent.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <functional>

using namespace std;

class HiredisHelper {
public:
	HiredisHelper(){};
	virtual ~HiredisHelper() {	}

	bool init(const string &ip, int port, const string &auth_str, int timeout = 200);
	bool uninit();

	//调用者需自行调用  freeReplyObject(reply);
    int ExecutevAsyncCmd(redisCallbackFn* fn, void *privdata, const char *format, ...);
    int ExecuteAsyncCmd(redisCallbackFn* fn, void *privdata, const char *cmd); 

	bool Connect();
	bool disconnect();

    	//调用者需自行调用  freeReplyObject(reply);
    void* ExecutevCmd(const char *format, ...);
    void* ExecuteCmd(const char *cmd); 

    static HiredisHelper& instance()
    {
        static HiredisHelper helper_;
        return helper_;
    }
	
private:
    // 下面三个回调函数供redis服务调用
    // 连接回调
    static void connect_callback(const redisAsyncContext *redis_context,
        int status);
    
    // 断开连接的回调
    static void disconnect_callback(const redisAsyncContext *redis_context,
        int status);
 
    // 执行命令回调
    static void command_callback(redisAsyncContext *redis_context,
        void *reply, void *privdata);
 
    // 事件分发线程函数
    static void *event_thread(void *data);

public:
    void *event_proc();

    static void print_replay(redisReply* redis_reply);

private:
	string _ip;
	int _port;
	int _timeout;
	string _authstring;
     // libevent事件对象
    event_base *_event_base;
    // 事件线程ID
    pthread_t _event_thread;
    // 事件线程的信号量
    sem_t _event_sem;
    // hiredis异步对象
    redisAsyncContext *_redis_async_context;
    redisContext* _redis_context;
};

#define redis_conn HiredisHelper::instance()

#endif /* _HIREDISHELPER_H_ */
