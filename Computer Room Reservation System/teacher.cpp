#include "teacher.h"

teacher::teacher() {}

teacher::teacher(int id, string name, string pwd) {
    this->id = id;
    this->name = name;
    this->pwd = pwd;
}

void teacher::openMenu() {
    cout << "Welcome for teacher: " << this->name << " to login!" << endl;
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|         1. Check all booking      |\n";
    cout << "\t\t|         2. Pending booking       |\n";
    cout << "\t\t|         0. Log out                |\n";
    cout << "\t\t-------------------------------------\n";
    cout << "Please enter your option: " << endl;
}

void teacher::showAllOrder() {
    orderFile of;
    orderFile();
    if (of.size = 0) {
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

void teacher::validOrder() {
    orderFile of;
    orderFile();
    if (of.size = 0) {
        cout << "No booking record!" << endl;
        return;
    }

    cout << "Record for pending booking as below: " << endl;
    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.size; i++) {
        if (of.orderData[i]["status"] == "1") {
            v.push_back(i);
            cout << index++ << ", ";
            cout << "Booking date: " << of.orderData[i]["date"];
            cout << "Interval: " << (of.orderData[i]["interval"] == "1" ? "Morning" : "Afternoon");
            cout << "StudentID: " << of.orderData[i]["StudentID"];
            cout << "StudentName: " << of.orderData[i]["StudentName"];
            cout << "RoomID: " << of.orderData[i]["roomID"];
            string status = "status: pending";
            cout << status << endl;
        }
    }
    cout << "Please enter record for pending booking, 0 for return" << endl;
    int select = 0;
    int ret = 0;
    while (true) {
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                cout << "Please enter pending result: " << endl;
                cout << "1 -- pass" << endl;
                cout << "2 -- not pass" << endl;
                cin >> ret;
                if (ret == 1) {
                    of.orderData[v[select - 1]]["status"] = "2";
                } else {
                    of.orderData[v[select - 1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "pending finished" << endl;
                break;
            }
        }

    }
}
