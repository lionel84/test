/*
 * @Auth: lionelzhang
 * @Date: 2021-01-08 21:08:35
 * @LastEditors: lionelzhang
 * @LastEditTime: 2021-01-12 15:57:00
 * @Description: 
 */
#include "test_uv.h"
#include "base.h"
#include <uv.h>
namespace nm_uv
{
    static int run = true;
    void test()
    {
        uv_timer_t tick_timer;
        uv_timer_init(uv_default_loop(), &tick_timer);
        cout<<"begin"<<endl;
        int* count = new int(5);

        tick_timer.data = (void*)count;
        uv_timer_start(&tick_timer, [](uv_timer_t *handle){
            int* count = (int*)handle->data;
            
            if(*count ){
                cout<<"cb "<<*count<<endl;
            }
            else{
                //uv_timer_stop(handle);
            }
            *count -=1;
            cout<<"uv_is_active "<<uv_is_active((uv_handle_t*)handle)<<endl;
            if(*count < 0){
                uv_timer_stop(handle);
            }
            int temp = uv_loop_alive(uv_default_loop());
            cout<<"temp "<<temp<<endl;
            cout<<"uv_is_active "<<uv_is_active((uv_handle_t*)handle)<<endl;

        }, 1000, 1000); // ms
        
        uv_run(uv_default_loop(), UV_RUN_DEFAULT);
        uv_close((uv_handle_t *)&tick_timer, nullptr);
    }
}