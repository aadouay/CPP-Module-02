#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>

class Array {
private:
  T *_data;
  unsigned int _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  ~Array();

  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
  unsigned int size() const;

  class OutOfBoundsException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Index out of bounds"; }
  };
  // ici un methode pour remplir le stock T *_data
  void remplir(T values) {
    for (int i = 0; i < _size; i++) {
      _data[i] = values;
    }
  }
  void print_stock() {
    for (int i = 0; i < _size; i++)
      std::cout << _data[i] << " | ";
  }
};

#include "Array.tpp"

#endif