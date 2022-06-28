#ifndef ADDRESSLIST_CONTACT_H
#define ADDRESSLIST_CONTACT_H

#include <string>
#include "Address.h"

class Contact {
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getGender() const;

    void setGender(const std::string &gender);

    size_t getPhone() const;

    void setPhone(size_t phone);

    const Address &getAddress() const;

    void setAddress(const Address &address);

private:
    std::string name_;
    std::string gender_;
    size_t phone_;
    Address address_;
};


#endif
