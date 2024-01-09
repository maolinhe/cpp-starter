#include "../include/FunctionOverload.h"
#include <iostream>

void FunctionOverload::fun()
{
    std::cout << "No parameters function" << std::endl;
}

void FunctionOverload::fun(int a)
{
    std::cout << "Parameters a = " << a << std::endl;
}

void FunctionOverload::fun(int a, int b)
{
    std::cout << "Parameters int a = " << a << ", int b = " << b << std::endl;
}

void FunctionOverload::fun(int a, std::string b)
{
    std::cout << "Parameters int a = " << a << ", string b = " << b << std::endl;
}

void FunctionOverload::fun(std::string a, int b)
{
    std::cout << "Parameters string a = " << a << ", int b = " << b << std::endl;
}