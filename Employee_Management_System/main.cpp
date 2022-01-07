#include <iostream>
#include "workerManager.h"
#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "boss.h"

using namespace std;

int main() {

//    worker *worker = NULL;
//    worker = new employee(1, "jack", 1);
//    worker->showInfo();
//
//    worker = new manager(2, "mike", 2);
//    worker->showInfo();
//
//    worker = new boss(3, "cindy", 3);
//    worker->showInfo();

    int choice;
    workerManager wm;

    while (true) {
        wm.showMenu();
        cout << "please enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
            case 0://exit
                wm.exitSystem();
                break;
            case 1://add
                wm.addEmployee();
                break;
            case 2://show
                wm.showEmp();
                break;
            case 3://delete
                wm.deleteEmp();
                break;
            case 4://change
                wm.changeEmp();
                break;
            case 5://find
                wm.findEmp();
                break;
            case 6://sort by ID
                wm.sortEmp();
                break;
            case 7://empty file
                wm.cleanFile();
                break;
            default:
                system("cls");
                break;
        }
    }


    return 0;
}
