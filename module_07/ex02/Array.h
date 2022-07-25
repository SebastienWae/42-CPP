#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>
#include <stdexcept>

template <typename T> class Array {
  T* elements;
  std::size_t len;

public:
  Array() : elements(new T[0]), len(0){};

  Array(unsigned int n) : elements(new T[n]), len(n) {
    for (std::size_t i = 0; i < n; ++i) {
      elements[i] = T();
    }
  };

  Array(Array<T> const& other) : elements(new T[other.len]), len(other.len) {
    for (std::size_t i = 0; i < len; ++i) {
      elements[i] = T(other[i]);
    }
  }

  Array<T>& operator=(Array<T> const& other) {
    if (this == &other) {
      return *this;
    }
    delete[] elements;
    len = other.len;
    elements = new T[len];
    for (std::size_t i = 0; i < len; ++i) {
      elements[i] = T(other[i]);
    }
    return *this;
  }

  T& operator[](std::size_t index) throw(std::exception) {
    if (index >= len) {
      throw std::exception();
    }
    return elements[index];
  }

  T const& operator[](std::size_t index) const throw(std::exception) {
    if (index >= len) {
      throw std::exception();
    }
    return elements[index];
  }

  std::size_t size() const { return len; }
};

#endif
