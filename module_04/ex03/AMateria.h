#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

class ICharacter;

class AMateria {
protected:
  std::string type;

public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const AMateria& other);

  virtual ~AMateria();

  AMateria& operator=(const AMateria& other);

  std::string const& GetType() const;

  virtual AMateria* Clone() const = 0;
  virtual void Use(ICharacter& target);
};

#endif
