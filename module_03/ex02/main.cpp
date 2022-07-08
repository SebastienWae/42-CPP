#include "FragTrap.h"

int main(void) {
  FragTrap ft("ft");
  FragTrap ft2 = ft;

  ft.attack("targer 1");
  ft.highFivesGuys();
}
