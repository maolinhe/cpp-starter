#include <iostream>
#include "include/namespace_test.h"

using namespace std;

int main() {
  string val = "hello cpp";

  cout << val << endl;
  
  SpaceA::print();
  SpaceA::SpaceAA::print();
}
