#include <iostream>
#include <string>

class FunctionOverload
{
public:
    void fun();
    void fun(int a);
    void fun(int a, int b);
    void fun(int a, std::string b);
    void fun(std::string a, int b);
};