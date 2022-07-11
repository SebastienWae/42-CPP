#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
  int value_;
  static const int Fractional = 8;

public:
  int GetRawBits(void) const;
  void SetRawBits(int const raw);

  float ToFloat(void) const;
  int ToInt(void) const;

  Fixed& operator=(const Fixed& f);

  bool operator>(const Fixed& f) const;
  bool operator<(const Fixed& f) const;
  bool operator>=(const Fixed& f) const;
  bool operator<=(const Fixed& f) const;
  bool operator==(const Fixed& f) const;
  bool operator!=(const Fixed& f) const;

  Fixed operator+(const Fixed& f) const;
  Fixed operator-(const Fixed& f) const;
  Fixed operator*(const Fixed& f) const;
  Fixed operator/(const Fixed& f) const;

  Fixed& operator++();
  Fixed& operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  static Fixed& Min(Fixed& a, Fixed& b);
  static const Fixed& Min(const Fixed& a, const Fixed& b);

  static Fixed& Max(Fixed& a, Fixed& b);
  static const Fixed& Max(const Fixed& a, const Fixed& b);

  Fixed& operator<<(const Fixed& f);

  Fixed();
  Fixed(const int i);
  Fixed(const float f);
  Fixed(const Fixed& f);

  ~Fixed();
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif
