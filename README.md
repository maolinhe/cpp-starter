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
    - [引用](#引用)
      - [引用的特性](#引用的特性)
      - [常引用](#常引用)
      - [引用的使用场景](#引用的使用场景)
      - [指针和引用的区别](#指针和引用的区别)
    - [内联函数](#内联函数)
      - [内联函数设计的目的](#内联函数设计的目的)
      - [内联函数的缺点](#内联函数的缺点)
      - [内联函数的使用](#内联函数的使用)
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


### 引用
引用是已存在在内存中的变量的一个别名，编译器不会为引用变量开辟内存空间，它和引用的变量公用同一块内存空间

#### 引用的特性
* 引用在定义时必须初始化
* 一个变量可以有多个引用
* 引用一旦绑定了一个实体，就不能再引用其它实体

#### 常引用
常引用是用const修饰的引用，const修饰的实体只能交给const引用
```cpp
int a = 100;
const int &ra = a;

const int ca = 100;
// 常变量不能用普通引用，只能用常引用
// int &rca = ca;
const int &rca = ca;
```
#### 引用的使用场景
* 作为函数参数
* 作为函数的返回值

#### 指针和引用的区别
* 引用比指针更加安全，因为指针可能导致内存泄漏的问题，所以开发中更加推荐使用引用
* 引用需要初始化，指针没有要求
* 引用在引用一个实体之后，不能重新引用其它实体，指针可以在任何时候指向任何一个相同类型的实体
* 不存在NULL引用，但存在NULL指针
* sizeof(引用)：引用类型的大小，sizeof(指针)：指向的地址所占空间的大小，32位下为4字节，64位下为8字节
* 引用自增或自减指的是引用实体的值的自增自减，指针的自增自减指的是地址的自增自减
* 存在多级指针，但没有多级引用
* 访问实体方式不同，引用访问由编译器处理，指针是由开发者显示解引用

### 内联函数
内联函数与普通函数类似，在函数前加上inline就成为内联函数
```cpp
inline void thisIsInlineFunction()
{

}
```
内联函数在编译阶段会把所有调用内联函数的地方替换为函数体
#### 内联函数设计的目的
* 代替部分`#define`宏定义
  
  宏是预处理指令，在预处理的阶段把所有的宏名使用宏体代替，内联函数在编译阶段替换其函数体
  宏的缺点和内联函数的优点
  * 宏没有类型检查，不管对错都直接替换；内联函数在编译时会进行安全检查
  * 宏的编写有限制，比如只能写一行，不能使用流程控制语句，比如return，if else等；内联函数可以使用丰富的流程控制语句
  * 宏无法操作C++类的私有成员
* 提高程序运行效率
  
  普通的函数调用会进行函数的入栈出栈操作，一方面，函数入栈出栈需要消耗大量的时间，函数入栈需要将实参，局部变量以及返回地址等都需要压入栈中，函数执行完成之后需要清理现场；另一方面，程序分配的栈空间是有限的，过多的函数调用可能会导致栈溢出问题
  
  内联函数通过将函数体插入到调用地方，减少了函数的调用次数

#### 内联函数的缺点
内联函数的关键点是替换函数体，这使得重复的代码量会增大，因此尽量保持内联函数的代码行数较少

实际上内联函数只是对编译器在编译过程的建议，具体是否进行内联，需要根据实际情况决定，比较复杂的内联函数比如函数体存在递归或循环，编译器可能会拒绝内联

#### 内联函数的使用
* 显式内联：使用`inline`关键字修饰
  ```cpp
  // 头文件Inline.h
  class Inline
  {
  private:
      int a;
      int b;

  public:
      Inline(int a, int b) : a(a), b(b){};
      int max();
  };
  ```
  
  ```cpp
  // 定义文件Inline.cpp
  #include <iostream>
  #include "../include/Inline.h"

  using namespace std;

  inline int Inline::max()
  {
      return a > b ? a : b;
  }
  ```

* 隐式内联：在c++类中，函数定义直接卸载类声明中，不需要加inline也会成为内联函数
  ```cpp
  class Inline
  {
  private:
      int a;
      int b;

  public:
      Inline(int a, int b) : a(a), b(b){};
      // 无须声明inline
      int max()
      {
        return a > b ? a : b;
      }
  };
  ```

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