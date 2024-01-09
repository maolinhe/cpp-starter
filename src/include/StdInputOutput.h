#include <iostream>

void stdInputOutput()
{
  int val;
  std::cin >> val;
  std::cout << "cout:" << val << std::endl;
  std::cerr << "cerr:" << val << std::endl;
}