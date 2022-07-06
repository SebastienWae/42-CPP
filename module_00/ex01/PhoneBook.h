#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstddef>
#include <ostream>
#include <string>

#include "Contact.h"

#define MAX_CONTACTS 8

class PhoneBook {
  Contact contacts_[MAX_CONTACTS];
  std::size_t c_index;
  std::size_t c_total;

 public:
  std::size_t GetSize(void) const;

  void AddContact(Contact& contact);
  const Contact& GetContactByIndex(std::size_t index) const;

  std::ostream& Print(std::ostream& ostream) const;

  PhoneBook(void);
};

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phonebook);

#endif
