#include <iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//admin submenu
void managerMenu(identity *&managers) {
    while (true) {
        managers->openMenu();

        manager *man = (manager *) managers;

        int select = 0;

        cout << "Please enter your option: " << endl;
        cin >> select;

        if (select == 1) {//add account
            man->addPerson();
        } else if (select == 2) {//check account
            man->showPerson();
        } else if (select == 3) {//check room
            man->showComputer();
        } else if (select == 4) {//cancel booking
            man->cleanFile();
        } else {
            delete managers;
            cout << "Log out successful!" << endl;
            return;
        }
    }
}

//student submenu
void studentMenu(identity *&students) {
    while (true) {
        students->openMenu();

        student *stu = (student *) students;

        int select = 0;
        cin >> select;

        if (select == 1) {//apply for booking
            stu->applyOrder();
        } else if (select == 2) {//check myself booking
            stu->showOrder();
        } else if (select == 3) {//check all bookings
            stu->showAllOrder();
        } else if (select == 4) {//cancel booking
            stu->cancelOrder();
        } else {
            delete students;
            cout << "Logout successful!" << endl;
            return;
        }

    }
}

void teacherMenu(identity *&teachers) {


    while (true) {
        teachers->openMenu();

        teacher *tea = (teacher *) teachers;
        int select = 0;
        cin >> select;
        if (select == 1) {
            tea->showAllOrder();
        } else if (select == 2) {
            tea->validOrder();
        } else {
            cout << "Logout successful!" << endl;
            return;
        }
    }

}

//login function
void logIn(string fileName, int select) {
    identity *person = NULL;
    ifstream ifs;
    ifs.open(fileName, ios::out);
    if (!ifs.is_open()) {
        cout << "file does not exist!" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;
    if (select == 1) {
        cout << "Please enter your student ID: " << endl;
        cin >> id;
    } else if (select == 2) {
        cout << "Please enter your teacher ID: " << endl;
        cin >> id;
    }

    cout << "Please enter your username: " << endl;
    cin >> name;

    cout << "Please enter your password: " << endl;
    cin >> pwd;

    if (select == 1) {
        int fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
            if (fid == id && fname == name && fpwd == pwd) {
                cout << "Student login successful!" << endl;
                person = new student(id, name, pwd);

                //student submenu
                studentMenu(person);
                return;
            }
        }
    } else if (select == 2) {
        int fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
            if (fid == id && fname == name && fpwd == pwd) {
                cout << "Teacher login successful!" << endl;
                person = new teacher(id, name, pwd);

                //teacher submenu
                teacherMenu(person);
                return;
            }
        }

    } else if (select == 3) {
        string fname;
        string fpwd;
        while (ifs >> fname && ifs >> fpwd) {
            if (name == fname && pwd == fpwd) {
                cout << "Admin login successful!" << endl;
                person = new manager(name, pwd);

                //admin submenu
                managerMenu(person);
                return;

            }
        }
    }

    cout << "Login failed!" << endl;

    return;
}


int main() {

    int select;

    while (true) {

        cout << "\t\t--------------------------------\n";
        cout << "\t\t|           1. Student         |\n";
        cout << "\t\t|           2. Teacher         |\n";
        cout << "\t\t|           3. Admin           |\n";
        cout << "\t\t|           0. Exit            |\n";
        cout << "\t\t--------------------------------\n";

        cout << "Please enter your choice: " << endl;
        cin >> select;
        switch (select) {
            case 1://student
                logIn((STUDENT_FILE), 1);
                break;
            case 2://teacher
                logIn((TEACHER_FILE), 2);
                break;
            case 3://admin
                logIn((ADMIN_FILE), 3);
                break;
            case 0://quit
                cout << "Welcome back next time!" << endl;
                return 0;
                break;
            default:
                cout << "Wrong input! please enter again!" << endl;
                break;
        }

    }

    return 0;
}
