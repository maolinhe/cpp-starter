#include <iostream>
#include "../include/Reference.h"

using namespace std;

Reference::Reference() {}
Reference::~Reference() {}

void Reference::basicRef()
{
    int a = 10;
    int &b = a;
    int *c = &a;

    cout << "a address = " << &a << endl;
    cout << "reference b address = " << &b << endl;
    cout << "point c address = " << &c << endl;

    b = 20;
    cout << "a = " << a << ", b = " << b << endl;
}

void Reference::constRef()
{
    int a = 100;
    const int &ra = a;

    a = 200; // b也会改变
    cout << "[const reference] a = " << a << ", ra = " << ra << endl;

    // error: assignment of read-only reference ‘ra’
    // ra = 300;

    const int c = 100;
    // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    // int &rc = c;
    const int &rc = c;
}

void Reference::paramRef(int &val)
{
    val *= val;
}

int &Reference::returnRef(int val)
{
    int &valRef = val;
    valRef *= valRef;
    return valRef;
}

void Reference::testParamAndReturnRef()
{
    int v1 = 10;
    cout << "previous v1 = " << v1 << endl;
    paramRef(v1);
    cout << "after v1 = " << v1 << endl;

    int v2 = returnRef(100);
    cout << "v2 = " << v2 << endl;
}

void Reference::referenceAndPointer()
{
    // sizeof(引用)：引用的对象类型的大小；sizeof(指针)：指针中保存的地址值的大小，32位下为4字节，64位下为8字节
    int a = 10;
    int &ca = a;
    int *pa = &a;
    cout << "sizeof(ca) = " << sizeof(ca) << ", sizeof(pa) = " << sizeof(pa) << endl;

    double b = 100;
    double &cb = b;
    double *pb = &b;
    cout << "sizeof(cb) = " << sizeof(cb) << ", sizeof(pb) = " << sizeof(pb) << endl;
}