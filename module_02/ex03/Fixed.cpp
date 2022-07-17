#include "Fixed.h"

#include <cmath>
#include <iostream>

int const Fixed::fractionalBits = 8;

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(int const value) : value(value << fractionalBits) {}

Fixed::Fixed(float const value) : value(roundf(value * (1 << fractionalBits))) {}

Fixed::Fixed(Fixed const& other) : value(other.value) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(Fixed const& other) {
  value = other.value;
  return *this;
}

bool Fixed::operator>(Fixed const& other) const { return value > other.getRawBits(); }

bool Fixed::operator<(Fixed const& other) const { return value < other.getRawBits(); }

bool Fixed::operator>=(Fixed const& other) const { return value >= other.getRawBits(); }

bool Fixed::operator<=(Fixed const& other) const { return value <= other.getRawBits(); }

bool Fixed::operator==(Fixed const& other) const { return value == other.getRawBits(); }

bool Fixed::operator!=(Fixed const& other) const { return value != other.getRawBits(); }

Fixed Fixed::operator+(Fixed const& other) const {
  Fixed result;

  result.setRawBits(value + other.getRawBits());

  return result;
}

Fixed Fixed::operator-(Fixed const& other) const {
  Fixed result;

  result.setRawBits(value - other.getRawBits());

  return result;
}

Fixed Fixed::operator*(Fixed const& other) const { return Fixed(toFloat() * other.toFloat()); }

Fixed Fixed::operator/(Fixed const& other) const { return Fixed(toFloat() / other.toFloat()); }

// Prefix
Fixed& Fixed::operator++(void) {
  value += 1;
  return *this;
}

// Prefix
Fixed& Fixed::operator--(void) {
  value -= 1;
  return *this;
}

// Postfix
Fixed Fixed::operator++(int) {
  Fixed copy(*this);
  value += 1;
  return copy;
}

// Postfix
Fixed Fixed::operator--(int) {
  Fixed copy(*this);
  value -= 1;
  return copy;
}

int Fixed::getRawBits(void) const { return value; };

void Fixed::setRawBits(int const raw) { value = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(value) / (1 << fractionalBits); }

int Fixed::toInt(void) const { return value / (1 << fractionalBits); }

Fixed& Fixed::min(Fixed& f1, Fixed& f2) { return (f1 < f2) ? f1 : f2; }

Fixed const& Fixed::min(Fixed const& f1, Fixed const& f2) { return (f1 < f2) ? f1 : f2; }

Fixed& Fixed::max(Fixed& f1, Fixed& f2) { return (f1 > f2) ? f1 : f2; }

Fixed const& Fixed::max(Fixed const& f1, Fixed const& f2) { return (f1 > f2) ? f1 : f2; }

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
  os << fixed.toFloat();
  return os;
}
