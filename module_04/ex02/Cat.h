#ifndef CAT_H
#define CAT_H

#include <string>

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
  Brain* brain;

public:
  Cat();
  Cat(Cat const& other);

  Cat& operator=(Cat const& other);

  ~Cat();

  void makeSound() const;

  Brain const* getBrain() const;
};

#endif
