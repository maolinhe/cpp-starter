#include <iostream>

using namespace std;

namespace MemoryManagerSpace
{
    void basicMemoryAllocation()
    {
        int a = 10, b = 20, c = 30, d = 40;
        cout << "a address = " << &a << endl;
        cout << "b address = " << &b << endl;
        cout << "c address = " << &c << endl;
        cout << "d address = " << &d << endl;

        cout << "b = " << b << endl;
        cout << "*(&b+1) = " << *(&b - 1) << endl; // 指向a
        cout << "*(&b+2) = " << *(&b + 1) << endl; // 指向c
    }
}