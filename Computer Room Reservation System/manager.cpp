#include <fstream>
#include "manager.h"

manager::manager() {}

manager::manager(string name, string pwd) {
    this->name = name;
    this->pwd = pwd;
    this->initVector();

    //initial room information
    ifstream ifs;

    ifs.open(COMPUTER_FILE, ios::in);

    computerRoom com;
    while (ifs >> com.comID && ifs >> com.MaxNum) {
        vCom.push_back(com);
    }
    ifs.close();
    cout << "Computer number: " << vCom.size() << endl;
}

void manager::openMenu() {
    cout << "\t\t----------------------------------\n";
    cout << "\t\t|         1. Add account         |\n";
    cout << "\t\t|         2. Check account       |\n";
    cout << "\t\t|         3. Check room          |\n";
    cout << "\t\t|         4. Cancel booking      |\n";
    cout << "\t\t|         0. Log out             |\n";
    cout << "\t\t----------------------------------\n";
}

void manager::addPerson() {
    cout << "Please enter the account type you want to add: " << endl;
    cout << "1 -- student" << endl;
    cout << "2 -- teacher" << endl;

    string fileName;
    string tip;
    string errorTip;

    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "Please enter student ID: ";
        errorTip = "Student ID repeated! please enter again: ";

    } else {
        fileName = TEACHER_FILE;
        tip = "Please enter teacher ID: ";
        errorTip = "Teacher ID repeated! please enter again: ";
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;
    cout << tip << endl;
    while (true) {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret) {//have repeated
            cout << errorTip << endl;
        } else {
            break;
        }
    }

    cout << tip << endl;
    cin >> id;
    cout << "Please enter name: " << endl;
    cin >> name;
    cout << "Please enter password: " << endl;
    cin >> pwd;
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Add successful!" << endl;
    ofs.close();

    this->initVector();
}

void printStudent(student &s) {
    cout << "Student ID: " << s.id << " Name: " << s.name << " Password: " << s.pwd << endl;
}

void printTeacher(teacher &t) {
    cout << "Teacher ID: " << t.id << " Name: " << t.name << " Password: " << t.pwd << endl;
}

void manager::showPerson() {
    cout << "Please enter option you want to check:" << endl;
    cout << "1 -- All student" << endl;
    cout << "2 -- All teacher" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        cout << "All student information as below: " << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);

    } else {
        cout << "All teacher information as below: " << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);

    }

}

void manager::showComputer() {
    cout << "Computer room information below: " << endl;
    for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
        cout << "Computer room ID: " << it->comID << " Computer room max capacity: " << it->MaxNum << endl;
    }
}

void manager::cleanFile() {
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();

    cout << "Clean successful!" << endl;
}

void manager::initVector() {
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File load failed!" << endl;
        return;
    }

    student s;
    while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd) {
        vStu.push_back(s);
    }
    cout << "current student number: " << vStu.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File load failed!" << endl;
        return;
    }
    teacher t;
    while (ifs >> t.id && ifs >> t.name && ifs >> t.pwd) {
        vTea.push_back(t);
    }
    cout << "current teacher number: " << vTea.size() << endl;
    ifs.close();
}

bool manager::checkRepeat(int id, int type) {
    if (type == 1) {
        //check student
        for (vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
            if (id == it->id) {
                return true;
            }
        }

    } else {
        //check teacher
        for (vector<teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
            if (id == it->id) {
                return true;
            }
        }
    }

    return false;
}
