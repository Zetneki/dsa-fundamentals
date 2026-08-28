#include "DynamicArray.hpp"
#include <cassert>

void testPush() {
  DynamicArray<int> array;
  
  array.push(10);
  array.push(20);
  array.push(30);

  assert(array.size() == 3);
  assert(array[0] == 10);
  assert(array[1] == 20);
  assert(array[2] == 30);
}

void testPop() {
  DynamicArray<int> array;

  array.push(10);
  array.push(20);

  int value = array.pop();

  assert(value == 20);
  assert(array.size() == 1);
  assert(array[0] == 10);
}

void testResize() {
  DynamicArray<int> array;

  for (int i = 0; i < 100; i++) {
    array.push(i);
  }

  assert(array.size() == 100);

  for (int i = 0; i < 100; i++) {
    assert(array[i] == i);
  }
}

void testShrink() {
  DynamicArray<int> array;

  for (int i = 0; i < 100; i++) {
    array.push(i);
  }
  assert(array.size() == 100 && array.size() <= array.capacity());

  size_t tempCapacity = array.capacity();

  for (int i = 0; i < 80; i++) {
    array.pop();
  }
  assert(array.size() == 20 && array.capacity() < tempCapacity);
}

void testGetSet() {
  DynamicArray<int> array;

  array.push(10);

  assert(array[0] == 10);

  array[0] = 100;

  assert(array[0] == 100);

  array.set(0, 200);
  assert(array.get(0) == 200);
}

int main() {
  testPush();
  testPop();
  testResize();
  testShrink();
  testGetSet();
}