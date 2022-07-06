#ifndef HARL_H
#define HARL_H

#include <string>

#define FUNC_N 4

class Harl {
  int filter;

  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  static std::string name_arr[FUNC_N];

  void complain(std::string level);

  Harl(std::string filter);
};

#endif
