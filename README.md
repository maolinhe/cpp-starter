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
    - [指针](#指针)
    - [const和static的区别](#const和static的区别)
    - [引用](#引用)
      - [引用的特性](#引用的特性)
      - [常引用](#常引用)
      - [引用的使用场景](#引用的使用场景)
      - [指针和引用的区别](#指针和引用的区别)
    - [内联函数](#内联函数)
      - [内联函数设计的目的](#内联函数设计的目的)
      - [内联函数的缺点](#内联函数的缺点)
      - [内联函数的使用](#内联函数的使用)
  - [面向对象](#面向对象)
    - [类的定义](#类的定义)
    - [类的访问限定符](#类的访问限定符)
    - [类的作用域](#类的作用域)
    - [类的实例化与对象](#类的实例化与对象)
    - [类的对象模型](#类的对象模型)
      - [类对象的存储方式](#类对象的存储方式)
      - [类对象的大小](#类对象的大小)
    - [this指针](#this指针)
      - [this指针特性](#this指针特性)
    - [类的六个默认的成员函数](#类的六个默认的成员函数)
      - [构造函数](#构造函数)
      - [析构函数](#析构函数)
      - [拷贝构造函数](#拷贝构造函数)
      - [赋值运算符=](#赋值运算符)
      - [取地址重载](#取地址重载)
      - [const取地址重载](#const取地址重载)
    - [初始化列表](#初始化列表)
    - [静态成员static](#静态成员static)
      - [访问方式](#访问方式)
    - [友元](#友元)
      - [友元函数](#友元函数)
      - [友元类](#友元类)
      - [友元类使用场景](#友元类使用场景)
    - [内部类](#内部类)
  - [C/C++内存管理](#cc内存管理)
    - [内存区域说明](#内存区域说明)
    - [new和delete](#new和delete)
      - [操作内置类型](#操作内置类型)
      - [操作自定义类型](#操作自定义类型)
    - [operator new和operator delete](#operator-new和operator-delete)
      - [malloc/free和new/delete的区别](#mallocfree和newdelete的区别)
    - [内存泄漏](#内存泄漏)
      - [危害](#危害)
      - [分类](#分类)
      - [如何避免内存泄漏](#如何避免内存泄漏)
      - [*如何一次在堆上申请4G的内存*](#如何一次在堆上申请4g的内存)
  - [模板（template）](#模板template)
    - [泛型编程](#泛型编程)
    - [函数模板](#函数模板)
      - [函数模板原理](#函数模板原理)
      - [函数模板实例化](#函数模板实例化)
      - [函数模板的匹配原则](#函数模板的匹配原则)
    - [类模板](#类模板)
      - [类模板与继承](#类模板与继承)
    - [模板的优缺点](#模板的优缺点)
  - [I/O流](#io流)
    - [标准I/O流](#标准io流)
    - [文件I/O流](#文件io流)
      - [文件流对象](#文件流对象)
      - [文件打开方式](#文件打开方式)
      - [文件读写操作](#文件读写操作)
      - [关闭文件](#关闭文件)
    - [stringstream](#stringstream)
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


### 指针
指针变量的值是另一块内存空间的起始
* 声明指针
  ```cpp
  int a= 10;
  int *pa = &a;
  ```
* 获取指针值
  ```cpp
  int a= 10;
  int *pa = &a;
  cout << *pa << endl;
  ```
* 双重指针：指向指针的指针
  ```cpp
  int a= 10;
  int *pa = &a;
  int *pa = &pa;
  cout << **pa << endl;
  ```
指针可以方便地操作内存，但是容易造成内存泄露的问题，谨慎使用

### const和static的区别
const定义的常量在超出其作用域之后其空间会被释放，而static定义的静态变量是全局的，不会在某个函数执行结束后被释放

### 引用
引用是已存在在内存中的变量的一个别名，编译器不会为引用变量开辟内存空间，它和引用的变量公用同一块内存空间
* const变量只能通过构造函数初始化列表进行
* static变量一般在类的内部声明，类外部定义，定义时不能再添加static关键字
```cpp
class Test {
private:
  const int a; // 只能在构造函数初始化列表中初始化
  static int b; // 在类的实现文件中定义和初始化
  const static int c;
  static const int d;
public: 
  Test() : a(0) {}
  enum {size1 = 100, size2 = 200}
}

int Test::b = 0; // 在类外部定义类的static静态变量
const int Test::c = 0;
const int Test::d = 0;
```

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

## 面向对象
C语言是面向过程编程，C++是面向对象编程。面向对象的两个重要的的概念：**类**和**对象**

### 类的定义
类由`class`关键字声明，后接类名，类名后紧跟着大括号，大括号里面为类体，由成员变量和成员函数组成
```cpp
class MyClass 
{
  // 类体：成员变量和成员函数
}
```
### 类的访问限定符
共有三种类的访问限定符：
* public（公有）
  
  public修饰的类成员在类内和类外都可以访问

* protected（保护）

  类内可以访问，类外不能直接访问

* private（私有）
  
  类内可以访问，类外不能直接访问

Note：
* 类的访问权限从当前访问限定符开始，到下一个限定符出现为止
* class默认的访问限定符为private，结构体struct默认为public（为了兼容C）

### 类的作用域
类定义了一个新的作用域，内中的所有成员都在类的作用域中，在类中，所有成员都可以直接相互访问，在类外，需要使用`::`操作符指明成员属于哪个类域

### 类的实例化与对象
用类类型创建的实体成为类的实例化，创建的实体称为对象
* 类只是声明，有哪些成员变量和成员函数，不会分配内存空间
* 一个类可以实例化多个对象，每一个实例化的对象都会被分配内存空间

### 类的对象模型
#### 类对象的存储方式
每个对象中只保存成员变量，成员函数存放在公共的代码段
#### 类对象的大小
一个类对象的大小就是该类中所有成员变量的大小之和（如果有内存对齐需要把对齐的内存计算进去）

空类没有成员变量，但是编译器为空类分配了一个字节的内存来唯一标识该类（占位）

### this指针
C++编译后给每一个非静态的成员函数都增加了一个隐藏的指针参数`this`，该指针指向当前的对象（当前对象指的是运行的时候调用该函数的对象）在函数体中访问成员变量都通过该指针进行
```cpp
// 编译前
class MyClass
{
public:
  void fun(int val);
}
```
```cpp
// 编译后
class MyClass
{
public:
  void fun(MyClass *this, int val);
}
```
#### this指针特性
* 类型：类类型* const，也即类指针常量
* 只能在成员函数内部使用
* 本质上是成员函数的形参，在调用成员函数时，将对象地址作为实参传递为this形参，对象本身不保存this指针
* this形参是隐藏默认的，不需要开发者主动传递，该过程由编译器完成

### 类的六个默认的成员函数
#### 构造函数
负责完成对象的初始化，函数名与类名完全相同，创建类对象的时候自动调用，在类的声明周期只调用一次
```cpp
class MyClass
{
public:
  MyClass()
  {
    cout << "MyClass construction" << endl;
  }
}
```
特性：
  * 函数名与类名相同
  * 无参
  * 无返回值
  * 支持重载
  * 实例化类对象的时候自动调用（如果没有指定重载的构造函数进行实例化）
  * 如果没有显示定义无参构造函数，编译器就不会再生成默认的构造函数
  * 编译器自动生成的默认构造函数，对于内置的类型成员不作处理，对于自定义的类型成员会在执行自身的构造函数之前去调用他们默认的构造函数(**经测试，自定义的构造函数也会有相同的动作**)
    ```cpp
    class Dog
    {
    public:
        Dog(){
          cout << "Dog construction" << endl;
        }
    };

    class Animal
    {
    private:
        Dog dog;
    public:
        Animal()
        {
          cout << "Dog construction" << endl;
        }
    };

    int main()
    {
      // 此时先调用Dog的构造函数，再调用Animal的构造函数
      Animal animal;
    }
    ```
#### 析构函数
负责完成对象销毁时的清理工作，对象被销毁时会自动调用
* 函数名为类名前加上`~`
* 无参
* 无返回值
* 对象被销毁时，自动调用
* 一个类有且只有一个析构函数
* 没有显式定义，会默认创建
* 不可以重载
* 嵌套对象，先构造的后析构，后构造的先析构
#### 拷贝构造函数
单个形参，是对本类类型的const引用，用于用已经存在的类对象创建新的类对象
```cpp
ClassName(const ClassName &obj)
{
  ...
}

```
* 无返回值
* 它是构造函数的一个重载形式
* 形参只有一个且必须是本类类型的引用
* 没有显式指定，编译器会默认产生
* 默认的拷贝构造函数，对于内置的成员变量完成浅拷贝（值拷贝），对于自定义的类型调用它们本身的拷贝构造函数
* 默认的拷贝构造函数无法完成深拷贝，完成深拷贝需要重写拷贝构造函数
  
#### 赋值运算符=
类重载了赋值运算符=
```cpp
MyClass& MyClass::operator=(const MyClass &obj)
{
  ...
}
```
该函数会将当前对象赋值给另外一个对象时调用，该过程不会实例化新对象
* 有新对象产生，调用拷贝构造函数
* 无新对象产生，调用复制函数

#### 取地址重载
#### const取地址重载

### 初始化列表
用在类的构造函数中，以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个成员变量后面跟一个放在括号中的初始值或表达式
```cpp
class Person
{
private:
  int age;
  string name;
public:
  MyClass(int age, string name) : age(age), name(name){};
}
```
构造函数执行会有两个阶段：初始化阶段和执行阶段
* 初始化阶段会对初始化列表中成员和不在列表中的自定义类型
* 计算阶段会执行函数体
  
特性：
* 每个成员变量在初始化列表只能出现一次
* 引用成员变量、const成员变量和自定义类型成员变量（该类没有构造函数），必须放在初始化列表进行初始化
* **尽量使用初始化列表对成员进行初始化**
  * 对于内置类型，使用初始化列表和构造函数体内进行初始化没有太大差别
  * 对于自定义的类型，使用初始化列表可以提高代码效率：
    * 构造函数体内赋初值，先调用默认构造函数初始化自定义类型的成员，然后再通过，然后再通过重载的=赋值
    * 初始化列表只需要调用一次拷贝构造函数即可
  ```cpp
  class T1
  {
  public:
    T1()
    {
      cout << "T1 construction" <<endl;
    }
    T1(const T1 &t1)
    {
      cout << "T1 copy construction" <<endl;
    }
    T1& operator=(const T1 &t1)
    {
      cout << "T1 operator =" <<endl;
    }
  };

  class T2
  {
  public:
    T1 t1; // 先调用T1的默认构造函数初始化t1
    T2(T1 &t1)
    {
      // 再调用T1的重载=赋值
      this.t1 = t1;
    }
  }

  class T3
  {
    T1 t1;
    T3(T1 &t1) : t1(t1) // 只调用一次T1的拷贝构造函数
    {

    }
  }
  ```
* 成员变量在类中的**声明顺序就是初始化顺序**，与在初始化列表中的先后顺序无关
* 构造函数体对成员赋值叫做赋初值而不是初始化
  * 构造函数体可以多次赋初值
  * 初始化只能有一次

### 静态成员static
用`static`修饰的成员叫静态成员，包括静态成员变量和静态成员函数
* 静态成员被所有的类共享，不属于某个具体的对象
* 静态成员变量必须在类内声明，类外定义（static const int可以直接类内定义），定义时不加`static`关键字
* 静态成员函数没有隐藏的this指针，因此不能访问任何非静态的成员
* 存在`public`、`protected`、`private`关键字修饰
* 静态成员函数可以访问非静态成员，非静态成员函数不可以访问静态成员

#### 访问方式
* 类名::成员名称（函数或变量）
* 对象.成员名称

### 友元
友元可以打破类的封装性，为编程带来便利，但是友元会增加模块之间的耦合度，因此不建议频繁使用

#### 友元函数
友元函数定义在类外部，但是有权限访问类的私有和保护成员。要定义一个类的友元函数，需要在类的内部使用关键字`friend`声明, 并将类的对象作为参数传递进去:
```cpp
namespace FriendSpace
{
    class Box
    {
    private:
        int height;
        int width;

    public:
        void setHeight(int height);
        void setWidth(int width);
        friend void printBox(Box &box);
    };

    void printBox(Box &box);
}
```

#### 友元类
一个类被定义成其它类的友元类，该类可以访问其它类的私有和保护成员。在其它类中使用`friend class className`声明一个类为本类的友元类。
```cpp
#include <iostream>

using namespace std;

namespace FriendSpace
{
    class MyClass;
    class FriendBox
    {
    private:
        int height;
        int width;

    public:
        FriendBox(int height, int width) : height(height), width(width) {}
        friend class MyClass;
    };

    class MyClass
    {
    public:
        void printBox(FriendBox &box)
        {
            cout << "Box width = " << box.width << ", height = " << box.height << endl;
        }
    };
}
```
友元类是单向的，即类A定义为类B的友元类，A可以访问B的私有和保护成员，但是B不是A的友元类，也不能访问A的私有和保护成员。

#### 友元类使用场景
* 类之间需要共享信息，但是不希望公开
* 两个类需要紧密结合实现某个功能
* 需要简化代码提高效率

总之，友元类（包括友元函数）要谨慎使用，因为它会突破类的封装性，增加代码的复杂性，提高模块之间的耦合度。确实需要在外部访问类的私有成员并且无法通过其它手段实现的情况下考虑使用。

### 内部类
一个类定义在另一个类的内部，该类就称为内部类
* 内部类可以定义在外部类的public、protected、private的任何一个区域
* 内部类是外部类的友元，但是外部类不是内部类的友元
* 内部类访问外部类
  * 直接访问外部类的static、枚举，不需要类名或者对象
  * 可以使用外部类对象参数访问外部类的所有成员（友元）
* 外部类大小与内部类无关，内部类是一个独立的类，与外部类无关
```cpp
    class OutClass
    {
    private:
        int id;
        static string name;
        enum Week
        {
            Mon,
            Tue,
            Wed,
            Thu,
            Fri,
            Sat,
            Sun
        };

    public:
        OutClass() : id(10086) {}
        class InnerClass
        {
        public:
            void print(const OutClass &out)
            {
                // 内部类直接访问外部类的static成员和enum成员，借助类对象访问类的所有成员变量（友元）
                Week week1 = Sun;
                cout << "id = " << out.id << ", name = " << name << ", week = " << week1 << endl;
            }
        };
    };

    string OutClass::name = "zhangsan";
```

## C/C++内存管理
操作系统分配内存基本概念：
* 内存空间时连续开辟的
* 当开辟内存空间时，内存分配从低位到高位
* 当往内存存储数据时，是从低位往高位存储
  ```cpp
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
  ```

### 内存区域说明
* **内核空间**：存放操作系统的内核代码，用户（应用层程序）无法直接访问，可以通过系统调用的方式进行访问
* **栈**：用于存放函数执行的参数、非静态的局部变量和返回值等（包括const变量），栈向下增长
* **内存映射段**：非常高效的I/O映射方式，用于装载一个共享的动态内存库。应用层可以通过系统接口创建共享内存，实现进程通信
* **堆**：程序运行时的动态内存分配，向上增长
* **数据段(全局区)**：存储全局数据和静态数据
* **代码段（代码区和常量区）**：存储可执行代码/只读常量
  ![Alt text](img/image-1.png)

### new和delete
#### 操作内置类型
* 申请/释放基本类型
  ```cpp
  int *p = new int;
  delete p;
  ```
* 申请/释放数组
  ```cpp
  int *p = new int[10];
  delete[] p;
  ```
* 申请/释放基本类型并初始化
  ```cpp
  int *p = new int(10);
  delete p;
  ```
* 申请/释放数组并初始化
  ```cpp
  int *p = new int[3]{0, 1, 2};
  delete[] p;
  ```
#### 操作自定义类型
与基本类型类似

### operator new和operator delete
operator new和operator delete是系统提供的全局函数，new和delete底层是调用这两个函数完成内存的分配与回收
* operator new底层通过malloc申请内存，申请成功正常返回，否则抛出异常
* operator delete底层通过free释放内存

#### malloc/free和new/delete的区别
* 相同点：都是从堆上申请内存，并且需要手动释放
* 不同点：
  * malloc和free是函数，new和delete是操作符
  * malloc申请内存需要手动计算大小并当作参数传递进去，new只需要说明类型即可
  * malloc返回void*，需要强转，new不需要
  * malloc申请失败返回NULL，需要判空，new申请失败抛出异常，因此使用new时需要捕获异常
  * malloc申请的空间不会初始化，new可以
  * 对于自定义类对象，malloc/free不会执行构造/析构函数，new会在申请空间成功之后执行类的构造函数，delete会先执行析构函数然后再释放内存

### 内存泄漏
内存泄漏指的是因为代码程序不规范导致申请的内存脱离了控制而无法再次访问，但是又不会被释放
#### 危害
长时间运行的应用程序如果内存泄漏频繁，会导致程序占用内存空间越来越大，系统的内存最终会被消耗殆尽，从而导致程序和系统宕机
#### 分类
* 堆内存泄漏：通过malloc/calloc/realloc/new申请的内存没有被释放
* 系统资源泄漏：程序使用系统分配的资源如socket、文件描述符fd、管道等没有被释放掉
#### 如何避免内存泄漏
* 养成良好的设计编码规范，及时正确释放申请的内存空间
* 采用智能指针
* 出现内存泄漏使用相应的工具排查

#### *如何一次在堆上申请4G的内存*
* 32位下内存最大4G，堆只占2G左右，因此无法申请
* 使用64位平台即可一次性申请4G内存


## 模板（template）
### 泛型编程
泛型编程可以编写与类型无关的通用代码，可以实现代码复用。**模板是泛型编程的基础**

### 函数模板
一个获得两个数的较大值的模板函数
```cpp
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}
```

#### 函数模板原理
在编译阶段，根据传入的实参类型推演生成对应类型的函数以供调用

#### 函数模板实例化
用不同类型的参数使用函数模板称为函数模板的实例化
* 隐式实例化
  让编译器根据传入的实参自动推断出实际类型，一般不会产生类型强制转换
  ```cpp
  max(10.2, 9.3);
  ```
* 显式实例化
  在函数名后面添加<>指定参数类型，当指定的的参数类型与传入的参数类型不一致的时候，编译器会尝试进行强制类型转换
  ```cpp
  max<double>(10.2, 9.3);
  max<int>(10.2, 9.3); // 强制进行类型转换：float -> int
  ```

#### 函数模板的匹配原则
同名的模板函数和非模板函数可以同时存在
* 如果其它条件相同，会优先调用非模板函数，而不是从模板函数实例化一个新的函数
* 如果模板函数可以产生一个更好的函数，就使用模板函数

### 类模板
定义模板类
```cpp
template <typename T>
class TemplateClass
{
private:
    T val;

public:
    TemplateClass(T val) : val(val) {}
    T &getVal()
    {
        return this->val;
    }
};
```
使用模板类
```cpp
TemplateClass<int> tc(10);
cout << tc.getVal() << endl;
tc.setVal(100);
cout << tc.getVal() << endl;
```

#### 类模板与继承
* 父类是一般类，子类为模板类：与一般继承一样
  ```cpp
  template <typename T>
  class TemplateSon1 : public Father
  {
  private:
      T sVal;

  public:
      TemplateSon1(T sVal) : sVal(sVal) {}
      T &getSVal()
      {
          return this->sVal;
      }
  };
  ```
* 父类是模板类，子类是一般类：需指定父类类型
  ```cpp
  class Son : public TemplateFather<double>
  {
  private:
      int sVal;

  public:
      Son(int sVal) : sVal(sVal), TemplateFather<double>(100) {}
      int &getSVal()
      {
          return this->sVal;
      }
  };
  ```
* 父类和子类都是模板类：子类虚拟的类型可以传递到父类
  ```cpp
  template <typename T>
  class TemplateSon2 : public TemplateFather<T>
  {
  private:
      T sVal;

  public:
      TemplateSon2(T sVal) : sVal(sVal) {}
      T &getSVal()
      {
          return this->sVal;
      }
  };
  ```

### 模板的优缺点
* 优点：
  * 代码复用，节省资源，更快地迭代开放，STL标准模板库因此产生
  * 代码更加灵活
* 缺点：
  * 代码膨胀，编译时间长
  * 模板编译错误时，错误信息凌乱，不易定位


## I/O流
### 标准I/O流
* 标准输出流：ostream
  * cout、cerr、clog
  * 标准文件输出流：ofstream
  * 标准字符输出流：ostringstream
* 标准输入流istream
  * cin
  * 标准文件输入流：ifstream
  * 标准字符输入流：istringstream
* 通用的输入/输出流：iostream
  * 文件输入/输出：fstream
  * 字符输入/输出：stringstream

  
### 文件I/O流
#### 文件流对象
* ofstream：只写
  ```cpp
  void ofstreamTest()
  {
      ofstream ofs("../data/input.txt");
      if (ofs.is_open())
      {
          ofs << "Hello, cpp\n";
          ofs << "Hello world\n";
          ofs.close();
          clog << "Write ok!" << endl;
      }
      else
      {
          cerr << "File open failed" << endl;
      }
  }
  ```
* ifstream：只读
  ```cpp
  void ifstreamTest()
  {
      ifstream ifs("../data/input.txt");
      char buffer[1024];
      if (ifs.is_open())
      {
          while (!ifs.eof())
          {
              /* 第二个参数为最大读取长度 */
              ifs.getline(buffer, 100);
              cout << buffer << endl;
          }
      }
      else
      {
          cerr << "File open failed" << endl;
      }
  }
  ```
* fstream：可读可写
  ```cpp
  void fstreamTest()
  {
      fstream ifs("../data/input.txt", ios::in | ios::binary);
      fstream ofs("../data/input.txt", ios::out | ios::binary);
      char buffer[1024];
      if (ifs.is_open() && ofs.is_open())
      {
          while (!ifs.eof())
          {
              ifs.getline(buffer, 100);
              cout << buffer << endl;
          }
          ifs.close();

          ofs << "Hello, fstream\n";
          ofs.sync();// 同步缓存
          ofs.close();
      }
      else
      {
          cerr << "File open failed" << endl;
      }
  }
  ```

#### 文件打开方式
形如`ios::xxx`
* `ios::in`: 以读方式打开
* `ios::out`: 以写方式打开
* `ios::binary`: 以二进制方式对文件进行操作
* `ios::ate`: 从文件末尾开始输出
* `ios::app`: 以追加方式写文件
* `ios::trunc`: 先清空文件内容再打开文件

#### 文件读写操作
* `put`：插入一个字符
* `write`：插入一段字符
* `get`：提取一个字符
* `read`：提取多个字符
* `tellg`：获得当前字符在文件中位置
* `seekg`：设置对文件进行操作的位置
* `>>`：运算符重载，输入
* `<<`：运算符重载，输出
  
获取二进制文件字节数：
```cpp
long getBinarySize()
{
    fstream ifs("../data/input.txt", ios::in | ios::binary);

    // 获取起始位置
    long start = ifs.tellg();
    // 将游标滑倒文件末尾位置
    ifs.seekg(0, ios::end);
    // 获取文件末尾位置
    long end = ifs.tellg();
    ifs.close();

    long size = end - start;
    cout << "File size is " << size << " bytes" << endl;
    return size;
}
```

#### 关闭文件
使用`close()`函数关闭流。使用完流记得要关闭

### stringstream
* 其它数据类型转换为字符串类型
* 字符串拼接
  ```cpp
  void stringstreamTest()
  {
      int val = 10086;
      string str;

      // 将int转为string
      stringstream ss;
      ss << val;
      ss >> str;
      cout << str << endl;

      // 拼接字符串
      ss.clear(); // 不会清空流中内容，只是重置了流的状态标志
      ss.str(""); // 清除流中内容
      ss << "Hello"
          << ", "
          << "cpp" << endl;
      cout << ss.str();
  }
  ```

## 单元测试-googletest
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

### SetUp and TearDown函数
* SetUpTestCase()
  在测试类的构造函数之后和第一个测试用例之前执行

* SetUp()
  在每一个测试用例执行之前执行，TEST宏不生效

* TearDownTestCase()
  在最后一个测试用例之后和测试类的析构函数之前执行，TEST宏不生效

* TearDown()
  在每一个测试用例执行之后执行，TEST宏不生效

### 测试用例宏
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