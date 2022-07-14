#include "Harl.h"

#include <iostream>

std::string Harl::name_arr[FUNC_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void) {
  funcs[0] = &Harl::debug;
  funcs[1] = &Harl::info;
  funcs[2] = &Harl::warning;
  funcs[3] = &Harl::error;
}

void Harl::debug(void) { std::cout << "DEBUG" << std::endl; }

void Harl::info(void) { std::cout << "INFO" << std::endl; }

void Harl::warning(void) { std::cout << "WARNING" << std::endl; }

void Harl::error(void) { std::cout << "ERROR" << std::endl; }

void Harl::complain(std::string level) {
  for (int i = 0; i < FUNC_N; ++i) {
    if (name_arr[i] == level) {
      (this->*(funcs[i]))();
      return;
    }
  }
  std::cerr << "Harl 2.0 doesn't know how to complain at level " << level << "." << std::endl;
}
