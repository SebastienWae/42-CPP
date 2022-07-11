#include "WrongCat.h"
#include <iostream>
#include <string>

WrongCat::WrongCat() {
  setType("WrongCat");
  log("wrong cat: default constructor");
}

WrongCat::WrongCat(const WrongCat& other) : Animal(other) {
  log("wrong cat: copy constructor");
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  setType(other.getType());
  log("wrong cat: copy operator");
  return *this;
}

WrongCat::~WrongCat() {
  log("wrong cat: destructor");
}

void WrongCat::makeSound() const {
  std::cout << "mooooo" << std::endl;
}
