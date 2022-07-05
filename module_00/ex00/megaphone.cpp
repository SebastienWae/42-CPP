#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc > 0) {
        if (argc == 1) {
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        } else {
            for (int i = 1; i < argc; ++i) {
                std::string str(argv[i]);
                for (std::string::iterator t = str.begin(); t != str.end();
                     ++t) {
                    std::cout << static_cast<char>(std::toupper(*t));
                }
            }
            std::cout << std::endl;
        }
        return 0;
    }
    return 1;
}
