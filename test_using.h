/*
 * @Auth: Do not edit
 * @Date: 2020-08-04 18:58:24
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-10 15:33:06
 * @Description: 
 */
namespace nm_test_using
{
    class test_typedef{
    public:
        typedef int myint;
        myint v1 ;

        //template<class T>
        //typedef T my_template_int; // error: template declaration of ‘typedef’  typedef T my_template_int;
    };

    class test_using{
        public:
        using myint = int;
        myint v1;

        template<class T>
        using my_template_int = T;
        my_template_int<int> v2;
    };

    void test()
    {
        //test_typedef::myint a = 1;
        //test_using::myint b = 1;

        //test_typedef::my_template_int<int> a1 = 1;
        //test_using::my_template_int<int> b1 = 2;
    }

} // namespace test_using

