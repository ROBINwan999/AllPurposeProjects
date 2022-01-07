#pragma once

#include <iostream>;

using namespace std;

class worker {

public:
    virtual void showInfo() = 0;

    virtual string getDeptName() = 0;

    int workID;
    string workName;
    int deptID;
};