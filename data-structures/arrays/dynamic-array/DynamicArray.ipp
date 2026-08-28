#pragma once

template <typename T>
DynamicArray<T>::DynamicArray(): m_size(0), m_capacity(0), m_data(nullptr) {}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  delete[] m_data;
}

// push adds a new element to the end of the array
template <typename T>
void DynamicArray<T>::push(const T &value) {
  if (m_size == m_capacity) resize();
  m_data[m_size++]=value;
}

// pop returns the last element and removes it from the array
template <typename T>
T DynamicArray<T>::pop() {
  if (m_size == 0) throw std::out_of_range("Cannot pop from an empty DynamicArray");

  T value = m_data[--m_size];
  if (m_size <= m_capacity / 4) shrink();

  return value;
}

// set sets the value of the element at the given index
template <typename T>
void DynamicArray<T>::set(size_t index, const T &value) {
  if (index >= m_size) throw std::out_of_range("Index out of range");
  m_data[index] = value;
}

// get returns the value of the element at the given index
template <typename T>
T DynamicArray<T>::get(size_t index) {
  if (index >= m_size) throw std::out_of_range("Index out of range");
  return m_data[index];
}

// operator[] returns or sets the value of the element at the given index
template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
  if (index >= m_size) throw std::out_of_range("Index out of range");
  return m_data[index];
} 

// operator[] returns the value of the element at the given index
template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
  if (index >= m_size) throw std::out_of_range("Index out of range");
  return m_data[index];
}

// size returns the number of elements in the array
template <typename T>
size_t DynamicArray<T>::size() {
  return m_size;
}

// capacity returns the number of elements that can be stored in the array
template <typename T>
size_t DynamicArray<T>::capacity() {
  return m_capacity;
}

// is_empty returns true if the array is empty, false otherwise
template <typename T>
bool DynamicArray<T>::is_empty() {
  return m_size == 0;
}

// resize increases the capacity of the array
template <typename T>
void DynamicArray<T>::resize() {
  if (m_capacity == 0) m_capacity=1;
  else m_capacity *= 2;

  // allocate new memory for the array and copy the old data
  T* resizedArray = new T[m_capacity];

  for (size_t i = 0; i < m_size; i++) 
    resizedArray[i] = m_data[i];

  // delete old array and set new array
  delete[] m_data;
  m_data = resizedArray;
}

// shrink decreases the capacity of the array
template <typename T>
void DynamicArray<T>::shrink() {
  if (m_capacity <= 1) return;
  m_capacity /= 2;

  // allocate new memory for the array and copy the old data
  T* shrunkArray = new T[m_capacity];

  for (size_t i = 0; i < m_size; i++)
    shrunkArray[i] = m_data[i];
  
  // delete old array and set new array
  delete[] m_data;
  m_data = shrunkArray;
}
