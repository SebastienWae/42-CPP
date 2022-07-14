#include <exception>
#include <iostream>
#include <list>

#include "easyfind.h"

int main(void) {
  std::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);
  try {
    easyfind(lst, 2);
  } catch (std::exception &e) {
    std::cerr << "not found" << std::endl;
  }
}
