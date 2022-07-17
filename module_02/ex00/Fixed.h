#ifndef FIXED_H
#define FIXED_H

class Fixed {
  static int const fractionalBits;
  int value;

public:
  Fixed();
  Fixed(Fixed const& other);
  ~Fixed();

  Fixed& operator=(Fixed const& other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
};

#endif
