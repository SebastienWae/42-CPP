#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "usage: sed_is_for_losers file s1 s2" << std::endl;
    return 1;
  }

  std::string input_file_name = argv[1];
  std::string const output_file_name = input_file_name + ".replace";
  std::string old_string = argv[2];
  std::string new_string = argv[3];

  if (old_string.empty()) {
    std::cerr << "cannot replace empty string" << std::endl;
    return 1;
  }

  std::ifstream input_file;
  input_file.open(input_file_name.c_str(), std::ifstream::in);
  if (input_file.fail()) {
    std::cerr << "failed to open " << input_file_name << " for reading" << std::endl;
    return 1;
  }

  std::ofstream output_file;
  output_file.open(output_file_name.c_str(), std::ofstream::out);
  if (output_file.fail()) {
    std::cerr << "failed to open " << output_file_name << " for writing" << std::endl;
    return 1;
  }

  std::string line;
  while (getline(input_file, line) != 0) {
    std::string::size_type n;
    while ((n = line.find(old_string)) != std::string::npos) {
      output_file << line.substr(0, n);
      line.erase(0, n + old_string.length());
      output_file << new_string;
    }
    output_file << line << std::endl;
  }
}
