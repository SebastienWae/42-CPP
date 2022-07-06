#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
  int value;
  static const int fractional = 8;

 public:
  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

  Fixed& operator=(const Fixed& f);
  Fixed& operator<<(const Fixed& f);

  Fixed(void);
  Fixed(const int i);
  Fixed(const float f);
  Fixed(const Fixed& f);

  ~Fixed();
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif
