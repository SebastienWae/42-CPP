#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
  std::string name;

public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

  void announce(void) const;

  void setName(std::string name);

private:
};

#endif
