#include "Cat.h"

#include <iostream>
#include <string>

#include "Animal.h"

Cat::Cat() : Animal("Cat") { std::cout << "Cat: default constructor" << std::endl; }

Cat::Cat(const Cat& other) : Animal(other) { std::cout << "Cat: copy constructor" << std::endl; }

Cat& Cat::operator=(Cat const& other) {
  std::cout << "Cat: copy operator" << std::endl;
  type = other.type;
  return *this;
}

Cat::~Cat() { std::cout << "Cat: destructor" << std::endl; }

void Cat::makeSound() const { std::cout << "* meow *" << std::endl; }
