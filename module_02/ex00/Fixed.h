#ifndef FIXED_H
#define FIXED_H

class Fixed {
  int value_;
  static const int Fractional = 8;

public:
  int GetRawBits(void) const;
  void SetRawBits(int const raw);

  Fixed(void);
  Fixed(const Fixed& f);

  Fixed& operator=(const Fixed& f);

  ~Fixed();
};
#endif
