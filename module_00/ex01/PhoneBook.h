#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstddef>
#include <ostream>
#include <string>

#include "Contact.h"

#define MAX_CONTACTS 8
#define PRINT_COL_MAX_SIZE 10

class PhoneBook {
  Contact contacts_[MAX_CONTACTS];
  std::size_t c_index_;
  std::size_t c_total_;

public:
  std::size_t GetTotalContacts() const;
  void AddContact();
  void SearchContacts() const;
  const Contact& GetContactByIndex(std::size_t index) const;

  std::ostream& Print(std::ostream& ostream) const;

  PhoneBook();
};

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phonebook);

#endif
