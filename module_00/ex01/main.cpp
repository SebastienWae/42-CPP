#include <iostream>
#include <string>

#include "PhoneBook.h"

int main(void) {
  PhoneBook phonebook = PhoneBook();
  std::string command;
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, command);
    if (command == "ADD") {
      phonebook.AddContact();
    } else if (command == "SEARCH") {
      phonebook.SearchContacts();
    } else if (command == "EXIT") {
      return 0;
    }
  }
}
