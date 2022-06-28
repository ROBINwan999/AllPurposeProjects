#include "Address.h"

using namespace std;

Address::Address() =default;

const string &Address::getCity() const {
    return city_;
}

void Address::setCity(const string &city) {
    city_ = city;
}

const string &Address::getCountry() const {
    return country_;
}

void Address::setCountry(const string &country) {
    country_ = country;
}
