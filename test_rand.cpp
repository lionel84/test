/*
 * @Auth: lionelzhang
 * @Date: 2020-12-07 16:55:44
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-12-07 20:55:34
 * @Description: 
 */
#include "test_rand.h"
#include "stdlib.h"
#include "base.h"
#include "test_aes_cbc.h"
using namespace nm_test_aes_cbc;
namespace nm_rand{
    /*
    void aes_srand(int seed){
        myRand1::instance().init(seed);
    }
    
    inline int32_t aes_random(){
        return myRand1::instance().rand();
    }
    */
    void test(){
        int seed = time(nullptr);
        map<uint32_t, uint32_t> cache;
        mtRand myrand ;
        myrand.init(seed);
        srand(seed);
        
        const int mod = 5;
        const int count = 100000;
        uint sum = 0;
        printnow();
        for(int i = 0; i < count; i++){
            sum = myrand.extract_number();
            cache[sum%mod] ++;
        }
        printnow("myrand: ");
        printf("myrand: %u\n", sum);
        for(auto it: cache){
           printf("key: %u, count: %d\n", it.first, it.second);
        }
        cache.clear();
        
        
        printnow();
        for(int i = 0; i < count; i++){
            sum = random();
            cache[sum%mod] ++;
        }
        
        printnow("random: ");
        printf("random: %u\n", sum);
        for(auto it: cache){
           printf("key: %u, count: %d\n", it.first, it.second);
        }
        
        //myRand1 rand1;
        //myRand1::instance().init(seed);
        aes_srand(seed);
        printnow();
        cache.clear();
        
        
        printnow();
        for(int i = 0; i< count; i++){
           //sum = myRand1::instance().rand();
           sum = aes_random();
            //printf("value: %u\n", value);
            cache[(uint)sum%mod] ++;
        }
        printnow("aes rand:");
        printf("random: %u\n", sum);
        for(auto it: cache){
           printf("key: %u, count: %d\n", it.first, it.second);
        }
        srand(12);
        int a1 = random();
        int a2 = random();
        printf("a2: %d\n", a2);
        srand(a1);
        a2 = random();
        printf("a2: %d\n", a2);
    }
}