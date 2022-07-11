#include "Harl.h"

#include <iostream>

std::string Harl::name_arr[FUNC_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void) {
  this->fns_[0] = &Harl::Debug;
  this->fns_[1] = &Harl::Info;
  this->fns_[2] = &Harl::Warning;
  this->fns_[3] = &Harl::Error;
}

void Harl::Debug(void) { std::cout << "DEBUG" << std::endl; }

void Harl::Info(void) { std::cout << "INFO" << std::endl; }

void Harl::Warning(void) { std::cout << "WARNING" << std::endl; }

void Harl::Error(void) { std::cout << "ERROR" << std::endl; }

void Harl::Complain(std::string level) {
  for (int i = 0; i < FUNC_N; ++i) {
    if (name_arr[i] == level) {
      (this->*(fns_[i]))();
      break;
    }
  }
}
