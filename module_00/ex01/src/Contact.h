#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
    std::string first_name, last_name, nickname, phone, secret;

  public:
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;

    std::ostream &print(std::ostream &os) const;
    std::istream &parse(std::istream &is);

    Contact(void);
};

std::ostream &operator<<(std::ostream &os, const Contact &contact);
std::istream &operator>>(std::istream &is, Contact &contact);

#endif
