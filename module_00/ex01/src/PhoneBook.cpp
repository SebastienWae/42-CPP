#include "PhoneBook.h"
#include "Contact.h"

void PhoneBook::addContact(void) {
    std::string first_name = "first";
    std::string nickname = "nick";
    std::string phone_number = "0000";
    std::string darkest_secret = "lol";
    const Contact contact =
        *new Contact(first_name, nickname, phone_number, darkest_secret);
}

void PhoneBook::searchContact(void) const {}

const Contact *PhoneBook::_getContactById(std::size_t id) const {

    if (id < 8)
        return &(contacts[id]);
    else
        return NULL;
}
void PhoneBook::_print(void) const {}
