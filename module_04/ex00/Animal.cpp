#include "Animal.h"

#include <iostream>
#include <string>

Animal::Animal() : type("Animal") { std::cout << "Animal: default constructor" << std::endl; }

Animal::Animal(std::string type) : type(type) {
  std::cout << "Animal: type constructor" << std::endl;
}

Animal::Animal(Animal const& other) : type(other.type) {
  std::cout << "Animal: copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  std::cout << "Animal: copy constructor" << std::endl;
  type = other.type;
  return *this;
}

Animal::~Animal() { std::cout << "Animal: destructor" << std::endl; }

void Animal::makeSound() const { std::cout << "* animal sound *" << std::endl; }

std::string Animal::getType() const { return type; }
