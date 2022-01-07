#include "manager.h"


manager::manager(int id, string name, int did) {
    this->workID = id;
    this->workName = name;
    this->deptID = did;
}

void manager::showInfo() {
    cout << "employee ID: " << this->workID
         << "\t employee Name: " << this->workName
         << "\t department: " << this->getDeptName()
         << "\t responsibility: finish the task from boss, and give task to employees!" << endl;
}

string manager::getDeptName() {
    return string("manager");
}