#ifndef FIXED_H
#define FIXED_H

class Fixed {
  int value;
  static const int fractional = 8;

 public:
  int getRawBits(void) const;
  void setRawBits(int const raw);

  Fixed& operator=(const Fixed& f);

  Fixed(void);
  Fixed(const Fixed& f);

  ~Fixed();
};
#endif
