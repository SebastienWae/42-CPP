#include <iostream>

#include "Fixed.h"

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  a.setRawBits(0b101010);
  std::cout << a.getRawBits() << std::endl;
}
