#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal() : type("Animal"), brain(new Brain) {
  log("animal: default constructor");
}

Animal::Animal(const Animal& other) : type(other.type) {
  brain = new Brain(*other.brain);
  log("animal: copy constructor");
}

Animal& Animal::operator=(const Animal& other) {
  if (this == &other) {
    return *this;
  }
  type = other.type;
  *brain = *other.brain;
  log("animal: copy operator");
  return *this;
}

Animal::~Animal() {
  delete brain;
  log("animal: destructor");
}

void Animal::setType(std::string new_type) {
  type = new_type;
}

std::string Animal::getType() const {
  return type;
}

Brain* Animal::getBrain() const {
  return brain;
}

void Animal::log(const std::string& msg) {
  std::cout << msg << std::endl;
}
