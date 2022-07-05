#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
  std::string first_name_, last_name_, nickname_, phone_, secret_;

 public:
  std::string GetFirstName(void) const;
  std::string GetLastName(void) const;
  std::string GetNickName(void) const;

  std::ostream &Print(std::ostream &ostream) const;
  std::istream &Parse(std::istream &istream);

  Contact(void);
};

std::ostream &operator<<(std::ostream &ostream, const Contact &contact);
std::istream &operator>>(std::istream &istream, Contact &contact);

#endif
