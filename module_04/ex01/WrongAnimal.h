#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
  std::string type;

 public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal& other);

  WrongAnimal& operator=(const WrongAnimal& other);

  virtual ~WrongAnimal();

  virtual void makeSound() const;

  void setType(std::string new_type);
  std::string getType() const;

  static void log(const std::string& msg);
};

#endif
