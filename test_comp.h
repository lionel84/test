/*
 * @Auth: lionelzhang
 * @Date: 2020-10-20 11:13:33
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-10-20 11:46:47
 * @Description: 
 */
#ifndef _TEST_COMP_H_
#define _TEST_COMP_H_
#include "base.h"
#include <iostream>
#include <functional>
using namespace std;

namespace nm_comp{
    
    template<typename KEY_TYPE> 
    struct KEY_COMP
    {
        using function_type = std::function<bool (const KEY_TYPE& l, const KEY_TYPE& r)>;
        bool is_descending_order;
        function_type _comp_function;
        KEY_COMP(function_type comp, bool descending_order):_comp_function(comp), is_descending_order(descending_order) 
        {
        
        }
        bool operator()(const KEY_TYPE& a, const KEY_TYPE& b) const
        {
            
            bool result;
            result = _comp_function(a, b);
            if(is_descending_order){
                return !result;
            }
            return result;
        }
    };
}


#endif