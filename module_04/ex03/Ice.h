#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria {
public:
  Ice();
  Ice(Ice const& other);

  Ice& operator=(Ice const& other);

  ~Ice();

  virtual Ice* clone() const;
  virtual void use(ICharacter& target);
};

#endif
