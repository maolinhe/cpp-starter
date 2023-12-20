#include <iostream>
#include "include/Namespace.h"
#include "include/StdInputOutput.h"
#include "include/DefaultParams.h"
#include "include/FunctionOverload.h"
#include "gtest/gtest.h"
#include "include/Reference.h"

using namespace std;

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
    SpaceA::print();
    SpaceA::SpaceAA::print();
    break;

  case U("std_input_output"):
    stdInputOutput();
    break;

  case U("default_params"):
    defaultAllParams();
    defaultPartialParams(5);
    break;

  case U("function_overload"):
    FunctionOverload fo;
    fo.fun();
    fo.fun(10);
    fo.fun(10, 20);
    fo.fun(10, "cpp");
    fo.fun("cpp", 10);
    break;
  case U("test_calculation"):
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    break;
  case U("reference"):
    Reference ref;
    ref.basicRef();
    ref.constRef();
    ref.testParamAndReturnRef();
    ref.referenceAndPointer();
    break;
  }

  return 0;
}
