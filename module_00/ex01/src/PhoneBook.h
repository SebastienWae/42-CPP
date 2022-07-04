#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstddef>
#include <ostream>
#include <string>

#include "Contact.h"

class PhoneBook {
  public:
    void addContact(void);
    void searchContact(void) const;
    PhoneBook(void);
    ~PhoneBook(void);

  private:
    Contact *contacts[8];
    std::size_t c_index;
    const Contact *getContactById(std::size_t id) const;
    void print(void) const;
};

#endif
