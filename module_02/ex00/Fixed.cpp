#include "Fixed.h"

#include <iostream>

Fixed::Fixed() : value_(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  SetRawBits(f.GetRawBits());
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called" << std::endl;
  SetRawBits(f.GetRawBits());
  return *this;
}

int Fixed::GetRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void Fixed::SetRawBits(int const raw) { value_ = raw; }
