#include "employee.h"

employee::employee(int id, string name, int did) {
    this->workID = id;
    this->workName = name;
    this->deptID = did;
}

void employee::showInfo() {
    cout << "employee ID: " << this->workID
         << "\t employee Name: " << this->workName
         << "\t department: " << this->getDeptName()
         << "\t responsibility: finish the task from manager!" << endl;
}

string employee::getDeptName() {
    return string("employee");
}