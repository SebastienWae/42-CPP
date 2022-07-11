#include <limits>

#include "ClapTrap.h"

int main(void) {
  ClapTrap c1("c1");
  ClapTrap c2(c1);
  ClapTrap c3 = c2;

  c1.Attack("target 1");
  c1.Attack("");

  c1.TakeDamage(9);

  c1.BeRepaird(2);

  c1.BeRepaird(std::numeric_limits<unsigned int>::min());
  c1.BeRepaird(std::numeric_limits<unsigned int>::max());

  c1.Attack("target 1");
  c1.Attack("target 2");
  c1.Attack("target 1");
  c1.Attack("target 2");
  c1.Attack("target 1");

  c1.Attack("target 1");
  c1.BeRepaird(10);

  c1.TakeDamage(9);
  c1.TakeDamage(std::numeric_limits<unsigned int>::max());
  c1.TakeDamage(1);

  c2.TakeDamage(std::numeric_limits<unsigned int>::min());
  c3.TakeDamage(std::numeric_limits<unsigned int>::max());
}
