/*
 * @Auth: lionelzhang
 * @Date: 2020-10-22 17:05:03
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-01-06 10:39:52
 * @Description: 
 */
#include "base.h"
#include "test_auto_ptr.h"
#include <memory>

namespace nm_ptr1 {
    void test()
    {
        std::weak_ptr<int> p5;
        {
            std::shared_ptr<int> p1 = std::make_shared<int>(5);
            p5 = p1;
        }
      
        std::cout<<"test weak_ptr"<<std::endl;
        
        std::cout<<p5.use_count()<<endl;
        auto it = p5.lock();
        if(it){
            std::cout<<it<<" "<<*it<<endl;
        }
        //std::cout<<p6<<endl;
    }
}