#include <iostream>
#include <string>

int main(void) {
  std::string brainzSTR = "HI THIS IS BRAIN";
  std::string* stringPTR = &brainzSTR;
  std::string& stringREF = brainzSTR;

  std::cout << "memory address of brainzSTR: " << &brainzSTR << std::endl;
  std::cout << "memory address of stringPTR: " << &stringPTR << std::endl;
  std::cout << "memory address of stringREF: " << &stringREF << std::endl;

  std::cout << "value of string: " << brainzSTR << std::endl;
  std::cout << "value at stringREF: " << *stringPTR << std::endl;
  std::cout << "value at stringREF: " << stringREF << std::endl;
  return 0;
}
