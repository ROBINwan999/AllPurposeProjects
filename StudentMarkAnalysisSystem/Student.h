#ifndef SMS_STUDENT_H
#define SMS_STUDENT_H

#include <string>

class Student {
public:
    Student();

    Student(int id, const std::string &name, int math, int english, int c, int dataStructure);

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getMath() const;

    void setMath(int math);

    int getEnglish() const;

    void setEnglish(int english);

    int getC() const;

    void setC(int c);

    int getDataStructure() const;

    void setDataStructure(int dataStructure);

    bool operator==(const Student &stu);

private:
    int id_;
    std::string name_;
    int math_;
    int English_;
    int C_;
    int data_structure_;
};

std::ostream &operator<<(std::ostream &os, const Student &stu);

#endif
