#include "PhoneBook.h"

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

#include "Contact.h"
#include "utils.h"

#define PRINT_COL_MAX_SIZE 10

PhoneBook::PhoneBook(void) {
  c_index_ = 0;
  c_total_ = 0;
}

std::size_t PhoneBook::GetSize(void) const { return c_total_; }

void PhoneBook::AddContact(Contact& contact) {
  contacts_[c_index_] = contact;
  c_index_ = (c_index_ + 1) % MAX_CONTACTS;
  if (c_total_ < MAX_CONTACTS) {
    c_total_++;
  }
}

const Contact& PhoneBook::GetContactByIndex(std::size_t index) const {
  if (index < c_total_) {
    return contacts_[index];
  }
  throw std::out_of_range("out of range");
}

std::ostream& PhoneBook::Print(std::ostream& ostream) const {
  ostream << "|      index | first name |  last name |   nickname |" << std::endl;
  ostream << "|------------|------------|------------|------------|" << std::endl;
  for (std::size_t i = 0; i < c_total_; ++i) {
    ostream << "| " << std::setw(PRINT_COL_MAX_SIZE) << i;
    ostream << " | " << std::setw(PRINT_COL_MAX_SIZE)
            << Truncate(contacts_[i].GetFirstName(), PRINT_COL_MAX_SIZE);
    ostream << " | " << std::setw(PRINT_COL_MAX_SIZE)
            << Truncate(contacts_[i].GetLastName(), PRINT_COL_MAX_SIZE);
    ostream << " | " << std::setw(PRINT_COL_MAX_SIZE)
            << Truncate(contacts_[i].GetNickName(), PRINT_COL_MAX_SIZE);
    ostream << " |" << std::endl;
  }
  ostream << "|------------|------------|------------|------------|" << std::endl;
  return ostream;
}

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phonebook) {
  return phonebook.Print(ostream);
}
