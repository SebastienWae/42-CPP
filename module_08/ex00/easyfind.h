#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <iostream>

class ElementNotFound : public std::exception {
public:
  virtual const char* what() const throw() { return "Element not found"; }
};

template <class T> void easyfind(T container, int n) {
  typename T::iterator iterator = std::find(container.begin(), container.end(), n);
  if (iterator != container.end()) {
    std::cout << "value " << *iterator << " was found" << std::endl;
    return;
  }
  throw ElementNotFound();
}

#endif
