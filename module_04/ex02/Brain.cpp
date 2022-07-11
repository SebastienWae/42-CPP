#include "Brain.h"
#include <iostream>

Brain::Brain() {
  for (int i = 0; i < IDEAS_N; ++i) {
    ideas[i] = "idea";
  }
  std::cout << "brain: default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
  for (int i = 0; i < IDEAS_N; ++i) {
    ideas[i] = other.ideas[i];
  }

  std::cout << "brain: copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  if (this == &other) {
    return *this;
  }

  for (int i = 0; i < IDEAS_N; ++i) {
    ideas[i] = other.ideas[i];
  }

  std::cout << "brain: copy operator" << std::endl;
  return *this;
}

Brain::~Brain() {
  std::cout << "brain: destructor" << std::endl;
}

std::string const* Brain::getIdeas(void) const {
  return &ideas[0];
}
