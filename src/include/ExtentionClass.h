#include <iostream>

using namespace std;

namespace ExtentionSpace
{
    class BaseClass
    {
    public:
        void publicFun()
        {
            cout << "base public function" << endl;
        }

    protected:
        void protectedFun()
        {
            cout << "base protected function" << endl;
        }

    private:
        void privateFun()
        {
            cout << "base private function" << endl;
        }
    };

    class SubClass1 : public BaseClass
    {
    public:
        void fun()
        {
            publicFun();
            protectedFun();
            // privateFun() //无法访问
        }
    };

    class SubClass2 : protected BaseClass
    {
    public:
        void fun()
        {
            BaseClass::publicFun();
            BaseClass::protectedFun();
            // privateFun() //无法访问
        }
    };

    class SubClass3 : private BaseClass
    {
    public:
        void fun()
        {
            BaseClass::publicFun();
            BaseClass::protectedFun();
            // privateFun() //无法访问
        }
    };

    // 测试派生类基类的默认成员函数执行顺序
    class BaseClass1
    {
    public:
        BaseClass1()
        {
            cout << "BaseClass1 construction" << endl;
        }

        BaseClass1(const BaseClass1 &baseClass1)
        {
            cout << "BaseClass1 copy function" << endl;
        }

        ~BaseClass1()
        {
            cout << "BaseClass1 destruction" << endl;
        }
    };

    class BaseClass2
    {
    public:
        BaseClass2(int val)
        {
            cout << "BaseClass2 construction" << endl;
        }

        BaseClass2(const BaseClass2 &baseClass2)
        {
            cout << "BaseClass2 copy function" << endl;
        }

        ~BaseClass2()
        {
            cout << "BaseClass2 destruction" << endl;
        }
    };

    class SubClass4 : public BaseClass1, public BaseClass2
    {
    public:
        SubClass4() : BaseClass2(2) // 显式调用父类的自定义构造函数
        {
            cout << "SubClass4 construction" << endl;
        }

        SubClass4(const SubClass4 &subClass4) : BaseClass2(1)
        {
            cout << "SubClass4 copy function" << endl;
        }
        ~SubClass4()
        {
            cout << "SubClass4 destruction" << endl;
        }
    };
}