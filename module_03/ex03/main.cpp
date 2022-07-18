#include "DiamondTrap.h"

int main(void) {
  DiamondTrap dt("1");
  DiamondTrap dt2(dt);
  DiamondTrap dt3("3");
  dt3 = dt;

  dt.whoAmI();
  dt2.whoAmI();
  dt3.whoAmI();

  dt.attack("target");
  dt2.beRepaired(10);
  dt3.takeDamage(10);

  dt.printStatus();
  dt2.printStatus();
  dt3.printStatus();
}
