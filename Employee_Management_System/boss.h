#pragma once

#include <iostream>;
#include "worker.h";

using namespace std;

class boss : public worker {
public:
    boss(int id, string name, int did);

    virtual void showInfo();

    virtual string getDeptName();
};