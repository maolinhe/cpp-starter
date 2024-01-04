#include <iostream>

using namespace std;

namespace MemoryManagerSpace
{
    void testNewAndDelete()
    {
        // 基本类型
        int *p1 = new int;
        *p1 = 10;
        delete p1;

        // 数组
        int *p2 = new int[3];
        *p2 = 1;
        *(p2 + 1) = 2;
        *(p2 + 2) = 3;
        delete[] p2;

        // 基本类型初始化
        int *p3 = new int(10);
        delete p3;

        // 数组初始化
        int *p4 = new int[3]{1, 2, 3};
        delete[] p4;

        // 自定义类型
        string *s1 = new string;
        *s1 = "Hello c++";
        delete s1;

        // 自定义类型初始化
        string *s2 = new string("hello cpp");
        delete s2;
    }
}