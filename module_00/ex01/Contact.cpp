#include "Contact.h"

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#define PRINT_LEFT_PAD 16

std::string Contact::GetFirstName(void) const { return first_name_; }
std::string Contact::GetLastName(void) const { return last_name_; }
std::string Contact::GetNickName(void) const { return nickname_; }

std::ostream& Contact::Print(std::ostream& ostream) const {
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "First name: " << first_name_ << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "Last name: " << last_name_ << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "Nickname: " << nickname_ << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "Phone number: " << phone_ << std::endl;
  ostream << std::left << std::setw(PRINT_LEFT_PAD) << "Darkest secret:" << secret_ << std::endl;
  return ostream;
}

std::istream& Contact::Parse(std::istream& istream) {
  while (first_name_.empty()) {
    std::cout << "> first name: ";
    std::getline(istream, first_name_);
  }

  while (last_name_.empty()) {
    std::cout << "> last name: ";
    std::getline(istream, last_name_);
  }

  while (nickname_.empty()) {
    std::cout << "> nickname: ";
    std::getline(istream, nickname_);
  }

  while (phone_.empty()) {
    std::cout << "> phone number: ";
    std::getline(istream, phone_);
  }

  while (secret_.empty()) {
    std::cout << "> darkest secret: ";
    std::getline(istream, secret_);
  }
  return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Contact& contact) {
  return contact.Print(ostream);
}

std::istream& operator>>(std::istream& istream, Contact& contact) { return contact.Parse(istream); }

Contact::Contact(void) {
  first_name_ = "";
  last_name_ = "";
  nickname_ = "";
  phone_ = "";
  secret_ = "";
}
