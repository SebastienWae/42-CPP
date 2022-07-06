#include "Harl.h"

#include <cctype>
#include <iostream>
#include <stdexcept>

std::string Harl::name_arr[FUNC_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(std::string filter) {
  for (int i = 0; i < FUNC_N; ++i) {
    if (name_arr[i] == filter) {
      this->filter = i;
      return;
    }
  }
  throw std::out_of_range(
      "[ Probably complaining about insignificant problems ]");
}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "debug msg" << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "info msg" << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "warning msg" << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "error msg" << std::endl;
}

void Harl::complain(std::string level) {
  for (int i = filter; i < FUNC_N; ++i) {
    if (name_arr[i] == level) {
      switch (i) {
        case 0:
          debug();
          break;
        case 1:
          info();
          break;
        case 2:
          warning();
          break;
        case 3:
          error();
          break;
      }
      std::cout << std::endl;
      return;
    }
  }
}
