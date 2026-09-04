#include <iostream>
#include "StaticArray.hpp"

int main() {
  int array[5] = {1, 2, 3};

  std::cout << array[0] << std::endl;
  std::cout << sizeof(array)/sizeof(array[0]) << std::endl;

  StaticArray<int, 5> staticArray;

  staticArray[0] = 10;

  for (size_t i = 0; i < staticArray.size(); i++) {
    std::cout << staticArray[i];
    if (i == staticArray.size() - 1) std::cout << std::endl;
    else std::cout << ", ";
  }

  StaticArray<int, 5> pelda = {1, 2, 3};
  std::cout << pelda.size() << std::endl;
  for (size_t i = 0; i < pelda.size(); i++) {
    std::cout << pelda[i];
    if (i == pelda.size() - 1) std::cout << std::endl;
    else std::cout << ", ";
  }
}