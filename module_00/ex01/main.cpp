#include <cstddef>
#include <iostream>
#include <string>

#include "Contact.h"
#include "PhoneBook.h"

void SearchCmd(PhoneBook &phonebook) {
  if (phonebook.GetSize() > 0) {
    std::cout << phonebook;
    std::cout << "> contact id: ";
    std::size_t index;
    std::cin >> index;
    try {
      const Contact &contact = phonebook.GetContactByIndex(index);
      std::cout << contact;
    } catch (std::exception &ex) {
      std::cout << "ERROR: contact id is invalid!" << std::endl;
    }
    std::cin.ignore();
  } else {
    std::cout << "ERROR: no contacts in phonebook!" << std::endl;
  }
}

void AddCmd(PhoneBook &phonebook) {
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
