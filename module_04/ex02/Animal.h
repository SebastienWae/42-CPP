#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
  std::string type;

public:
  Animal();
  Animal(std::string type);
  Animal(Animal const& other);

  Animal& operator=(Animal const& other);

  virtual ~Animal();

  virtual void makeSound() const = 0;

  std::string getType() const;
};

#endif
