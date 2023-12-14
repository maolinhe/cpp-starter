#include <iostream>

void std_input_output()
{
  int val;
  std::cin >> val;
  std::cout << "cout:" << val << std::endl;
  std::cerr << "cerr:" << val << std::endl;
}