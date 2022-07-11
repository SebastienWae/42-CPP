#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal() : type("Animal") {
  log("animal: default constructor");
}

Animal::Animal(const Animal& other) : type(other.type) {
  log("animal: copy constructor");
}

Animal& Animal::operator=(const Animal& other) {
  type = other.type;
  log("animal: copy operator");
  return *this;
}

Animal::~Animal() {
  log("animal: destructor");
}

void Animal::makeSound() const {
  std::cout << "* animal sound *" << std::endl;
}

void Animal::setType(std::string new_type) {
  type = new_type;
}

std::string Animal::getType() const {
  return type;
}

void Animal::log(const std::string& msg) {
  std::cout << msg << std::endl;
}
