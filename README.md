# Beginner of cpp

[TOC]

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