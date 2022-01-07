#include "workerManager.h"

workerManager::workerManager() {

    ifstream ifs;
    ifs.open(("/Users/robin/CLionProjects/Employee_Management_System"), ios::in);

    if (!ifs.is_open()) {
        //cout << "file does not exist!" << endl;
        this->employeeNumber = 0;
        this->employeeArr = NULL;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        // cout << "file is empty!" << endl;
        this->employeeNumber = 0;
        this->employeeArr = NULL;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    int num = this->getEmpNum();
    //cout << "employee number are: " << num << endl;
    this->employeeNumber = num;

    this->employeeArr = new worker *[this->employeeNumber];
    this->initEmp();

//    for (int i = 0; i < this->employeeNumber; i++) {
//        cout << "employee ID: " << this->employeeArr[i]->workID
//             << "\t employee Namke: " << this->employeeArr[i]->workName
//             << "\t department: " << this->employeeArr[i]->deptID << endl;
//    }
}

void workerManager::showMenu() {
    cout << "Welcome to use Employee Management System!" << endl;
    cout << "0. exit system" << endl;
    cout << "1. add employee" << endl;
    cout << "2. show employee" << endl;
    cout << "3. delete employee" << endl;
    cout << "4. change employee" << endl;
    cout << "5. find employee" << endl;
    cout << "6. sort by ID" << endl;
    cout << "7. empty all file" << endl;
    cout << endl;
}

void workerManager::exitSystem() {
    cout << "welcome back next time!" << endl;
    exit(0);
}

void workerManager::addEmployee() {
    cout << "please enter number you want to add: " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->employeeNumber + addNum;
        worker **newSpace = new worker *[newSize];
        if (this->employeeArr != NULL) {
            for (int i = 0; i < this->employeeNumber; i++) {
                newSpace[i] = this->employeeArr[i];
            }
        }
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;
            cout << "please enter the " << i + 1 << "th number employee ID" << endl;
            cin >> id;

            cout << "please enter the " << i + 1 << "th number employee name" << endl;
            cin >> name;

            cout << "please choose the department" << endl;
            cout << "1 -- employee" << endl;
            cout << "2 -- manager" << endl;
            cout << "3 -- boss" << endl;
            cin >> dSelect;

            worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new employee(id, name, 1);
                    break;
                case 2:
                    worker = new manager(id, name, 2);
                    break;
                case 3:
                    worker = new boss(id, name, 3);
                    break;
                default:
                    break;
            }
            newSpace[this->employeeNumber + i] = worker;
        }
        delete[] this->employeeArr;
        this->employeeArr = newSpace;
        this->employeeNumber = newSize;

        this->isFileEmpty = false;

        cout << "successfully add " << addNum << " employees!" << endl;

        this->save(); //save data into file

    } else {
        cout << "wrong number!" << endl;
    }
}

void workerManager::save() {
    ofstream ofs;
    ofs.open(("/Users/robin/CLionProjects/Employee_Management_System/empFILE.txt"), ios::out);

    for (int i = 0; i < this->employeeNumber; i++) {
        ofs << this->employeeArr[i]->workID << " "
            << this->employeeArr[i]->workName << " "
            << this->employeeArr[i]->deptID << endl;
    }
    ofs.close();
}

int workerManager::getEmpNum() {
    ifstream ifs;
    ifs.open(("/Users/robin/CLionProjects/Employee_Management_System"), ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did) {
        num++;
    }
    return num;
}

void workerManager::initEmp() {
    ifstream ifs;
    ifs.open(("/Users/robin/CLionProjects/Employee_Management_System"), ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    int index;
    while (ifs >> id && ifs >> name && ifs >> did) {
        worker *worker = NULL;
        if (did == 1) {
            worker = new employee(id, name, did);
        } else if (did == 2) {
            worker = new manager(id, name, did);
        } else {
            worker = new boss(id, name, did);
        }
        this->employeeArr[index] = worker;
        index++;
    }
    ifs.close();
}

void workerManager::showEmp() {
    if (this->isFileEmpty) {
        cout << "file does not exist or is empty!" << endl;
    } else {
        for (int i = 0; i < employeeNumber; i++) {
            this->employeeArr[i]->showInfo();
        }
    }
}

void workerManager::deleteEmp() {
    if (this->isFileEmpty) {
        cout << "file does not exist or is empty!" << endl;
    } else {
        cout << "please enter the employee ID you want to delete: " << endl;
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->employeeNumber - 1; i++) {
                this->employeeArr[i] = this->employeeArr[i + 1];
            }
            this->employeeNumber--;
            this->save();
            cout << "delete successful!" << endl;
        } else {
            cout << "delete failed, do not find this guy!" << endl;
        }
    }
}

int workerManager::isExist(int id) {
    int index = -1;
    for (int i = 0; i < this->employeeNumber; i++) {
        if (this->employeeArr[i]->workID == id) {
            index = i;
            break;
        }
    }
    return index;
}

void workerManager::changeEmp() {
    if (this->isFileEmpty) {
        cout << "file does not exist or is empty!" << endl;
    } else {
        cout << "please enter the employee ID you want to modify: " << endl;
        int id;
        cin >> id;
        int res = this->isExist(id);
        if (res != -1) {
            delete this->employeeArr[res];

            int newID = 0;
            string newName = " ";
            int newDid = 0;
            cout << "find " << id << " employee!, please enter newID: " << endl;
            cin >> newID;
            cout << "please enter new name: " << endl;
            cin >> newName;
            cout << "please enter new department: " << endl;
            cout << "1 -- employee" << endl;
            cout << "2 -- manager" << endl;
            cout << "3 -- boss" << endl;
            cin >> newDid;
            worker *worker = NULL;
            switch (newDid) {
                case 1:
                    worker = new employee(newID, newName, newDid);
                    break;
                case 2:
                    worker = new manager(newID, newName, newDid);
                    break;
                case 3:
                    worker = new boss(newID, newName, newDid);
                    break;
                default:
                    break;
            }
            this->employeeArr[res] = worker;
            cout << "modify successful!" << endl;
        } else {
            cout << "modify failed, can not find this guy!" << endl;
        }
    }
}

void workerManager::findEmp() {
    if (this->isFileEmpty) {
        cout << "file does not exist or is empty!" << endl;
    } else {
        cout << "please enter way of finding: " << endl;
        cout << "1 -- by employee ID" << endl;
        cout << "2 -- by employee name" << endl;

        int select;
        cin >> select;
        if (select == 1) {
            cout << "please enter the employee ID you want to modify: " << endl;
            int id;
            cin >> id;
            int res = this->isExist(id);
            if (res != -1) {
                cout << "find the employee!" << endl;
                this->employeeArr[res]->showInfo();
            }
        } else if (select == 2) {
            string name;
            cout << "please enter the name you want to find: " << endl;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < this->employeeNumber; i++) {
                if (this->employeeArr[i]->workName == name) {
                    cout << "find this guy! name is: "
                         << employeeArr[i]->workName
                         << " information below: " << endl;
                    this->employeeArr[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "failed, can not find this guy!" << endl;
            }
        }
        cout << "entered wrong input" << endl;
    }
}

void workerManager::sortEmp() {
    if (this->isFileEmpty) {
        cout << "file does not exist or is empty!" << endl;
    } else {
        cout << "please choose ascending or descending order: " << endl;
        cout << " 1 -- ascending by ID" << endl;
        cout << " 2 -- descending by ID" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->employeeNumber; i++) {
            int minOrMax = i;
            for (int j = i + 1; j < this->employeeNumber; j++) {
                if (select == 1) {
                    if (this->employeeArr[minOrMax]->workID > this->employeeArr[j]->workID) {
                        minOrMax = j;
                    }
                } else {
                    if (this->employeeArr[minOrMax]->workID < this->employeeArr[j]->workID) {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax) {
                worker *temp = this->employeeArr[i];
                this->employeeArr[i] = this->employeeArr[i + 1];
                this->employeeArr[i + 1] = temp;
            }
        }
    }
    cout << "sort successful! result below: " << endl;
    this->save();
    this->showEmp();
}

void workerManager::cleanFile() {
    cout << "are you sure clean the whole file?" << endl;
    cout << "1 -- Yes,do it!" << endl;
    cout << "2 -- No, go back!" << endl;

    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs(("/Users/robin/CLionProjects/Employee_Management_System"), ios::trunc);
        ofs.close();

        if (this->isFileEmpty != NULL) {
            for (int i = 0; i < this->employeeNumber; i++) {
                delete this->employeeArr[i];
                this->employeeArr = NULL;
            }
            delete[] this->employeeArr;
            this->employeeArr = NULL;
            this->employeeNumber = 0;
            this->isFileEmpty = true;
        }
        cout << "clean successful!" << endl;
    }
}

workerManager::~workerManager() {
    if (this->employeeArr != NULL) {
        for (int i = 0; i < this->employeeNumber; i++) {
            if (this->employeeArr != NULL) {
                delete this->employeeArr[i];
            }
        }
        delete[]this->employeeArr;
        this->employeeArr = NULL;
    }
}


