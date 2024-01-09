#include "../include/DefaultParams.h"
#include <iostream>

int defaultAllParams(int length, int width, int height) {
  std::cout << "length = " << length << ", width = " << width
            << ", height = " << height << std::endl;
  return length * width * height;
}

int defaultPartialParams(int length, int width, int height) {
  std::cout << "length = " << length << ", width = " << width
            << ", height = " << height << std::endl;
  return length * width * height;
}