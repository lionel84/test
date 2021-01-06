/*
 * @Auth: lionelzhang
 * @Date: 2020-12-08 11:20:56
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-12-08 17:15:41
 * @Description: 
 */
#include "test_m_list.h"
#include "base.h"
#include <list>
#include <deque>
#include <stack>
using namespace std;
namespace nm_m_list
{
    void test(){
        mList<int> mlist;
        list<int> ilist;
        ilist.push_back(3);
        ilist.push_back(4);

        deque<int> dq ;
        dq.push_back(4);
        dq.push_front(3);
        int a = dq.front();
        int b = dq.back();
      //  cout<<a<<endl;
     //   cout<<b<<endl;
        //ilist.
       // ilist.insert(3);
       stack<int> st;
       st.push(3);
       st.push(45);
       cout<<"size: "<<st.size()<<endl;
       int size = st.size();
       for(int i = 0; i< size; i++){
           printf("top: %d %d\n", i, st.top());
           st.pop();
           cout<<"size: "<<st.size()<<endl;
       }
       //int a1 = st.pop();
       int a11 = st.top();
       cout<<"3:"<<a11<<endl;
       cout<<"end"<<endl;

       st.emplace(34);
       st.push(23);

printf("top: %d %d\n", 0, st.top());

    }
}
