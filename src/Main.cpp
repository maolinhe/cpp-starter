#include <iostream>
#include "include/Namespace.h"
#include "include/StdInputOutput.h"
#include "include/DefaultParams.h"

using namespace std;

int toUnicode(const char *str) {
  return str[0] + (str[1] ? toUnicode(str + 1) : 0);
}

constexpr inline int U(const char *str) {
  return str[0] + (str[1] ? U(str + 1) : 0);
}

int main(int argc, char *argv[]) {
  cout << "****************** args count = " << argc
       << "; arg 2 = " << *(argv + 1) << " ******************" << endl;

  switch (toUnicode(argv[1])) {
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
  }

  return 0;
}
