#include "Dog.h"
#include <iostream>
#include <string>

Dog::Dog() {
  setType("Dog");
  log("dog: default constructor");
}

Dog::Dog(const Dog& other) : Animal(other) {
  log("dog: copy constructor");
}

Dog& Dog::operator=(const Dog& other) {
  setType(other.getType());
  log("dog: copy operator");
  return *this;
}

Dog::~Dog() {
  log("dog: destructor");
}

void Dog::makeSound() const {
  std::cout << "woof" << std::endl;
}
