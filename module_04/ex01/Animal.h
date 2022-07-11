#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "Brain.h"

class Animal {
  std::string type;
  Brain* brain;

 public:
  Animal();
  Animal(std::string type);
  Animal(const Animal& other);

  Animal& operator=(const Animal& other);

  virtual ~Animal();

  virtual void makeSound() const;

  void setType(std::string new_type);
  std::string getType() const;
  Brain* getBrain() const;

  static void log(const std::string& msg);
};

#endif
