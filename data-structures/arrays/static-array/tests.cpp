#include "StaticArray.hpp"
#include <cassert>

void testInitialization() {
  StaticArray<int, 3> arr = {};
  StaticArray<int, 5> arr2 = {1,2,3};
  StaticArray<std::string, 5> arr3 = {"1","2","3","4","5"};

  bool exceptionThrown = false;

  try {
    StaticArray<std::string, 5> arr4 = {"1","2","3","4","5","6"};
  }
  catch (const std::out_of_range&) {
    exceptionThrown = true;
  }
  
  assert(arr.size() == 3 && arr[0] == 0 && arr[1] == 0 && arr[2] == 0);
  assert(arr2.size() == 5 && 
    arr2[0] == 1 && arr2[1] == 2 && arr2[2] == 3 && 
    arr2[3] == 0 &&
    arr2[4] == 0);
  assert(arr3.size() == 5 && 
    arr3[0] == "1" && arr3[1] == "2" && arr3[2] == "3" && 
    arr3[3] == "4" && arr3[4] == "5");
  assert(exceptionThrown);
}

void testOperators() {
  StaticArray<int, 3> arr = {1,2,3};

  assert(arr[0] == 1);
  assert(arr[1] == 2);
  assert(arr[2] == 3);

  arr[0] = 10;

  assert(arr[0] == 10);

  const StaticArray<double, 3> arr2 = {1.2,2.3,3.4};

  assert(arr2[0] == 1.2);
  assert(arr2[1] == 2.3);
  assert(arr2[2] == 3.4);

  bool exceptionThrown = false;

  try {
    arr[3];
  }
  catch (const std::out_of_range&) {
    exceptionThrown = true;
  }

  assert(exceptionThrown);
}

void testSize() {
  StaticArray<int, 3> arr;
  assert(arr.size() == 3);
}

int main () {
  testInitialization();
  testOperators();
  testSize();
}