//
// Created by Robin Wan on 28/6/22.
//

#ifndef SMS_STUDENTMANAGER_H
#define SMS_STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
public:
    StudentManager();

    void menuOption();

private:
    void printMenu();

    void readFile();

    void mathRanking();

    void EnglishRanking();

    void CRanking();

    void dataStructureRanking();

    void menuOption1();

    void averageRanking();

    void menuOption2();

    int highestMath();

    int lowestMath();

    int highestEnglish();

    int lowestEnglish();

    int highestC();

    int lowestC();

    int highestDataStructure();

    int lowestDataStructure();

    std::vector<int> subjectAverage();

    std::vector<int> below60();

    std::vector<int> between60to69();

    std::vector<int> between79to79();

    std::vector<int> between80to89();

    std::vector<int> above90();

    void menuOption3();

    void getGpa();

    void menuOption4();

    std::string getName();

    void menuOption5();

    int getSid();

    void menuOption6();

    int getMath();

    int getEnglish();

    int getC();

    int getDataStructure();

    void createStudent();

    void writeFile(const Student &stu);

    void menuOption7();

    void deleteStudent();

    void menuOption8();

private:
    std::vector<Student> students_;
};


#endif //SMS_STUDENTMANAGER_H
