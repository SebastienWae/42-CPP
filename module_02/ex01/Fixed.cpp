#include "Fixed.h"

#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed(void) : value_(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int i) {
  std::cout << "Int constructor called" << std::endl;
  SetRawBits(i << Fractional);
}

Fixed::Fixed(const float f) {
  std::cout << "Float constructor called" << std::endl;
  SetRawBits(round(f * (1 << Fractional)));
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  SetRawBits(f.GetRawBits());
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float Fixed::ToFloat(void) const { return static_cast<float>(GetRawBits()) / (1 << Fractional); }

int Fixed::ToInt(void) const { return GetRawBits() / (1 << Fractional); }

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called" << std::endl;
  SetRawBits(f.GetRawBits());
  return *this;
}

int Fixed::GetRawBits(void) const { return value_; }

void Fixed::SetRawBits(int const raw) { value_ = raw; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
  ostream << fixed.ToFloat();
  return ostream;
}
