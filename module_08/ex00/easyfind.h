#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>

template <class T> void easyfind(T it, int n) {
  typename T::iterator result = std::find(it.begin(), it.end(), n);
  if (result != it.end()) {
    std::cout << "value " << n << " was found" << std::endl;
  }
  throw std::exception();
}

#endif
