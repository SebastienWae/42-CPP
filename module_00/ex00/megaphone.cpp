#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc > 0) {
    if (argc == 1) {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
      for (int i = 1; i < argc; ++i) {
        std::string str(argv[i]);
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
          std::cout << static_cast<char>(std::toupper(*it));
        }
      }
      std::cout << std::endl;
    }
    return 0;
  }
  return 1;
}
