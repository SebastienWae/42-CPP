#include "WrongCat.h"

#include <iostream>
#include <string>

#include "WrongAnimal.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat: default constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other) {
  std::cout << "WrongCat: copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  (void)other;
  std::cout << "WrongCat: copy operator" << std::endl;
  return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat: destructor" << std::endl; }

void WrongCat::makeSound() const { std::cout << "* mooooo *" << std::endl; }
