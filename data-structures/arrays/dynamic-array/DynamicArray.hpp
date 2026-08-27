#pragma once

template <class T>
class DynamicArray {
public:
  DynamicArray();
  ~DynamicArray();

  void push(const T &value);
  T pop();

  void set(size_t index, const T &value);
  T get(size_t index);

  size_t size();
  size_t capacity();

  bool is_empty();
  
private:
  size_t m_size // number of elements
  size_t m_capacity // number of elements that can be stored
  T* m_data // pointer to the first element
  void resize(); // increases the capacity of the array
};

#include "DynamicArray.tpp"