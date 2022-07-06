#include "Contact.h"

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#define PRINT_LEFT_PAD 16

std::string Contact::GetFirstName(void) const {
  return first_name;
}
std::string Contact::GetLastName(void) const {
  return last_name;
}
std::string Contact::GetNickName(void) const {
  return nickname;
}

std::ostream& Contact::Print(std::ostream& ostream) const {
  ostream << std::left << std::setw(PRINT_LEFT_PAD)
          << "First name: " << first_name << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD)
          << "Last name: " << last_name << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "Nickname: " << nickname
          << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "Phone number: " << phone
          << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD)
          << "Darkest secret:" << secret << std::endl;
  return ostream;
}

std::istream& Contact::Parse(std::istream& istream) {
  while (first_name.empty()) {
    std::cout << "> first name: ";
    std::getline(istream, first_name);
  }

  while (last_name.empty()) {
    std::cout << "> last name: ";
    std::getline(istream, last_name);
  }

  while (nickname.empty()) {
    std::cout << "> nickname: ";
    std::getline(istream, nickname);
  }

  while (phone.empty()) {
    std::cout << "> phone number: ";
    std::getline(istream, phone);
  }

  while (secret.empty()) {
    std::cout << "> darkest secret: ";
    std::getline(istream, secret);
  }
  return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Contact& contact) {
  return contact.Print(ostream);
}

std::istream& operator>>(std::istream& istream, Contact& contact) {
  return contact.Parse(istream);
}

Contact::Contact(void) {
  first_name = "";
  last_name = "";
  nickname = "";
  phone = "";
  secret = "";
}
