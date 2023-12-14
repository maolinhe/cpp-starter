#include <iostream>
#include "include/namespace_test.h"
#include "include/std_input_output.h"
#include "include/default_params.h"

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
    std_input_output();
    break;

  case U("default_params"):
    default_all_params();
    default_partial_params(5);
    break;
  }

  return 0;
}
