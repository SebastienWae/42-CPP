#include "Brain.h"

#include <iostream>

Brain::Brain() {
  std::cout << "Brain: defautl constructor" << std::endl;
  for (int i = 0; i < 100; ++i) {
    ideas[i] = "";
  }
}

Brain::Brain(Brain const& other) {
  std::cout << "Brain: copy constructor" << std::endl;
  for (int i = 0; i < 100; ++i) {
    ideas[i] = other.ideas[i];
  }
}

Brain::~Brain() { std::cout << "Brain: destructor" << std::endl; }

Brain& Brain::operator=(Brain const& other) {
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < 100; ++i) {
    ideas[i] = other.ideas[i];
  }
  return *this;
}

std::string const* Brain::getIdeas() const { return ideas; }
