#include "PhoneBook.h"
#include <iostream>
#include <string>

int main(void) {
    PhoneBook phonebook = PhoneBook();
    std::string command;
    while (1) {
        std::getline(std::cin, command);
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT")
            return 0;
        command.clear();
    }
}
