#include "Cat.h"
#include <iostream>
#include <string>

Cat::Cat() {
  setType("Cat");
  log("cat: default constructor");
}

Cat::Cat(const Cat& other) : Animal(other) {
  log("cat: copy constructor");
}

Cat& Cat::operator=(const Cat& other) {
  setType(other.getType());
  log("cat: copy operator");
  return *this;
}

Cat::~Cat() {
  log("cat :destructor");
}

void Cat::makeSound() const {
  std::cout << "meow" << std::endl;
}
