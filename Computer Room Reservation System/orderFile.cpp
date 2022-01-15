#include "orderFile.h"

orderFile::orderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;
    string interval;
    string studentID;
    string studentName;
    string roomID;
    string status;

    this->size = 0;

    while (ifs >> date && ifs >> interval && ifs >> studentID && ifs >> studentName && ifs >> roomID && ifs >> status) {
        cout << date << " ";
        cout << interval << " ";
        cout << studentID << " ";
        cout << studentName << " ";
        cout << roomID << " ";
        cout << status << " ";
        cout << endl;

        string key;
        string value;
        map<string, string> m;

        int pos = date.find(":");
        if (pos != -1) {
            key = date.substr(0, 4);
            value = date.substr(pos + 1, date.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = interval.find(":");
        if (pos != -1) {
            key = interval.substr(0, 4);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = studentID.find(":");
        if (pos != -1) {
            key = studentID.substr(0, 4);
            value = studentID.substr(pos + 1, studentID.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = studentName.find(":");
        if (pos != -1) {
            key = studentName.substr(0, 4);
            value = studentName.substr(pos + 1, studentName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = roomID.find(":");
        if (pos != -1) {
            key = roomID.substr(0, 4);
            value = roomID.substr(pos + 1, roomID.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = status.find(":");
        if (pos != -1) {
            key = status.substr(0, 4);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        this->orderData.insert(make_pair(this->size, m));
        this->size++;

    }
    ifs.close();

}

void orderFile::updateOrder() {
    if (this->size == 0) {
        return;
    }
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < this->size; i++) {
        ofs << "date: " << this->orderData[i]["date"] << " ";
        ofs << "interval: " << this->orderData[i]["interval"] << " ";
        ofs << "studentID: " << this->orderData[i]["studentID"] << " ";
        ofs << "studentName: " << this->orderData[i]["studentName"] << " ";
        ofs << "roomID: " << this->orderData[i]["roomID"] << " ";
        ofs << "status: " << this->orderData[i]["status"] << " ";
    }
    ofs.close();
}
