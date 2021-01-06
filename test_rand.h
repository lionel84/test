/*
 * @Auth: lionelzhang
 * @Date: 2020-12-07 16:44:17
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-12-07 21:24:30
 * @Description: 
 */
#ifndef _TEST_RAND_H_
#define _TEST_RAND_H_
#include <vector>
#include <stdlib.h>
#include <cstdint>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <memory>
#include <string.h>
using namespace std;
namespace nm_rand
{
    class mtRand{
        public:
        static mtRand& instance(){
            static mtRand _instance;
            return _instance;
        }
        
        void init(int seed){ //}, int left, int right){
            mt.resize(624);
            mt[0] = seed;
            mti = 0;
            //_left = left;
            //_right = right;
            for(int i = 1 ; i< 624; i++){
                mt[i] = int32_t(1812433253 * (mt[i - 1] ^ mt[i - 1] >> 30) + i);
            }
        }
        
        uint32_t extract_number(){
            if(mti == 0){
                twist();
            }
            int64_t y = mt[mti];
            y = y^y >>11;
            y = y^y <<7 & 2636928640;
            y = y ^ y << 15 & 4022730752;
            y = y ^ y >> 18;
            mti = (mti + 1)%624;
            return int32_t(y);
        }

        void twist(){
            for(int i = 0; i< 624; i++){
                int32_t y = int32_t((mt[i] & 0x80000000) + (mt[(i + 1) % 624] & 0x7fffffff));
                mt[i] = (y >> 1) ^ mt[(i + 397) % 624];


                if (y % 2 != 0)
                    mt[i] = mt[i] ^ 0x9908b0df;
            }
        }
        private:
        vector<int64_t> mt;
        int32_t mti ;
       // int32_t _left ;
       // int32_t _right;       
    };

    class aesRand
    {
    public:
        using cipher_evp_t = EVP_CIPHER_CTX;
        static aesRand& instance(){
            static aesRand _instance;
            return _instance;
        }
        aesRand():enc(nullptr), index(0){
        }
    private:
        cipher_evp_t *enc;
        int index;
        unsigned char buf[2][32];
    public:
        void init(uint32_t seed)
        {
            unsigned char ivec[16] = {
                0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
            };
            const unsigned char key[] = {"1234567812345678"};
            memset(buf, 0, sizeof(char)*2*32);
            if(enc){
                EVP_CIPHER_CTX_free(enc);
                enc = nullptr;
            }
            enc = EVP_CIPHER_CTX_new();
            int32_t ret = EVP_EncryptInit_ex(enc, EVP_aes_128_cbc(), NULL, key, ivec);
            if(ret == 0){
                return;
            }
            printf("seed: %d\n", seed);
            *(int32_t*)buf[index] = seed;
            return;
        }
        long random(){
            encrypt(buf[index], buf[!index]);
            index = !index;
            return *(long*)buf[index];
        }
        void encrypt(const unsigned char *buf_in, unsigned char *buf_out){
            int out_len = 32;
                EVP_EncryptUpdate(enc, buf_out,&out_len, buf_in, 32) ;
        }
    };
    #define aes_srand(seed) aesRand::instance().init(seed)
    #define aes_random() aesRand::instance().random()

    void test();
}
#endif