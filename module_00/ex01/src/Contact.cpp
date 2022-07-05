#include "Contact.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

std::string Contact::getFirstName(void) const { return first_name; }
std::string Contact::getLastName(void) const { return last_name; }
std::string Contact::getNickName(void) const { return nickname; }

std::ostream &Contact::print(std::ostream &os) const {
    os << std::left << std::setw(16) << "First name: " << first_name
       << std::endl;
    os << std::left << std::setw(16) << "Last name: " << last_name << std::endl;
    os << std::left << std::setw(16) << "Nickname: " << nickname << std::endl;
    os << std::left << std::setw(16) << "Phone number: " << phone << std::endl;
    os << std::left << std::setw(16) << "Darkest secret:" << secret
       << std::endl;
    return os;
}

std::istream &Contact::parse(std::istream &is) {
    while (first_name.empty()) {
        std::cout << "> first name: ";
        std::getline(is, first_name);
    }

    while (last_name.empty()) {
        std::cout << "> last name: ";
        std::getline(is, last_name);
    }

    while (nickname.empty()) {
        std::cout << "> nickname: ";
        std::getline(is, nickname);
    }

    while (phone.empty()) {
        std::cout << "> phone number: ";
        std::getline(is, phone);
    }

    while (secret.empty()) {
        std::cout << "> darkest secret: ";
        std::getline(is, secret);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
    return contact.print(os);
}

std::istream &operator>>(std::istream &is, Contact &contact) {
    return contact.parse(is);
}

Contact::Contact(void) {
    first_name = "";
    last_name = "";
    nickname = "";
    phone = "";
    secret = "";
}
