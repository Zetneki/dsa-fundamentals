#pragma once

#include <stdexcept>
#include <cstddef>
#include <initializer_list>

template <typename T, size_t N>
class StaticArray {
public:
  StaticArray(std::initializer_list<T> list);
  StaticArray();

  T& operator[](size_t index);
  const T& operator[](size_t index) const;

  size_t size() const;
private:
  T m_data[N]; // fixed-size array to hold the elements
};

#include "StaticArray.ipp"