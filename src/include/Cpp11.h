#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace Cpp11Space
{
    void initVar()
    {
        int x1 = {1};
        int array1[]{1, 2, 3};
        int array2[5]{0}; // 以0初始化数组长度为5的数组
        int *p1 = new int[3]{1, 2, 3};
        int *p2 = new int[5]{0};
        // STL容器支持列表初始化是因为C++11新增了initializer_list容器
        vector<int> vec1 = {1, 2, 3};
        list<int> list1 = {1, 2, 3};
    }

    void autoTest()
    {
        // auto 修饰指针时， 加不加*效果一样
        // auto修饰变量必须初始化，因为要进行类型推导
        auto p1 = new int[3]{1, 2, 3};
        auto *p2 = new int(4);
        cout << "p1[1] = " << *(p1 + 1) << ", p2 = " << *p2 << endl;

        // auto修饰引用必须加&，否则会被当做普通变量
        auto &r1 = *p1;
        cout << "r1 = " << r1 << endl;

        // auto不能作为函数参数，不能直接用来声明数组
    }
}