#ifndef DOG_H
#define DOG_H

#include <string>

#include "Animal.h"

class Dog : public Animal {
public:
  Dog();
  Dog(Dog const& other);

  Dog& operator=(Dog const& other);

  ~Dog();

  void makeSound() const;
};

#endif
