/*
 * @Auth: lionelzhang
 * @Date: 2020-08-18 15:04:35
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-18 15:51:23
 * @Description: 
 */
#ifndef _NM_TEST_TEMPLATE_H_
#define _NM_TEST_TEMPLATE_H_
#include <vector>
namespace nm_test_template{
    struct TESTS{
        int type;
        int arg;
    };
    template<class T>
    void check(const T& lists);

    void test();
}

#endif