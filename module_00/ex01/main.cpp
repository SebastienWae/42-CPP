#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Contact.h"
#include "PhoneBook.h"

void SearchCmd(PhoneBook& phonebook) {
  if (phonebook.GetSize() > 0) {
    std::cout << phonebook;
    std::cout << "> contact id: ";
    std::string input;
    std::getline(std::cin, input);
    try {
      if (input.length() == 1 && input[0] >= '0' && input[0] < '8') {
        std::size_t index = input[0] - '0';
        const Contact& contact = phonebook.GetContactByIndex(index);
        std::cout << contact;
      } else {
        throw std::out_of_range("out of range");
      }
    } catch (std::exception& ex) {
      std::cout << "ERROR: contact id is invalid!" << std::endl;
    }
  } else {
    std::cout << "ERROR: no contacts in phonebook!" << std::endl;
  }
}

void AddCmd(PhoneBook& phonebook) {
  Contact contact;
  std::cin >> contact;
  phonebook.AddContact(contact);
}

int main(void) {
  PhoneBook phonebook = PhoneBook();
  std::string command;
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, command);
    if (command == "ADD") {
      AddCmd(phonebook);
    } else if (command == "SEARCH") {
      SearchCmd(phonebook);
    } else if (command == "EXIT") {
      return 0;
    }
  }
}
