#include "../include/default_params.h"
#include <iostream>

int default_all_params(int length, int width, int height) {
  std::cout << "length = " << length << ", width = " << width
            << ", height = " << height << std::endl;
  return length * width * height;
}

int default_partial_params(int length, int width, int height) {
  std::cout << "length = " << length << ", width = " << width
            << ", height = " << height << std::endl;
  return length * width * height;
}