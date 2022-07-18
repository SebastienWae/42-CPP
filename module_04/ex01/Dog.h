#ifndef DOG_H
#define DOG_H

#include <string>

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
  Brain* brain;

public:
  Dog();
  Dog(Dog const& other);

  Dog& operator=(Dog const& other);

  ~Dog();

  void makeSound() const;

  Brain const* getBrain() const;
};

#endif
