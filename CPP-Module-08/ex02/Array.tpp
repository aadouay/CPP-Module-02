#include "Array.hpp"

template <typename T> Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _size(n) {
  _data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(0) {
  // on check si le size est > 0 sinon on dois faire rien !!
  this->_size = other._size;

  if (this->_size > 0) {
    this->_data = new T[other._size];
    for (int i = 0; i < this->_size; i++) {
      this->_data[i] = other._data[i];
    }
  }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
  if (this == other)
    return *this;
  // on doit libérer l'ancienne mémoire
  delete[] this->_data;
  if (this->_size > 0) {
    this->_size = other._size;
    this->_data = new T[this->_size];
    for (int i = 0; i < this->_size; i++)
      this->_data[i] = other._data[i];
  } else {
    this->_data = nullptr;
  }
  return *this;
}

template <typename T> Array<T>::~Array() { delete[] _data; }

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _size)
    throw Array<T>::OutOfBoundsException();
  return _data[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= _size)
    throw Array<T>::OutOfBoundsException();
  return _data[index];
}

template <typename T> unsigned int Array<T>::size() const { return _size; }
