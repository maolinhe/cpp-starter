#include <iostream>

namespace SpaceA {
void print() { std::cout << "print namespace A" << std::endl; }

namespace SpaceAA {
void print() { std::cout << "print namespace AA" << std::endl; }
} // namespace SpaceAA
} // namespace SpaceA