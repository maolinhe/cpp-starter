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
  }
  case U("static"):
  {
    StaticNamespace::Person person;
    person.printAge();
    cout << "person age = " << person.age << endl;
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
  }
  case U("inner_class"):
  {
    InnerClassSpace::OutClass out;
    InnerClassSpace::OutClass::InnerClass in;
    in.print(out);
  }
  case U("basic_memory_allocation"):
  {
    MemoryManagerSpace::basicMemoryAllocation();
  }
  case U("compare_template_function"):
  {
    cout << TemplateSpace::max(1, 2) << endl;
    cout << TemplateSpace::max(3.5, 2.1) << endl;
    cout << TemplateSpace::max('a', 'A') << endl;
  }
  }

  return 0;
}
