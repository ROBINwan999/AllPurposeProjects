#pragma once

#include "identity.h"
#include <iostream>
#include <string>
#include "computerRoom.h"
#include <vector>
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"


using namespace std;

class student : public identity {

public:

    student();

    student(int id, string name, string pwd);

    virtual void openMenu();//menu

    void applyOrder();

    void showOrder();

    void showAllOrder();

    void cancelOrder();

    int id;//student number
    string name;
    string pwd;

    vector<computerRoom> vCom;

};

