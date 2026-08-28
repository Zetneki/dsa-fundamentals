#include <iostream>
#include "DynamicArray.hpp"

int main() {

  DynamicArray<int> array;

  array.push(10);
  array.push(20);
  array.push(30);

  std::cout << array[0] << std::endl;

  array[0] = 100;

  std::cout << array[0] << std::endl;
}