#include "Contact.h"

using namespace std;

const string &Contact::getName() const {
    return name_;
}

void Contact::setName(const string &name) {
    name_ = name;
}

const string &Contact::getGender() const {
    return gender_;
}

void Contact::setGender(const string &gender) {
    gender_ = gender;
}

size_t Contact::getPhone() const {
    return phone_;
}

void Contact::setPhone(size_t phone) {
    phone_ = phone;
}

const Address &Contact::getAddress() const {
    return address_;
}

void Contact::setAddress(const Address &address) {
    address_ = address;
}


