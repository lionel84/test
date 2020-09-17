/*
 * @Auth: lionelzhang
 * @Date: 2020-09-04 16:39:15
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-09-04 21:26:56
 * @Description: 
 */

#include "test_aes_cbc.h"
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#define PADDING_MODE 5
namespace nm_test_aes_cbc {
    void encrypt(const unsigned char *buf_in, int in_len, unsigned char *buf_out, int *out_len){
        int ret;
        unsigned char ivec[16] = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
        };
        const unsigned char key[] = {"1234567812345678"};
        typedef EVP_CIPHER_CTX cipher_evp_t;
        cipher_evp_t *enc = EVP_CIPHER_CTX_new();
        ret = EVP_EncryptInit_ex(enc, EVP_aes_128_cbc(), NULL, key, ivec);
        //printf("ret: %d\n", ret);

        int first_size , left_size = 0;
        int block_size = EVP_CIPHER_CTX_block_size(enc);
        first_size = (in_len / block_size) * block_size;
        left_size = in_len % block_size;
        int  first_out_size = 0, second_out_size = 0, final_out_size = 0;
        do{
            #if 1
            first_size = in_len;
            if(first_size >= block_size){
                first_out_size = *out_len;
                EVP_EncryptUpdate(enc, buf_out, &first_out_size, buf_in, first_size) ;
            }
            #else
            if(first_size){
                first_out_size = *out_len;
                EVP_EncryptUpdate(enc, buf_out, &first_out_size, buf_in, first_size) ;
                buf_in += first_size;
                //buf_out += first_out_size;
            }
            if(left_size){
                second_out_size = *out_len - first_out_size;
                static unsigned char padding[128];
                if(sizeof(padding) < block_size){
                    ret = -5;
                    break;
                }
                for(size_t i = 0; i< left_size; i++){
                    padding[i] = buf_in[i];
                }
                for(size_t i = left_size; i< block_size; i++){
                    padding[i] = 0;
                }
                EVP_EncryptUpdate(enc, buf_out+ first_out_size, &second_out_size, padding, block_size) ;
            }
            #endif
            ret = EVP_CIPHER_CTX_set_padding(enc, PADDING_MODE);
            //printf("ret: %d\n", ret);
            final_out_size = *out_len - first_out_size - second_out_size;
            ret = EVP_EncryptFinal_ex(enc, buf_out + first_out_size + second_out_size, &final_out_size);
            //printf("ret: %d\n", ret);
            /* Clean up */
            EVP_CIPHER_CTX_free(enc);
            *out_len = first_out_size + second_out_size + final_out_size;
        }while(0);
    }   
    void decrypt(const unsigned char *in, int in_len, unsigned char *out, int *out_len){
        int ret;
        unsigned char ivec[16] = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
        };
        const unsigned char key[] = {"1234567812345678"};
                typedef EVP_CIPHER_CTX cipher_evp_t;

        cipher_evp_t *dec = EVP_CIPHER_CTX_new();
        ret = EVP_DecryptInit_ex(dec, EVP_aes_128_cbc(), NULL, key, ivec);
        //printf("ret: %d\n", ret);
        ret = EVP_CIPHER_CTX_set_padding(dec, 5);
        //printf("ret: %d\n", ret);
        
        int  first_out_size = 0, second_out_size = 0, final_out_size = 0;

        first_out_size = *out_len;
        EVP_DecryptUpdate(dec, out, &first_out_size, in, in_len) ;
        final_out_size = *out_len - first_out_size;
        ret = EVP_DecryptFinal_ex(dec, out + first_out_size, &final_out_size);
        printf("ret: %d\n", ret);
        /* Clean up */
        EVP_CIPHER_CTX_free(dec);
        *out_len = first_out_size + final_out_size;
    }   
    void test(){
        //unsigned char in[]= "abcdabcdabcdabcda";
        unsigned char in[]= "1234567812345678";
        //in[sizeof(in)-1] = 16;
        
        int in_len = sizeof(in);
        unsigned char out[128];
        int out_len = sizeof(out);
        encrypt(in, in_len, out, &out_len);
        printf("%s\n", out);
        for(int i = 0; i< in_len; i++){
            printf("%d ", in[i]);
        }
        printf("\n");
        unsigned char de_buf[129];
        int de_buf_len = sizeof(de_buf);
        decrypt(out, out_len, de_buf, &de_buf_len);
        printf("old[size: %d]: %s\n", sizeof(in), in);
        printf("new[size: %d]: %s\n", de_buf_len, de_buf);
        for(int i = 0; i< de_buf_len; i++){
            printf("%d ", de_buf[i]);
        }
        printf("\n");

    }
}