#include "Contact.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

Contact::Contact(std::string first_name, std::string last_name,
                 std::string nickname, std::string phone_number,
                 std::string darkest_secret)
    : first_name(first_name), last_name(last_name), nickname(nickname),
      phone_number(phone_number), darkest_secret(darkest_secret) {}

std::string Contact::getFirstName(void) const { return first_name; }
std::string Contact::getLastName(void) const { return last_name; }
std::string Contact::getNickName(void) const { return nickname; }

void Contact::print(void) const {
    std::cout << std::left << std::setw(16) << "first name: ";
    std::cout << first_name << std::endl;
    std::cout << std::left << std::setw(16) << "last name: ";
    std::cout << last_name << std::endl;
    std::cout << std::left << std::setw(16) << "nickname: ";
    std::cout << nickname << std::endl;
    std::cout << std::left << std::setw(16) << "phone number: ";
    std::cout << phone_number << std::endl;
    std::cout << std::left << std::setw(16) << "darkest secret: ";
    std::cout << darkest_secret << std::endl;
}
