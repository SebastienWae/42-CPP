#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
  std::string type;

 public:
  Animal();
  Animal(std::string type);
  Animal(const Animal& other);

  Animal& operator=(const Animal& other);

  virtual ~Animal();

  virtual void makeSound() const;

  void setType(std::string new_type);
  std::string getType() const;

  static void log(const std::string& msg);
};

#endif
