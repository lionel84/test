/*
 * @Auth: Do not edit
 * @Date: 2020-08-05 11:21:29
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-06 21:12:08
 * @Description: 
 */
#include <iostream> // for make_pair
#include <memory>   // for shared_ptr

namespace nm_test_pair{
    using namespace std;
    std::shared_ptr<std::pair<int, char> > test_func(int v1, char v2){
        return std::make_shared<std::pair<int, char> >(std::make_pair(v1, v2));
    }

    void test(){
        std::shared_ptr<std::pair<int, char> > result = test_func(1, 'a');
        if(result){
            cout<<result->first<<endl;
            cout<<result->second<<endl;
            cout<<"ok"<<endl;
            
        }
    }
}