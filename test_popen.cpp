/*
 * @Auth: lionelzhang
 * @Date: 2020-09-02 17:06:25
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-09-02 17:08:14
 * @Description: 
 */
#include "stdio.h"
namespace nm_test_popen {
    void test(){
        FILE* fd = popen("cat 1", "r");
        if(fd == NULL){
            return ;
        }
        char buf[10240];
        fread(buf, 1, 10240, fd);
        printf("buf: %s\n", buf);
        pclose(fd);
    }
}