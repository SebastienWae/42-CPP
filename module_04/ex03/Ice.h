#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice& other);

  Ice& operator=(const Ice& other);

  ~Ice();

  virtual Ice* Clone() const;
  virtual void Use(ICharacter& target);
};

#endif
