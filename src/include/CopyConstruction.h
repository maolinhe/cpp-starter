#include <iostream>

using namespace std;

class ClassA
{
private:
    int a;

public:
    ClassA()
    {
        cout << "ClassA default construction" << endl;
    }
    ClassA(ClassA &classA)
    {
        cout << "ClassA copy construction" << endl;
    }
};

class ClassB
{
private:
    int b;
    ClassA classA;

public:
    ClassB()
    {
        cout << "ClassB default construction" << endl;
    }
    ClassB(int b, ClassA classA) : b(b), classA(classA)
    {
        cout << "ClassB custom construction" << endl;
    }
    ClassB(ClassB &classB)
    {
        cout << "ClassB copy construction" << endl;
    }
};

class ClassC
{
public:
    ClassC()
    {
        cout << "ClassC default construction" << endl;
    }
    ClassC(ClassC &obj)
    {
        cout << "ClassC copy construction" << endl;
    }
    ClassC &operator=(ClassC &obj)
    {
        cout << "ClassC = construction" << endl;
        return *this;
    }
};