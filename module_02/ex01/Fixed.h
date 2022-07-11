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
  Fixed& operator<<(const Fixed& f);

  Fixed();
  Fixed(const int i);
  Fixed(const float f);
  Fixed(const Fixed& f);

  ~Fixed();
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif
