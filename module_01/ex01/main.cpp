#include <iostream>
#include <string>

#include "Zombie.h"

Zombie* zombieHorde(int n, std::string name);

void annouceHorde(Zombie* horde, int n) {
  for (int i = n - 1; i >= 0; i--) {
    horde[i].announce();
  }
}

int main(void) {
  std::string const name = "z";
  {
    std::cout << "## TEST 1 ##" << std::endl;

    int const n = 5;
    Zombie* horde = zombieHorde(n, name);
    annouceHorde(horde, n);
    horde->announce();
    horde->setName("a");
    annouceHorde(horde, n);

    delete[] horde;
  }
  {
    std::cout << "## TEST 2 ##" << std::endl;

    int const n = -5;
    Zombie* horde = zombieHorde(n, name);
    annouceHorde(horde, n);
  }
  {
    std::cout << "## TEST 3 ##" << std::endl;

    int const n = 0;
    Zombie* horde = zombieHorde(n, name);
    annouceHorde(horde, n);
  }
}
