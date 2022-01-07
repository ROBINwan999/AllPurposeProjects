#include "boss.h"


boss::boss(int id, string name, int did) {
    this->workID = id;
    this->workName = name;
    this->deptID = did;
}

void boss::showInfo() {
    cout << "employee ID: " << this->workID
         << "\t employee Name: " << this->workName
         << "\t department: " << this->getDeptName()
         << "\t\t responsibility: manage everything in the company!" << endl;
}

string boss::getDeptName() {
    return string("boss");
}