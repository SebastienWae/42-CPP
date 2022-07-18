#include <limits>

#include "ClapTrap.h"

int main(void) {
  ClapTrap c1("c1");
  ClapTrap c2(c1);
  ClapTrap c3 = c2;

  c1.attack("target 1");
  c1.attack("");

  c1.takeDamage(9);

  c1.beRepaired(2);

  c1.beRepaired(std::numeric_limits<unsigned int>::min());
  c1.beRepaired(std::numeric_limits<unsigned int>::max());

  c1.attack("target 1");
  c1.attack("target 2");
  c1.attack("target 1");
  c1.attack("target 2");
  c1.attack("target 1");

  c1.attack("target 1");
  c1.beRepaired(10);

  c1.takeDamage(9);
  c1.takeDamage(std::numeric_limits<unsigned int>::max());
  c1.takeDamage(1);

  c2.takeDamage(std::numeric_limits<unsigned int>::min());
  c3.takeDamage(std::numeric_limits<unsigned int>::max());
}
