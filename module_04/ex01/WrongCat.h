#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <string>
#include "Animal.h"

class WrongCat : public Animal {
 public:
  WrongCat();
  WrongCat(const WrongCat& other);

  WrongCat& operator=(const WrongCat& other);

  ~WrongCat();

  void makeSound() const;
};

#endif
