#include <iostream>
#include <ostream>

#include "Harl.h"

int main(int argc, char* argv[]) {
  if (argc == 2) {
    try {
      Harl harl(argv[1]);
      harl.complain("DEBUG");
      harl.complain("INFO");
      harl.complain("WARNING");
      harl.complain("ERROR");
      harl.complain("TEST");
      harl.complain("");
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  } else {
    std::cerr << "Missing filter!" << std::endl;
  }
}
