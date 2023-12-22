#include <iostream>

using namespace std;

namespace StaticNamespace
{
    class Person
    {
    public:
        static int age;
        // static const int 可以在类内声明和定义，其它的数据类型不行
        static const int height = 180;
        void printAge();
    };
};