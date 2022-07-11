#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc == 4) {
    std::string line;

    std::string old_str = argv[2];
    std::string new_str = argv[3];

    std::ifstream old_file(argv[1]);
    if (!old_file.is_open()) {
      std::cout << "Unable to open file" << std::endl;
      return 1;
    }

    std::string new_file_name = static_cast<std::string>(argv[1]).append(".replace");
    std::ofstream new_file(new_file_name.c_str());
    if (!new_file.is_open()) {
      std::cout << "Unable to open file" << std::endl;
      old_file.close();
      return 1;
    }

    while (std::getline(old_file, line) != 0) {
      std::string::size_type start = line.find(old_str);
      while (start != std::string::npos) {
        new_file << line.substr(0, start);
        new_file << new_str;
        line = line.substr(start + old_str.length());
        start = line.find(old_str);
      }
      new_file << line << std::endl;
    }
    return 0;
  }
  std::cout << "Invalid arguments" << std::endl;
  return 1;
}
