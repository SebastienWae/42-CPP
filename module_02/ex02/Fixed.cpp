#include "Fixed.h"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : value_(0) {}

Fixed::Fixed(const int i) { SetRawBits(i << Fractional); }

Fixed::Fixed(const float f) { SetRawBits(round(f * (1 << Fractional))); }

Fixed::Fixed(const Fixed& f) { SetRawBits(f.GetRawBits()); }

Fixed::~Fixed() {}

float Fixed::ToFloat(void) const { return static_cast<float>(GetRawBits()) / (1 << Fractional); }

int Fixed::ToInt(void) const { return GetRawBits() / (1 << Fractional); }

int Fixed::GetRawBits(void) const { return value_; }

void Fixed::SetRawBits(int const raw) { value_ = raw; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
  ostream << fixed.ToFloat();
  return ostream;
}

Fixed& Fixed::operator=(const Fixed& f) {
  SetRawBits(f.GetRawBits());
  return *this;
}

bool Fixed::operator>(const Fixed& f) const { return GetRawBits() > f.GetRawBits(); }

bool Fixed::operator<(const Fixed& f) const { return GetRawBits() < f.GetRawBits(); }

bool Fixed::operator>=(const Fixed& f) const { return GetRawBits() >= f.GetRawBits(); }

bool Fixed::operator<=(const Fixed& f) const { return GetRawBits() <= f.GetRawBits(); }

bool Fixed::operator==(const Fixed& f) const { return GetRawBits() == f.GetRawBits(); }

bool Fixed::operator!=(const Fixed& f) const { return GetRawBits() != f.GetRawBits(); }

Fixed Fixed::operator+(const Fixed& f) const {
  Fixed result(ToFloat() + f.ToFloat());
  return result;
}

Fixed Fixed::operator-(const Fixed& f) const {
  Fixed result(ToFloat() - f.ToFloat());
  return result;
}

Fixed Fixed::operator*(const Fixed& f) const {
  Fixed result(ToFloat() * f.ToFloat());
  return result;
}

Fixed Fixed::operator/(const Fixed& f) const {
  Fixed result(ToFloat() / f.ToFloat());
  return result;
}

Fixed& Fixed::operator++() {
  SetRawBits(GetRawBits() + 1);
  return *this;
}

Fixed& Fixed::operator--() {
  SetRawBits(GetRawBits() - 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed copy = *this;
  SetRawBits(GetRawBits() + 1);
  return copy;
}

Fixed Fixed::operator--(int) {
  Fixed copy = *this;
  SetRawBits(GetRawBits() - 1);
  return copy;
}

const Fixed& Fixed::Min(const Fixed& a, const Fixed& b) {
  return Fixed::Min(const_cast<Fixed&>(a), const_cast<Fixed&>(b));
}

Fixed& Fixed::Min(Fixed& a, Fixed& b) {
  if (a.GetRawBits() <= b.GetRawBits()) {
    return a;
  }
  return b;
}

const Fixed& Fixed::Max(const Fixed& a, const Fixed& b) {
  return Fixed::Max(const_cast<Fixed&>(a), const_cast<Fixed&>(b));
}

Fixed& Fixed::Max(Fixed& a, Fixed& b) {
  if (a.GetRawBits() >= b.GetRawBits()) {
    return a;
  }
  return b;
}
