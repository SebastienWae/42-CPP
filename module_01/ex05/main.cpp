#include "Harl.h"

int main(void) {
  Harl harl;

  harl.complain("debug");
  harl.complain("info");
  harl.complain("warning");
  harl.complain("error");
  harl.complain("test");
  harl.complain("");
}
