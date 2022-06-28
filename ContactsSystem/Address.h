#ifndef ADDRESSLIST_ADDRESS_H
#define ADDRESSLIST_ADDRESS_H

#include <string>

class Address {
public:
    Address();

    const std::string &getCity() const;

    void setCity(const std::string &city);

    const std::string &getCountry() const;

    void setCountry(const std::string &country);

private:
    std::string city_;
    std::string country_;
};


#endif
