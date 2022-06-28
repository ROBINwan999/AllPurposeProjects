#ifndef ADDRESSLIST_CONTACTMANAGER_H
#define ADDRESSLIST_CONTACTMANAGER_H

#include <unordered_map>
#include <string>
#include "Contact.h"

class ContactManager {
public:
    ContactManager();

    void menuOption();

private:
    void readFile();

    void printMenu();

    bool hasNumber(const std::string &str);

    std::string createName();

    std::string chooseGender();

    size_t createPhone();

    std::string addCity();

    std::string addCountry();

    bool isExist(const std::string &name);

    bool isContinue();

    void writeFile(const Contact &contact);

    void addContact();

    void deleteInFile(const std::string &name);

    void deleteContact();

    std::string getName(const std::string &name);

    void printContact();

    void modifyContact();

    void searchContact();

    void clearContact();

private:
    std::unordered_multimap<std::string, Contact> contact_list_;
};

#endif
