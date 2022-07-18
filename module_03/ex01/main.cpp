#include "ScavTrap.h"

int main(void) {
  ScavTrap st("st");
  ScavTrap st2 = st;

  st.attack("target 1");
  st.guardGate();
  st.guardGate();
}
