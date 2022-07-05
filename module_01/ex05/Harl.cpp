#include "Harl.h"

#include <iostream>

std::string Harl::name_arr[4] = {"debug", "info", "warning", "error"};

void Harl::debug(void) { std::cout << "DEBUG" << std::endl; }

void Harl::info(void) { std::cout << "INFO" << std::endl; }

void Harl::warning(void) { std::cout << "WARNING" << std::endl; }

void Harl::error(void) { std::cout << "ERROR" << std::endl; }

void Harl::complain(std::string level) {
  HarlFn fns[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  for (int i = 0; i < 4; ++i) {
    if (name_arr[i] == level) {
      (this->*(fns[i]))();
      break;
    }
  }
}
