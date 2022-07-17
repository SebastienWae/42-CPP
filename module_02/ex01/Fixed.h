#ifndef FIXED_H
#define FIXED_H

#include <ostream>

class Fixed {
  static int const fractionalBits;
  int value;

public:
  Fixed();
  Fixed(int const value);
  Fixed(float const value);
  Fixed(Fixed const& other);

  ~Fixed();

  Fixed& operator=(Fixed const& other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif
