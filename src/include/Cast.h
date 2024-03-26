using namespace std;

namespace CastSpace
{
    void testStaticCast()
    {
        int i = 10, j = 3;
        double slope = static_cast<double>(i) / j;
        cout << "slope = " << slope << endl;
        void *p1 = &slope;
        double *p2 = static_cast<double *>(p1);
        cout << "*p2 = " << *p2 << endl;
    }

    class A
    {
    public:
        // dynamic_cast必须要在父类中定义虚函数
        virtual void fun()
        {
            cout << "Class A fun" << endl;
        };
    };
    class B : public A
    {
    public:
        void fun() override
        {
            cout << "Class B fun" << endl;
        };
    };
    void testDynamicCast()
    {
        A *a = new B();
        a->fun();
        B *b = dynamic_cast<B *>(a);
        b->fun();
    }

    void testConstCast()
    {
        const char *p1;
        cout << "*p1 = " << *p1 << endl;
        char *p2 = const_cast<char *>(p1);
        *p2 = 'A';
        cout << "*p2 = " << *p2 << endl;
    }
}