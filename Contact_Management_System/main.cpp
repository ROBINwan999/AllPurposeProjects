#include <iostream>
#include <string>

using namespace std;

struct person {
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct contactBook {
    struct person personArr[1000];

    int size;
};

void addPerson(contactBook *cb) {
    if (cb->size == 1000) {
        cout << "contact book is full, can not add!" << endl;
    } else {
        string name;
        cout << "please enter name: " << endl;
        cin >> name;
        cb->personArr[cb->size].name = name;

        cout << "please enter sex: " << endl;
        cout << "1 -- male" << endl;
        cout << "2 -- female" << endl;
        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                cb->personArr[cb->size].sex = sex;
                break;
            } else {
                cout << "wrong sex, please enter again" << endl;
            }
        }
        cout << "please enter age: " << endl;
        int age = 0;
        while (true) {
            cin >> age;
            if (age < 0 || age > 120) {
                cout << "wrong age, please enter again" << endl;
            } else {
                cb->personArr[cb->size].age = age;
                break;
            }
        }
        cout << "please enter phone number: " << endl;
        string phone;
        cin >> phone;
        cb->personArr[cb->size].phone = phone;

        cout << "please enter address: " << endl;
        string address;
        cin >> address;
        cb->personArr[cb->size].address = address;

        cb->size++;

        cout << "add successful!" << endl;

    }
}

void showPerson(contactBook *cb) {
    if (cb->size == 0) {
        cout << "it is empty right now!" << endl;
    } else {
        for (int i = 0; i < cb->size; i++) {
            cout << "name: " << cb->personArr->name << "\t";
            cout << "sex: " << (cb->personArr->sex == 1 ? "male" : "femail") << "\t";
            cout << "age: " << cb->personArr->age << "\t";
            cout << "phone: " << cb->personArr->phone << "\t";
            cout << "address: " << cb->personArr->address << endl;

        }
    }
}

int isExist(contactBook *cb, string name) {
    for (int i = 0; i < cb->size; i++) {
        if (cb->personArr[i].name == name) {
            return i;
        }
    }
    return -1;
}

void deletePerson(contactBook *cb) {
    cout << "please enter name for delete: " << endl;

    string name;
    cin >> name;

    int result = isExist(cb, name);

    if (result != -1) {
        for (int i = 0; i < cb->size; i++) {
            cb->personArr[i] = cb->personArr[i + 1];
        }
        cb->size--;
        cout << "delete successful!" << endl;
    } else {
        cout << "person do not exist!" << endl;
    }
}

void findPerson(contactBook *cb) {
    cout << "enter name for searching: " << endl;
    string name;
    cin >> name;
    int result = isExist(cb, name);
    if (result != -1) {
        cout << "name: " << cb->personArr[result].name << "\t";
        cout << "sex: " << cb->personArr[result].sex << "\t";
        cout << "age: " << cb->personArr[result].age << "\t";
        cout << "phone: " << cb->personArr[result].phone << "\t";
        cout << "address: " << cb->personArr[result].address << endl;
    } else {
        cout << "can not find this person!" << endl;
    }
}

void changePerson(contactBook *cb) {
    cout << "please enter name for modify: " << endl;
    string name;
    cin >> name;
    int result = isExist(cb, name);
    if (result != -1) {
        string name;
        cout << "please enter the name: " << endl;
        cin >> name;
        cb->personArr[result].name = name;

        int sex = 0;
        cout << "please enter sex: " << endl;
        cout << "1 -- male" << endl;
        cout << "2 -- female" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                cb->personArr[result].sex = sex;
                break;
            } else {
                cout << "wrong sex, please enter again: " << endl;
            }
        }

        int age;
        cout << "please enter age: " << endl;
        while (true) {
            cin >> age;
            if (age < 0 || age > 120) {
                cout << "wrong age, please enter again: " << endl;
            } else {
                cb->personArr[result].age = age;
                break;
            }
        }

        cout << "please enter phone number: " << endl;
        string phone;
        cin >> phone;
        cb->personArr[result].phone = phone;

        cout << "please enter address: " << endl;
        string address;
        cin >> address;
        cb->personArr[result].address = address;
    } else {
        cout << "can not find this person!" << endl;
    }
}

void cleanPerson(contactBook *cb) {
    cb->size = 0;
    cout << "contact book is empty now!" << endl;
}

void showMenu() {
    cout << "1. add contact" << endl;
    cout << "2. show contact" << endl;
    cout << "3. delete contact" << endl;
    cout << "4. find contact" << endl;
    cout << "5. change contact" << endl;
    cout << "6. empty contact" << endl;
    cout << "0. exit contact" << endl;
}

int main() {

    contactBook cb;

    cb.size = 0;

    int select = 0; ///user input variable

    while (true) {
        showMenu();
        cin >> select;

        switch (select) {
            case 1:///add
                addPerson(&cb);
                break;
            case 2:///show
                showPerson(&cb);
                break;
            case 3: ///delete
                deletePerson(&cb);
                break;
            case 4:///find
                findPerson(&cb);
                break;
            case 5:///change
                changePerson(&cb);
                break;
            case 6:///empty
                cleanPerson(&cb);
                break;
            case 0:///exit
                cout << "welcome back next time" << endl;
                return 0;
                break;
            default:
                break;
        }
    }


    return 0;
}
