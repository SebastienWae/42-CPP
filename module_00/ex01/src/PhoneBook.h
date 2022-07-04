#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <cstddef>
#include <string>

#include "Contact.h"

class PhoneBook {
    Contact contacts[8];
    std::size_t n_contacts;

  public:
    void addContact(void);
    void searchContact(void) const;

    PhoneBook(void);
    ~PhoneBook(void);

  private:
    const Contact *_getContactById(std::size_t id) const;
    void _print(void) const;
};

#endif
