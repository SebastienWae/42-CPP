#include "Harl.h"

#include <cctype>
#include <iostream>
#include <stdexcept>

std::string Harl::name_arr[FUNC_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(std::string filter) {
  for (int i = 0; i < FUNC_N; ++i) {
    if (name_arr[i] == filter) {
      this->filter_ = i;
      return;
    }
  }
  throw std::out_of_range("[ Probably complaining about insignificant problems ]");
}

void Harl::Debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "debug msg" << std::endl;
}

void Harl::Info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "info msg" << std::endl;
}

void Harl::Warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "warning msg" << std::endl;
}

void Harl::Error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "error msg" << std::endl;
}

void Harl::Complain(std::string level) {
  for (int i = filter_; i < FUNC_N; ++i) {
    if (name_arr[i] == level) {
      switch (i) {
        case 0:
          Debug();
          break;
        case 1:
          Info();
          break;
        case 2:
          Warning();
          break;
        case 3:
          Error();
          break;
      }
      std::cout << std::endl;
      return;
    }
  }
}
