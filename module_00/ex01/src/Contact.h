#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
    const std::string first_name, nickname, phone_number, darkest_secret;

  public:
    Contact(std::string first_name, std::string nickname,
            std::string phone_number, std::string darkest_secret);
    ~Contact(void);

  private:
    void _print(void) const;
};

#endif
