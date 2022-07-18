#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <string>

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(WrongCat const& other);

  WrongCat& operator=(WrongCat const& other);

  ~WrongCat();

  void makeSound() const;
};

#endif
