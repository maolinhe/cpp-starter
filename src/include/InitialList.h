#include <iostream>

using namespace std;

namespace InitialList
{
    class T1
    {
    public:
        T1()
        {
            cout << "T1 construction" << endl;
        }
        T1(const T1 &t1)
        {
            cout << "T1 copy construction" << endl;
        }
        T1 &operator=(const T1 &t1)
        {
            cout << "T1 operator =" << endl;
            return *this;
        }
    };

    class T2
    {
    public:
        T1 t1; // 先调用T1的默认构造函数初始化t1
        T2() {}
        T2(T1 &t1)
        {
            // 再调用T1的重载=赋值
            this->t1 = t1;
        }
    };

    class T3
    {
    public:
        T1 t1;
        T3() {}
        T3(T1 &t1) : t1(t1) // 只调用一次T1的拷贝构造函数
        {
        }
    };
}