#include "Harl.h"

#include <iostream>

std::string Harl::name_arr[FUNC_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void) {
  this->fns[0] = &Harl::debug;
  this->fns[1] = &Harl::info;
  this->fns[2] = &Harl::warning;
  this->fns[3] = &Harl::error;
}

void Harl::debug(void) {
  std::cout << "DEBUG" << std::endl;
}

void Harl::info(void) {
  std::cout << "INFO" << std::endl;
}

void Harl::warning(void) {
  std::cout << "WARNING" << std::endl;
}

void Harl::error(void) {
  std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level) {
  for (int i = 0; i < FUNC_N; ++i) {
    if (name_arr[i] == level) {
      (this->*(fns[i]))();
      break;
    }
  }
}
