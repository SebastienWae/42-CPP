#include "Fixed.h"
#include <iostream>

Fixed::Fixed(void) : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  setRawBits(f.getRawBits());
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called" << std::endl;
  setRawBits(f.getRawBits());
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value;
}

void Fixed::setRawBits(int const raw) {
  value = raw;
}
