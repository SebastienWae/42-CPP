#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
  public:
    void print(void) const;
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    Contact(std::string first_name, std::string last_name, std::string nickname,
            std::string phone_number, std::string darkest_secret);

  private:
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
};

#endif
