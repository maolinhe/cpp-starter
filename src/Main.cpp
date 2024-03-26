#include <iostream>
#include "include/Namespace.h"
#include "include/StdInputOutput.h"
#include "include/DefaultParams.h"
#include "include/FunctionOverload.h"
#include "gtest/gtest.h"
#include "include/Reference.h"
#include "include/DefaultConstructionClass.h"
#include "include/CopyConstruction.h"
#include "include/InitialList.h"
#include "include/Static.h"
#include "include/FriendFunction.h"
#include "include/FriendClass.h"
#include "include/InnerClass.h"
#include "include/BasicMemoryAllocation.h"
#include "include/CompareTemplateFunction.h"
#include "include/TemplateClass.h"
#include "include/IOStream.h"
#include "include/ExtentionClass.h"
#include "include/Polymorphic.h"
#include "include/Cpp11.h"
#include "include/Singleton.h"
#include "include/Cast.h"

using namespace std;
using namespace InitialList;

int toUnicode(const char *str)
{
  return str[0] + (str[1] ? toUnicode(str + 1) : 0);
}

constexpr inline int U(const char *str)
{
  return str[0] + (str[1] ? U(str + 1) : 0);
}

int main(int argc, char **argv)
{
  cout << "****************** args count = " << argc
       << "; arg 2 = " << *(argv + 1) << " ******************" << endl;

  switch (toUnicode(argv[1]))
  {
  case U("namespace"):
  {
    SpaceA::print();
    SpaceA::SpaceAA::print();
    break;
  }
  case U("std_input_output"):
  {
    stdInputOutput();
    break;
  }
  case U("default_params"):
  {
    defaultAllParams();
    defaultPartialParams(5);
    break;
  }
  case U("function_overload"):
  {
    FunctionOverload fo;
    fo.fun();
    fo.fun(10);
    fo.fun(10, 20);
    fo.fun(10, "cpp");
    fo.fun("cpp", 10);
    break;
  }
  case U("test_calculation"):
  {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    break;
  }
  case U("reference"):
  {
    Reference ref;
    ref.basicRef();
    ref.constRef();
    ref.testParamAndReturnRef();
    ref.referenceAndPointer();
    break;
  }
  case U("default_construction"):
  {
    Animal animal1;
    cout << "--------------------" << endl;
    string name("www");
    Animal animal2(name);
    break;
  }
  case U("copy_construction"):
  {
    ClassA classA;
    cout << "--------------------" << endl;
    ClassB classB(10, classA);
    cout << "--------------------" << endl;
    ClassB copyClassB(classB);
    cout << "--------------------" << endl;
    ClassC classC;
    ClassC copyClassC(classC);
    copyClassC = classC;
    ClassC copyClassC2 = classC;
    break;
  }
  case U("initial_list"):
  {
    InitialList::T1 t1;
    cout << "--------------------" << endl;
    InitialList::T2 t2(t1);
    cout << "--------------------" << endl;
    InitialList::T3 t3(t1);
    break;
  }
  case U("static"):
  {
    StaticNamespace::Person person;
    person.printAge();
    cout << "person age = " << person.age << endl;
    break;
  }
  case U("friend"):
  {
    FriendSpace::Box box;
    box.setHeight(10);
    box.setWidth(20);
    FriendSpace::printBox(box);
    cout << "--------------------" << endl;
    FriendSpace::FriendBox friendBox(100, 200);
    FriendSpace::MyClass myClass;
    myClass.printBox(friendBox);
    break;
  }
  case U("inner_class"):
  {
    InnerClassSpace::OutClass out;
    InnerClassSpace::OutClass::InnerClass in;
    in.print(out);
    break;
  }
  case U("basic_memory_allocation"):
  {
    MemoryManagerSpace::basicMemoryAllocation();
    break;
  }
  case U("compare_template_function"):
  {
    cout << TemplateSpace::max(1, 2) << endl;
    cout << TemplateSpace::max(3.5, 2.1) << endl;
    cout << TemplateSpace::max<char>('a', 'A') << endl;
    break;
  }
  case U("compare_template_class"):
  {
    TemplateSpace::TemplateClass<int> tc(10);
    cout << tc.getVal() << endl;
    tc.setVal(100);
    cout << tc.getVal() << endl;
    break;
  }
  case U("standard_io_test"):
  {
    cout << "----------ofstream----------" << endl;
    IOSpace::ofstreamTest();
    cout << "----------ifstream----------" << endl;
    IOSpace::ifstreamTest();
    cout << "----------fstream----------" << endl;
    IOSpace::fstreamTest();
    cout << "----------get binary file size----------" << endl;
    IOSpace::getBinarySize();
    cout << "----------test stringstream----------" << endl;
    IOSpace::stringstreamTest();
    break;
  }
  case U("access_of_extention"):
  {
    ExtentionSpace::SubClass1 subClass1;
    ExtentionSpace::SubClass2 subClass2;
    ExtentionSpace::SubClass3 subClass3;

    subClass1.fun();
    subClass2.fun();
    subClass3.fun();
    break;
  }
  case U("deafult_methods_call_of_extention"):
  {
    ExtentionSpace::SubClass4 obj1;
    cout << "---------------------" << endl;
    ExtentionSpace::SubClass4 obj2 = obj1;
    cout << "---------------------" << endl;
    break;
  }
  case U("polymorphic"):
  {
    PolymorphicSpace::Rectangle rectangle(3, 5);
    PolymorphicSpace::Circle cirlce(4);

    PolymorphicSpace::Shape *shape1 = &rectangle;
    shape1->printArea();

    shape1 = &cirlce;
    shape1->printArea();

    PolymorphicSpace::Shape &shape2 = rectangle;
    shape2.printArea();
    break;
  }
  case U("test_cpp11"):
  {
    Cpp11Space::initVar();
    Cpp11Space::autoTest();
    Cpp11Space::nullptrTest();

    // error: conversion from ‘int’ to non-scalar type ‘Cpp11Space::ExplicitTest’ requested
    // Cpp11Space::ExplicitTest et1 = 1;

    Cpp11Space::STLTest();
    Cpp11Space::threadTest();
    Cpp11Space::mutexTest();
    Cpp11Space::uniqueLockTest();
    Cpp11Space::atomicTest();
    Cpp11Space::smartPointerTest();
    break;
  }
  case U("test_singleton"):
  {
    SingletonSpace::HungrySingleton *singleton1 = SingletonSpace::HungrySingleton::getInstance();
    SingletonSpace::LazySingleton *singleton2 = SingletonSpace::LazySingleton::getInstance();
    SingletonSpace::SafeLazySingleton *singleton3 = SingletonSpace::SafeLazySingleton::getInstance();
    break;
  }
  case U("test_cast"):
  {
    CastSpace::testStaticCast();
    CastSpace::testDynamicCast();
    CastSpace::testConstCast();
    break;
  }
  }

  return 0;
}
