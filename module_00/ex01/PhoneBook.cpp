#include "PhoneBook.h"

#include <cstddef>
#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <string>

#include "Contact.h"
#include "utils.h"

PhoneBook::PhoneBook(void) : c_index_(0), c_total_(0) {}

std::size_t PhoneBook::GetTotalContacts() const { return c_total_; }

void PhoneBook::AddContact() {
  Contact contact;

  std::cin >> contact;
  contacts_[c_index_] = contact;
  c_index_ = (c_index_ + 1) % MAX_CONTACTS;
  if (c_total_ < MAX_CONTACTS) {
    c_total_++;
  }
}

void PhoneBook::SearchContacts() const {
  if (c_total_ > 0) {
    std::cout << *this;
    std::cout << "> contact id: ";
    std::string input;
    std::getline(std::cin, input);
    try {
      if (input.length() == 1 && input[0] >= '0' && input[0] < MAX_CONTACTS + '0') {
        std::size_t index = input[0] - '0';
        const Contact& contact = GetContactByIndex(index);
        std::cout << contact;
      } else {
        throw std::out_of_range("");
      }
    } catch (std::exception& ex) {
      std::cout << "ERROR: contact id is invalid!" << std::endl;
    }
  } else {
    std::cout << "ERROR: no contacts in phonebook!" << std::endl;
  }
}

const Contact& PhoneBook::GetContactByIndex(std::size_t index) const {
  if (index < c_total_) {
    return contacts_[index];
  }
  throw std::out_of_range("");
}

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phonebook) {
  ostream << "|      index | first name |  last name |   nickname |" << std::endl;
  ostream << "|------------|------------|------------|------------|" << std::endl;
  for (std::size_t i = 0; i < phonebook.GetTotalContacts(); ++i) {
    const Contact& c = phonebook.GetContactByIndex(i);
    ostream << "| " << std::setw(PRINT_COL_MAX_SIZE) << i;
    ostream << " | " << std::setw(PRINT_COL_MAX_SIZE)
            << Truncate(c.GetFirstName(), PRINT_COL_MAX_SIZE);
    ostream << " | " << std::setw(PRINT_COL_MAX_SIZE)
            << Truncate(c.GetLastName(), PRINT_COL_MAX_SIZE);
    ostream << " | " << std::setw(PRINT_COL_MAX_SIZE)
            << Truncate(c.GetNickName(), PRINT_COL_MAX_SIZE);
    ostream << " |" << std::endl;
  }
  ostream << "|------------|------------|------------|------------|" << std::endl;
  return ostream;
}
