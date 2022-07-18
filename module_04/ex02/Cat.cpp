#include "Cat.h"

#include <iostream>
#include <string>

#include "Animal.h"
#include "Brain.h"

Cat::Cat() : Animal("Cat"), brain(new Brain) {
  std::cout << "Cat: default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Cat: copy constructor" << std::endl;
}

Cat& Cat::operator=(Cat const& other) {
  std::cout << "Cat: copy operator" << std::endl;
  if (&other == this) {
    return *this;
  }
  *brain = *other.brain;
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat: destructor" << std::endl;
  delete brain;
}

void Cat::makeSound() const { std::cout << "* meow *" << std::endl; }

Brain const* Cat::getBrain() const { return brain; }
