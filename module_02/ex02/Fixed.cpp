#include "Fixed.h"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const int i) {
  setRawBits(i << fractional);
}

Fixed::Fixed(const float f) {
  setRawBits(round(f * (1 << fractional)));
}

Fixed::Fixed(const Fixed& f) {
  setRawBits(f.getRawBits());
}

Fixed::~Fixed() {}

float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (1 << fractional);
}

int Fixed::toInt(void) const {
  return getRawBits() / (1 << fractional);
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

Fixed& Fixed::operator=(const Fixed& f) {
  setRawBits(f.getRawBits());
  return *this;
}

bool Fixed::operator>(const Fixed& f) const {
  return getRawBits() > f.getRawBits();
}

bool Fixed::operator<(const Fixed& f) const {
  return getRawBits() < f.getRawBits();
}

bool Fixed::operator>=(const Fixed& f) const {
  return getRawBits() >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed& f) const {
  return getRawBits() <= f.getRawBits();
}

bool Fixed::operator==(const Fixed& f) const {
  return getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed& f) const {
  return getRawBits() != f.getRawBits();
}

Fixed Fixed::operator+(const Fixed& f) const {
  Fixed result(toFloat() + f.toFloat());
  return result;
}

Fixed Fixed::operator-(const Fixed& f) const {
  Fixed result(toFloat() - f.toFloat());
  return result;
}

Fixed Fixed::operator*(const Fixed& f) const {
  Fixed result(toFloat() * f.toFloat());
  return result;
}

Fixed Fixed::operator/(const Fixed& f) const {
  Fixed result(toFloat() / f.toFloat());
  return result;
}

Fixed& Fixed::operator++() {
  setRawBits(getRawBits() + 1);
  return *this;
}

Fixed& Fixed::operator--() {
  setRawBits(getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed copy = *this;
  setRawBits(getRawBits() + 1);
  return copy;
}

Fixed Fixed::operator--(int) {
  Fixed copy = *this;
  setRawBits(getRawBits() - 1);
  return copy;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return Fixed::min(const_cast<Fixed&>(a), const_cast<Fixed&>(b));
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  if (a.getRawBits() <= b.getRawBits()) {
    return a;
  }
  return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return Fixed::max(const_cast<Fixed&>(a), const_cast<Fixed&>(b));
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  if (a.getRawBits() >= b.getRawBits()) {
    return a;
  }
  return b;
}
