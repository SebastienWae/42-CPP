#include "Dog.h"

#include <iostream>
#include <string>

#include "Animal.h"

Dog::Dog() : Animal("Dog") { std::cout << "Dog: default constructor" << std::endl; }

Dog::Dog(Dog const& other) : Animal(other) { std::cout << "Dog: copy constructor" << std::endl; }

Dog& Dog::operator=(const Dog& other) {
  std::cout << "Dog: copy operator" << std::endl;
  type = other.type;
  return *this;
}

Dog::~Dog() { std::cout << "Dog: destructor" << std::endl; }

void Dog::makeSound() const { std::cout << "* woof *" << std::endl; }
