#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(WrongAnimal const& other);

  WrongAnimal& operator=(WrongAnimal const& other);

  ~WrongAnimal();

  void makeSound() const;

  std::string getType() const;
};

#endif
