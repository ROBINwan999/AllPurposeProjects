#pragma once

#include <iostream>


using namespace std;

class identity {

public:
    virtual void openMenu() = 0;

    string name;//user name
    string pwd;//password
};