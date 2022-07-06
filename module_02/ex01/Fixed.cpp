#include "Fixed.h"
#include <__tuple>
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed(void) : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
  std::cout << "Int constructor called" << std::endl;
  setRawBits(i << fractional);
}

Fixed::Fixed(const float f) {
  std::cout << "Float constructor called" << std::endl;
  setRawBits(round(f * (1 << fractional)));
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  setRawBits(f.getRawBits());
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (1 << fractional);
}

int Fixed::toInt(void) const {
  return getRawBits() / (1 << fractional);
}

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called" << std::endl;
  setRawBits(f.getRawBits());
  return *this;
}

int Fixed::getRawBits(void) const {
  return value;
}

void Fixed::setRawBits(int const raw) {
  value = raw;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
  ostream << fixed.toFloat();
  return ostream;
}
