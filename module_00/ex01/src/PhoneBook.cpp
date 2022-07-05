#include "PhoneBook.h"
#include "Contact.h"
#include "utils.h"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

PhoneBook::PhoneBook(void) {
    c_index = 0;
    c_total = 0;
}

std::size_t PhoneBook::getSize(void) { return c_total; }

void PhoneBook::addContact(Contact &contact) {
    contacts[c_index] = contact;
    c_index = (c_index + 1) % MAX_CONTACTS;
    if (c_total < MAX_CONTACTS)
        c_total++;
}

const Contact &PhoneBook::getContactById(std::size_t id) const {
    if (id < c_total)
        return contacts[id];
    else
        throw std::out_of_range("out of range");
}

std::ostream &PhoneBook::print(std::ostream &os) const {
    os << "|      index | first name |  last name |   nickname |" << std::endl;
    os << "|------------|------------|------------|------------|" << std::endl;
    for (std::size_t i = 0; i < c_total; ++i) {
        os << "| " << std::setw(10) << i;
        os << " | " << std::setw(10)
           << truncate(contacts[i].getFirstName(), 10);
        os << " | " << std::setw(10) << truncate(contacts[i].getLastName(), 10);
        os << " | " << std::setw(10) << truncate(contacts[i].getNickName(), 10);
        os << " |" << std::endl;
    }
    os << "|------------|------------|------------|------------|" << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const PhoneBook &phonebook) {
    return phonebook.print(os);
}
