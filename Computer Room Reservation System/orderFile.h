#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

#include"globalFile.h"
#include<fstream>

class orderFile {
public:
    orderFile();

    void updateOrder();

    int size;

    map<int, map<string, string>> orderData;

};

