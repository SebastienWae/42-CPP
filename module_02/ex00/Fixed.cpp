#include "Fixed.h"

#include <iostream>

int const Fixed::fractionalBits = 8;

Fixed::Fixed(void) : value(0) { std::cout << "Default Constructor called" << std::endl; }

Fixed::Fixed(Fixed const& other) : value(other.value) {
  std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(Fixed const& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  value = other.value;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value;
};

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value = raw;
}
