#include "Contact.h"
#include "PhoneBook.h"
#include <cstddef>
#include <iostream>
#include <string>

void search_cmd(PhoneBook &phonebook) {
    if (phonebook.getSize() > 0) {
        std::cout << phonebook;
        std::cout << "> contact id: ";
        std::size_t id;
        std::cin >> id;
        try {
            const Contact &contact = phonebook.getContactById(id);
            std::cout << contact;
        } catch (std::exception &ex) {
            std::cout << "ERROR: contact id is invalid!" << std::endl;
        }
        std::cin.ignore();
    } else
        std::cout << "ERROR: no contacts in phonebook!" << std::endl;
}

void add_cmd(PhoneBook &phonebook) {
    Contact contact;
    std::cin >> contact;
    phonebook.addContact(contact);
}

int main(void) {
    PhoneBook phonebook = PhoneBook();
    std::string command;
    while (1) {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (command == "ADD")
            add_cmd(phonebook);
        else if (command == "SEARCH")
            search_cmd(phonebook);
        else if (command == "EXIT")
            return 0;
    }
}
