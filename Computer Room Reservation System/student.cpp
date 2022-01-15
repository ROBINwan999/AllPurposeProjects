
#include "student.h"

student::student() {}

student::student(int id, string name, string pwd) {
    this->id = id;
    this->name = name;
    this->pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    computerRoom com;
    while (ifs >> com.comID && ifs >> com.MaxNum) {
        vCom.push_back(com);
    }
    ifs.close();
}

void student::openMenu() {
    cout << "Welcome for student: " << this->name << " to login!" << endl;
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|         1. Apply for booking      |\n";
    cout << "\t\t|         2. Check my booking       |\n";
    cout << "\t\t|         3. Check all booking      |\n";
    cout << "\t\t|         4. Cancel my booking      |\n";
    cout << "\t\t|         0. Log out                |\n";
    cout << "\t\t-------------------------------------\n";
    cout << "Please enter your option: " << endl;
}

void student::applyOrder() {
    cout << "Computer room open from Monday to Friday" << endl;
    cout << "Please enter booking day: " << endl;
    cout << "1 -- Monday" << endl;
    cout << "2 -- Tuesday" << endl;
    cout << "3 -- Wednesday" << endl;
    cout << "4 -- Thursday" << endl;
    cout << "5 -- Friday" << endl;

    int date;
    int interval = 0;//AM or PM
    int room = 0;

    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "Wrong input! please enter again: " << endl;
    }

    cout << "Please enter booking interval: " << endl;
    cout << "1 -- Morning" << endl;
    cout << "2 -- Afternoon" << endl;

    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "Wrong input! please enter again: " << endl;
    }

    cout << "Please choose a computer room: " << endl;
    for (int i = 0; i < vCom.size(); i++) {
        cout << vCom[i].comID << " -- computer room max capacity is: " << vCom[i].MaxNum << endl;
    }
    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "Wrong input! please enter again: " << endl;
    }
    cout << "Booking successful! it is pending now." << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "Date:" << date << " ";
    ofs << "Interval:" << interval << " ";
    ofs << "StudentID:" << this->id << " ";
    ofs << "StudentName:" << this->name << " ";
    ofs << "RoomID:" << room << " ";
    ofs << "Status:" << 1 << endl;

    ofs.close();
}

void student::showOrder() {
    orderFile of;
    orderFile();
    if (of.size = 0) {
        cout << "No booking record!" << endl;
        return;
    }

    for (int i = 0; i < of.size; i++) {
        if (this->id == stoi(of.orderData[i]["studentID"])) {
            cout << "Booking date: " << of.orderData[i]["date"];
            cout << "Interval: " << (of.orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
            cout << "RoomID: " << of.orderData[i]["roomID"];
            string status;
            if (of.orderData[i]["status"] == "1") {
                status += "Pending";
            } else if (of.orderData[i]["status"] == "2") {
                status += "Booking successful!";
            } else if (of.orderData[i]["status"] == "-1") {
                status += "Booking failed! not pass pending";
            } else {
                status += "Booking canceled!";
            }
            cout << status << endl;
        }
    }
}

void student::showAllOrder() {
    orderFile of;
    if (of.size == 0) {
        cout << "No booking record!" << endl;
        return;
    }
    for (int i = 0; i < of.size; i++) {
        cout << i + 1 << ", ";
        cout << "Date: " << of.orderData[i]["date"];
        cout << "Interval: " << (of.orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
        cout << "StudentID: " << of.orderData[i]["StudentID"];
        cout << "StudentName: " << of.orderData[i]["StudentName"];
        cout << "RoomID: " << of.orderData[i]["roomID"];
        string status;
        if (of.orderData[i]["status"] == "1") {
            status += "Pending";
        } else if (of.orderData[i]["status"] == "2") {
            status += "Booking successful!";
        } else if (of.orderData[i]["status"] == "-1") {
            status += "Booking failed! not pass pending";
        } else {
            status += "Booking canceled!";
        }
        cout << status << endl;
    }
}

void student::cancelOrder() {
    orderFile of;
    if (of.size == 0) {
        cout << "No booking record!" << endl;
        return;
    }
    cout << "Pending and successful booking record can be canceled, please enter your option:  " << endl;
    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.size; i++) {
        if (this->id == stoi(of.orderData[i]["StudentID"])) {
            if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2") {
                v.push_back(i);
                cout << index++ << ", ";
                cout << "Booking date: " << of.orderData[i]["date"];
                cout << "Interval: " << (of.orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
                cout << "RoomID: " << of.orderData[i]["roomID"];
                string status;
                if (of.orderData[i]["status"] == "1") {
                    status += "Pending";
                } else if (of.orderData[i]["status"] == "2") {
                    status += "Booking successful!";
                } else if (of.orderData[i]["status"] == "-1") {
                    status += "Booking failed! not pass pending";
                } else {
                    status += "Booking canceled!";
                }
                cout << status << endl;
            }
        }

    }
    cout << "Please enter cancel record, 0 for return" << endl;
    int select = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= 3) {
            if (select == 0) {
                break;
            } else {
                of.orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "Booking canceled!" << endl;
                break;
            }
        }
    }
}
