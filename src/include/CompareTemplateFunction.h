#include <iostream>

using namespace std;

namespace TemplateSpace
{
    template <typename T>
    T max(T a, T b)
    {
        return a > b ? a : b;
    }
}