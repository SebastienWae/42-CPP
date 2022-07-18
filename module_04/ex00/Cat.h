#ifndef CAT_H
#define CAT_H

#include <string>

#include "Animal.h"

class Cat : public Animal {
public:
  Cat();
  Cat(Cat const& other);

  Cat& operator=(Cat const& other);

  ~Cat();

  void makeSound() const;
};

#endif
