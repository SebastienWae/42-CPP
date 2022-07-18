#include "WrongAnimal.h"

#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "WrongAnimal: default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
  std::cout << "WrongAnimal: default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other) : type(other.type) {
  std::cout << "WrongAnimal: copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  std::cout << "WrongAnimal: copy constructor" << std::endl;
  type = other.type;
  return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal: destructor" << std::endl; }

void WrongAnimal::makeSound() const { std::cout << "* wrong animal sound *" << std::endl; }

std::string WrongAnimal::getType() const { return type; }
