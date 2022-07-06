#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      std::string str(argv[i]);
      for (int j = 0; str[j] != 0; ++j) {
        std::cout << static_cast<char>(std::toupper(str[j]));
      }
    }
    std::cout << std::endl;
  }
}
