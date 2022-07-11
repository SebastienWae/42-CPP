#ifndef HARL_H
#define HARL_H

#include <string>

#define FUNC_N 4

class Harl {
  int filter_;

  void Debug(void);
  void Info(void);
  void Warning(void);
  void Error(void);

public:
  static std::string name_arr[FUNC_N];

  void Complain(std::string level);

  Harl(std::string filter);
};

#endif
