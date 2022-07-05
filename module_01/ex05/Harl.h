#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  typedef void (Harl::*HarlFn)(void);
  HarlFn fns[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  static std::string name_arr[4];

  void complain(std::string level);
};

#endif
