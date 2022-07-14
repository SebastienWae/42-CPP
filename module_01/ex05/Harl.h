#ifndef HARL_H
#define HARL_H

#include <string>

#define FUNC_N 4

class Harl {
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

  typedef void (Harl::*logFunc)(void);
  logFunc funcs[FUNC_N];

public:
  static std::string name_arr[FUNC_N];

  void complain(std::string level);

  Harl();
};

#endif
