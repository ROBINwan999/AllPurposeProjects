#pragma once

#include <iostream>;
#include "worker.h";

using namespace std;

class manager : public worker {
public:
    manager(int id, string name, int did);

    virtual void showInfo();

    virtual string getDeptName();
};