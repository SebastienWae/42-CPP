#include <iostream>
#include <ostream>

#include "Harl.h"

int main(int argc, char* argv[]) {
  if (argc == 2) {
    try {
      Harl harl(argv[1]);
      harl.Complain("DEBUG");
      harl.Complain("INFO");
      harl.Complain("WARNING");
      harl.Complain("ERROR");
      harl.Complain("TEST");
      harl.Complain("");
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  } else {
    std::cout << "Missing filter!" << std::endl;
  }
}
