#include "WrongAnimal.h"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  log("wrong animal: default constructor");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
  log("wrong animal: copy constructor");
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  type = other.type;
  log("wrong animal: copy operator");
  return *this;
}

WrongAnimal::~WrongAnimal() {
  log("wrong animal: destructor");
}

void WrongAnimal::makeSound() const {
  std::cout << "* wrong animal sound *" << std::endl;
}

void WrongAnimal::setType(std::string new_type) {
  type = new_type;
}

std::string WrongAnimal::getType() const {
  return type;
}

void WrongAnimal::log(const std::string& msg) {
  std::cout << msg << std::endl;
}
