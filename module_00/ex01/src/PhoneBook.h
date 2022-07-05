#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstddef>
#include <ostream>
#include <string>

#include "Contact.h"

#define MAX_CONTACTS 8

class PhoneBook {
    Contact contacts[MAX_CONTACTS];
    std::size_t c_index;
    std::size_t c_total;

  public:
    std::size_t getSize(void);

    void addContact(Contact &contact);
    const Contact &getContactById(std::size_t id) const;

    std::ostream &print(std::ostream &os) const;

    PhoneBook(void);
};

std::ostream &operator<<(std::ostream &os, const PhoneBook &phonebook);

#endif
