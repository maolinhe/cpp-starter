# Beginner of cpp

- [Beginner of cpp](#beginner-of-cpp)
  - [c++基础](#c基础)
    - [namespace](#namespace)
    - [namespace定义](#namespace定义)
    - [namespace使用](#namespace使用)
    - [标准输入输出](#标准输入输出)
    - [缺省参数](#缺省参数)
      - [全缺省](#全缺省)
      - [半缺省](#半缺省)
    - [函数重载](#函数重载)
      - [函数重载原理](#函数重载原理)
      - [extern "C"](#extern-c)
    - [单元测试-googletest](#单元测试-googletest)
      - [SetUp and TearDown函数](#setup-and-teardown函数)
      - [测试用例宏](#测试用例宏)


## c++基础

### namespace
一个命名空间定义了一个新的作用域，命名空间内所有的内容都局限于该命名空间

### namespace定义
* namespace 关键字后面跟命名空间名称和大括号
```cpp
namespace MyNamespace {
    void print() {
        std::cout << "print in MyNamespace" << endl;
    }
}
```
* namespace支持嵌套
* 同一个工程中允许存在多个相同名称的命名空间，编译器最后会将其所有成员合在一个命名空间中

### namespace使用
* 命名空间和作用域限定符
```cpp
MyNamespace::print();
```
* 使用using引入命名空间中的成员
```cpp
using MyNamespace::print;
```
* 使用using引入整个命名空间
```cpp
using MyNamespace
```

### 标准输入输出
* std::cin: 标准输入
```cpp
int val;
std::cin >> val;
```
* std::cout: 标准输出
```cpp
std::cout << "Hello cpp" << std::endl;
```
* std::cerr: 标准错误输出
```cpp
std::cerr << "Hello cpp" << std::endl;
```

### 缺省参数
在声明或者定义函数的时候，为函数的参数指定一个默认值，在调用函数的时候，如果没有为该参数传入实参，则采用默认参数，否则采用实参
* 缺省参数不能在声明和定义中同时出现
* 缺省参数值必须是常量或者全局变量
#### 全缺省
函数的全部参数在定义的时候全部设置默认值
```cpp
int default_all_params(int length = 3, int width = 4, int height = 5) {
    std::cout << "length = " << length << ", width = " << width
    << ", height = " << height << std::endl;
    return length * width * height;
}
```

#### 半缺省
* 必须从右到左依次给出，不能间隔
```cpp
int default_partial_params(int length, int width = 4, int height = 5) {
    std::cout << "length = " << length << ", width = " << width
    << ", height = " << height << std::endl;
    return length * width * height;
}
```
### 函数重载
同一个作用域中的两个函数的函数名相同，但是形参列表不同：
* 形参个数不同
* 形参类型不同
* 形参顺序不同

#### 函数重载原理
C++函数再编译后会生成一个标识符，该标识符由函数名称和函数参数类型共同组成，因此即使同名函数，参数不同，修饰出来的标识符可能会不一样，这个就支持了函数重载
例如：
以下两个函数
```cpp
void fun(int a, string b);
void fun(string a, int b);
```
编译出来的函数标识符分别为
```cpp
_fun_int_string
_fun_string_int
```
#### extern "C"
C语言中函数无法重载，因为它不支持函数类似C++的函数标识符的编译机制。在C++中，如果使用`extern "C"`修饰函数，那么函数就无法重载
```cpp
#include <iostream>
using namespace::std

extern "C" void fun()
{
  
}
extern "C" void fun(int a)
{
  
}

int main()
{

}

```
上面的写法编译会报错，提示不允许函数fun的重载

### 单元测试-googletest
googletest简称gtest是一个用于c++单元测试的框架。仓库地址[https://github.com/google/googletest.git](https://github.com/google/googletest.git)

安装gtest环境，以ubuntu为例
```bash
sudo git clone https://github.com/google/googletest.git
sudo cd googletest
sudo mkdir build & cd build
sudo cmake ..
sudo make
sudo make install
```
安装后路径
```bash
/usr/local/lib
/usr/local/include/gtest
```

#### SetUp and TearDown函数
* SetUpTestCase()
  在测试类的构造函数之后和第一个测试用例之前执行

* SetUp()
  在每一个测试用例执行之前执行，TEST宏不生效

* TearDownTestCase()
  在最后一个测试用例之后和测试类的析构函数之前执行，TEST宏不生效

* TearDown()
  在每一个测试用例执行之后执行，TEST宏不生效

#### 测试用例宏
* TEST
  用于快速测试的宏，不依赖测试类，因此也不会升到测试类的生命周期函数影响
```cpp
TEST(TestSuiteName, TestName) {
  ... statements ...
}
```
* TEST_F
  依赖于测试类，并且受到测试类生命周期函数影响。TEST_F包含了TEST所有功能，因此一般会直接使用TEST_F
```cpp
TEST_F(TestFixtureName, TestName) {
  ... statements ...
}
```
* TEST_P
  一个参数化的测试用例宏，当需要测试的数据比较多的时候，可以简化我们的代码书写。使用TEST_P需要让测试类继承`testing::TestWithParam<Type>`
```cpp
class TestClass : public ::testing::TestWithParam<int>
{
...
}
```
TEST_P定义和TEST_F类似，第一个参数为类名，第二个参数随意，按需即可
```cpp
TEST_P(TestClass, TestName) {
  int param = GetParam();
  ... statements ...
}
```
然后生成参数：
```cpp
INSTANTIATE_TEST_SUITE_P(Params, TestClass, testing::Values(2, 4, 6, 8));
```
在TEST_P测试用例中，可以使用`GetParam()`获取参数


[**参考文章**](https://blog.csdn.net/chenlong_cxy/article/details/127166206)