/*
 * @Auth: lionelzhang
 * @Date: 2021-01-05 10:48:30
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-01-05 11:11:11
 * @Description: 
 */
#include "test_function.h"
#include "base.h"
namespace nm_test_function{
    int test_func(char ch){
        cout<<ch<<endl;
    }
    //[]void (int a)
    int b = 2;
    std::function<int (int)>  myfunc;
    void test1(){
        b = 100;
        cout<<myfunc(4)<<endl;
    }
    void test2(){
        b = 200;
        cout<<myfunc(5)<<endl;
    }
    
    void test(){
        int a = 1;
        int ac[5] = {2,3,4,5,6};
        myfunc=[b, ac](int a){
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<ac[0]<<endl;
            return a+b;
        };
        //myfunc(a);
        //test1();
        //test2();
    }
    void testtest(){
        test1();
        test2();
    }
}