#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.h"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);

  Dog& operator=(const Dog& other);

  ~Dog();

  void makeSound() const;
};

#endif
