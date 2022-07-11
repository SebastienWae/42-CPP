#include "DiamondTrap.h"

int main(void) {
  DiamondTrap dt("1");
  DiamondTrap dt2(dt);
  DiamondTrap dt3("3");
  dt3 = dt;

  dt.WhoAmI();
  dt2.WhoAmI();
  dt3.WhoAmI();

  dt.Attack("target");
  dt2.BeRepaired(10);
  dt3.TakeDamage(10);

  dt.PrintStatus();
  dt2.PrintStatus();
  dt3.PrintStatus();
}
