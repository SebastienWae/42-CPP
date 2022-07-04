#include "PhoneBook.h"
#include "Contact.h"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

std::string truncate(std::string str, size_t width) {
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}

PhoneBook::PhoneBook(void) {
    c_index = 0;
    for (int i = 0; i < 8; ++i)
        contacts[i] = NULL;
}

PhoneBook::~PhoneBook(void) {
    for (int i = 0; i < 8; ++i) {
        if (this->contacts[i])
            delete contacts[i];
    }
}

void PhoneBook::addContact(void) {
    std::string first_name;
    while (first_name.empty()) {
        std::cout << "first name: ";
        std::getline(std::cin, first_name);
    }

    std::string last_name;
    while (last_name.empty()) {
        std::cout << "last name: ";
        std::getline(std::cin, last_name);
    }

    std::string nickname;
    while (nickname.empty()) {
        std::cout << "nickname: ";
        std::getline(std::cin, nickname);
    }

    std::string phone_number;
    while (phone_number.empty()) {
        std::cout << "phone number: ";
        std::getline(std::cin, phone_number);
    }

    std::string darkest_secret;
    while (darkest_secret.empty()) {
        std::cout << "darkest secret: ";
        std::getline(std::cin, darkest_secret);
    }

    Contact *contact = new Contact(first_name, last_name, nickname,
                                   phone_number, darkest_secret);

    if (c_index == 7)
        c_index = 0;
    else
        c_index++;
    if (contacts[c_index])
        delete contacts[c_index];
    contacts[c_index] = contact;
}

void PhoneBook::searchContact(void) const {
    print();
    while (1) {
        std::cout << "contact id: ";
        std::size_t id;
        std::cin >> id;
        const Contact *contact = getContactById(id);
        if (contact) {
            contact->print();
            return;
        } else
            std::cout << "contact id is invalid" << std::endl;
    }
}

const Contact *PhoneBook::getContactById(std::size_t id) const {
    if (id < 8 && contacts[id])
        return contacts[id];
    else
        return NULL;
}

void PhoneBook::print(void) const {
    std::cout << "|      index | first name |  last name |   nickname |"
              << std::endl;
    std::cout << "|------------|------------|------------|------------|"
              << std::endl;
    for (int i = 0; i < 8; ++i) {
        if (contacts[i]) {
            std::cout << "| ";
            std::cout << std::setw(10) << i;
            std::cout << " | ";
            std::cout << std::setw(10)
                      << truncate(contacts[i]->getFirstName(), 10);
            std::cout << " | ";
            std::cout << std::setw(10)
                      << truncate(contacts[i]->getLastName(), 10);
            std::cout << " | ";
            std::cout << std::setw(10)
                      << truncate(contacts[i]->getNickName(), 10);
            std::cout << " |" << std::endl;
        }
    }
    std::cout << "|------------|------------|------------|------------|"
              << std::endl;
}
