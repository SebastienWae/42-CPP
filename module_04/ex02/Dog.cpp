#include "Dog.h"

#include <iostream>
#include <string>

#include "Animal.h"
#include "Brain.h"

Dog::Dog() : Animal("Dog"), brain(new Brain) {
  std::cout << "Dog: default constructor" << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Dog: copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << "Dog: copy operator" << std::endl;
  if (&other == this) {
    return *this;
  }
  *brain = *other.brain;
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog: destructor" << std::endl;
  delete brain;
}

void Dog::makeSound() const { std::cout << "* woof *" << std::endl; }

Brain const* Dog::getBrain() const { return brain; }
