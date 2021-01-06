/*
 * @Auth: lionelzhang
 * @Date: 2021-01-06 10:34:18
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-01-06 10:40:39
 * @Description: 
 */
#include "test_ptr.h"
#include "base.h"
namespace nm_ptr
{
    void test(){
        int * a = new int();
        std::weak_ptr<int> ap;
        {
            std::shared_ptr<int> asp = std::make_shared<int>(1);
            ap = asp;
            if(auto temp = ap.lock()){
                cout<<*temp<<endl;
            }
        }
        if(auto temp = ap.lock()){
            cout<<*temp<<endl;
        }
        
    }
}