#pragma once

// constructor initializes the array with the given initializer list
// it fills the array with 0s if the initializer list is smaller than the array size
template <typename T, size_t N>
StaticArray<T, N>::StaticArray(std::initializer_list<T> list) {
  if (list.size() > N) throw std::out_of_range("Initializer list size exceeds array size");

  for (size_t i = 0; i < N; i++) {
    if (i < list.size()) m_data[i] = *(list.begin()+i);
    else m_data[i] = T();
  }
}

// default constructor initializes the array with 0s
template <typename T, size_t N>
StaticArray<T, N>::StaticArray() {
  for (size_t i = 0; i < N; i++) m_data[i] = T();
}

// operator[] returns or sets the value of the element at the given index
template <typename T, size_t N>
T& StaticArray<T, N>::operator[](size_t index) {
  if (index >= N) throw std::out_of_range("Index out of range");
  return m_data[index];
}

// operator[] returns the value of the element at the given index
template <typename T, size_t N>
const T& StaticArray<T, N>::operator[](size_t index) const {
  if (index >= N) throw std::out_of_range("Index out of range");
  return m_data[index];
}

// size returns the number of elements in the array
template <typename T, size_t N>
size_t StaticArray<T, N>::size() const {
  return N;
}