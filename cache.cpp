/*
 * @Author: lionel
 * @Date: 2020-07-29 10:04:48
 * @LastEditors: lionel
 * @LastEditTime: 2020-07-29 10:25:32
 * @Description: 
 */ 

#include "cache.h"
#include "HiredisHelper.h"

bool cache::check(const char* key, long long value)
{

    redisReply* reply = (redisReply*)redis_conn.ExecutevCmd("eval %s 1 %s %lld", 
    "local ret = false \
    local result \
    result = redis.call('GET', KEYS[1]) \
    if result then \
        if result == ARGV[1] then \
            ret = true \
        end \
    else    \
        ret = true  \
    end \
    return ret", 
        key, value);
    if(reply != nullptr && REDIS_REPLY_INTEGER == reply->type && true == reply->integer)
    {
        return true;
    }
    return false;
}

bool cache::write(const char* key, long long value)
{
    redisReply* reply = (redisReply*)redis_conn.ExecutevCmd("eval %s 1 %s %lld", 
    "local ret = false \
    local result \
    result = redis.call('SET', KEYS[1], ARGV[1]) \
    if result and result.ok then \
        return true \
    end \
    return false",
        key, value);
    if(reply != nullptr && REDIS_REPLY_INTEGER == reply->type && true == reply->integer)
    {
        return true;
    }
    return false;
}
