#include <iostream>

int main() {
  int array[5] = {1, 2, 3};

  std::cout << array[0] << std::endl;
  std::cout << sizeof(array)/sizeof(array[0]) << std::endl;
}