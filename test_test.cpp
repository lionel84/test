/*
 * @Auth: lionelzhang
 * @Date: 2020-09-10 21:20:06
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-09-10 21:25:54
 * @Description: 
 */
#include "test_test.h"
#include "base.h"
namespace nm_test {
    bool checkmi(int in){
        while(true){
            if(in == 1)
            {
                return true;
            }
            if(in == 0){
                return false;
            }
            if(in %2 != 0)return false;
            in = in/2;
        }
    }
    bool checkmi1(int in){
        return (in | (in-1)) == ((in<<1) -1);
    }
    void test(){
        printf("%d\n", checkmi1(2));
        printf("%d\n", checkmi1(9));
        printf("%d\n", checkmi1(16));
    }
}