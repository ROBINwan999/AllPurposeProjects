#pragma once

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt";

using namespace std;


class workerManager {

public:
    workerManager();

    ~workerManager();

    void showMenu();

    void exitSystem();

    int employeeNumber;//record number of employee

    worker **employeeArr;//employee array pointer

    void addEmployee();//add employees

    void save();//save file

    bool isFileEmpty;//check is file empty or not

    int getEmpNum();//statistic number of employees

    void initEmp();//initial employees

    void showEmp();//print out employees

    void deleteEmp();//delete employee

    int isExist(int id);//check it not exist, return -1

    void changeEmp();//modify employee information

    void findEmp();//find employee

    void sortEmp();//sort employee

    void cleanFile();//clean file

};

