#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(WrongAnimal const& other);

  WrongAnimal& operator=(WrongAnimal const& other);

  virtual ~WrongAnimal();

  virtual void makeSound() const;

  std::string getType() const;
};

#endif
