#include "Fixed.h"

#include <cmath>
#include <iostream>

int const Fixed::fractionalBits = 8;

Fixed::Fixed(void) : value(0) { std::cout << "Default Constructor called" << std::endl; }

Fixed::Fixed(int const value) : value(value << fractionalBits) {
  std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(float const value) : value(roundf(value * (1 << fractionalBits))) {
  std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) : value(other.value) {
  std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(Fixed const& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  value = other.value;
  return *this;
}

int Fixed::getRawBits(void) const { return value; };

void Fixed::setRawBits(int const raw) { value = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(value) / (1 << fractionalBits); }

int Fixed::toInt(void) const { return value / (1 << fractionalBits); }

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
  os << fixed.toFloat();
  return os;
}
