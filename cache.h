/*
 * @Author: lionel
 * @Date: 2020-07-29 09:59:27
 * @LastEditors: lionel
 * @LastEditTime: 2020-07-29 10:07:26
 * @Description: cache
 */ 

class cache
{
    public:
    cache(){};
    ~cache(){};

    static cache& instance()
    {
        static cache cache_;
        return cache_;
    }
    bool check(const char* key, long long value);
    bool write(const char* key, long long value);
};