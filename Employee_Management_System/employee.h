#pragma once

#include <iostream>
#include "worker.h"

using namespace std;


class employee : public worker {

public:

    employee(int id, string name, int did);

    virtual void showInfo();

    virtual string getDeptName();

};
