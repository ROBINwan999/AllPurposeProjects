#include <fstream>
#include "Student.h"

using namespace std;

Student::Student() = default;

Student::Student(int id, const string &name, int math, int english, int c, int dataStructure) : id_(id),
                                                                                                name_(name),
                                                                                                math_(math),
                                                                                                English_(english),
                                                                                                C_(c),
                                                                                                data_structure_(
                                                                                                        dataStructure) {}

int Student::getId() const {
    return id_;
}

void Student::setId(int id) {
    id_ = id;
}

const string &Student::getName() const {
    return name_;
}

void Student::setName(const string &name) {
    name_ = name;
}

int Student::getMath() const {
    return math_;
}

void Student::setMath(int math) {
    math_ = math;
}

int Student::getEnglish() const {
    return English_;
}

void Student::setEnglish(int english) {
    English_ = english;
}

int Student::getC() const {
    return C_;
}

void Student::setC(int c) {
    C_ = c;
}

int Student::getDataStructure() const {
    return data_structure_;
}

void Student::setDataStructure(int dataStructure) {
    data_structure_ = dataStructure;
}

bool Student::operator==(const Student &stu) {
    if (id_ == stu.id_) {
        return true;
    } else {
        return false;
    }
}

ostream &operator<<(ostream &os, const Student &stu) {
    os << stu.getId() << '\t' << stu.getName() << "\t\t"
       << stu.getMath() << "\t" << stu.getEnglish() << "\t"
       << stu.getC() << "\t" << stu.getDataStructure();

    return os;
}