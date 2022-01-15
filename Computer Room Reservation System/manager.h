#pragma once

#include "identity.h"
#include <iostream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include <vector>
#include <algorithm>
#include "computerRoom.h"

using namespace std;

class manager : public identity {

public:

    manager();

    manager(string name, string pwd);

    virtual void openMenu();

    void addPerson();

    void showPerson();

    void showComputer();

    void cleanFile();

    void initVector();

    vector<student> vStu;
    vector<teacher> vTea;

    //check repeat, parameter1 for student/teacher ID, parameter2 for account type
    bool checkRepeat(int id, int type);

    vector<computerRoom> vCom;

    string name;
    string pwd;


};

