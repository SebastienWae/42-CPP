#include <iostream>
#include <list>
#include <vector>

#include "easyfind.h"

int main(void) {
  {
    std::cout << "### TEST 1 ###" << std::endl;

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    try {
      easyfind(lst, 2);
      easyfind(lst, 10);
    } catch (ElementNotFound &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    std::cout << "### TEST 2 ###" << std::endl;

    std::vector<char> vec;
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');

    try {
      easyfind(vec, 'c');
      easyfind(vec, 'z');
    } catch (ElementNotFound &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
