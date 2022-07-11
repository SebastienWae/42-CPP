#include "Harl.h"

int main(void) {
  Harl harl;

  harl.Complain("DEBUG");
  harl.Complain("INFO");
  harl.Complain("WARNING");
  harl.Complain("ERROR");
  harl.Complain("TEST");
  harl.Complain("");
}
