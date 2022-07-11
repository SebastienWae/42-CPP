#ifndef HARL_H
#define HARL_H

#include <string>

#define FUNC_N 4
class Harl {
  void Debug(void);
  void Info(void);
  void Warning(void);
  void Error(void);

  typedef void (Harl::*LogFns)(void);
  LogFns fns_[FUNC_N];

public:
  static std::string name_arr[FUNC_N];

  void Complain(std::string level);

  Harl();
};

#endif
