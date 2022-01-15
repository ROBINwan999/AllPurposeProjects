#pragma once

#include "identity.h"
#include <iostream>
#include <string>
#include "orderFile.h"
#include <vector>

using namespace std;
class teacher :public identity{
public:
    teacher();

    teacher(int id, string name, string pwd);

    virtual void openMenu();

    void showAllOrder();

    void validOrder();


    int id;
    string name;
    string pwd;
};
