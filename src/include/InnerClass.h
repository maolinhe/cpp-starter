#include <iostream>

using namespace std;

namespace InnerClassSpace
{
    class OutClass
    {
    private:
        int id;
        static string name;
        enum Week
        {
            Mon,
            Tue,
            Wed,
            Thu,
            Fri,
            Sat,
            Sun
        };

    public:
        OutClass() : id(10086) {}
        class InnerClass
        {
        public:
            void print(const OutClass &out)
            {
                // 内部类直接访问外部类的static成员和enum成员，借助类对象访问类的所有成员变量（友元）
                Week week1 = Sun;
                cout << "id = " << out.id << ", name = " << name << ", week = " << week1 << endl;
            }
        };
    };

    string OutClass::name = "zhangsan";
}