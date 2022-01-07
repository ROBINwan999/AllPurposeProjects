#include <iostream>
#include "speechManager.h"
#include <string>
#include <ctime>

using namespace std;

int main() {

    speechManager sm;
    int choice = 0;
    cout << "please enter your choice: " << endl;
    srand((unsigned int) time(NULL));

    while (true) {
        sm.showMenu();
        cout << "please enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
            case 1://start contest
                sm.startSpeech();
                break;
            case 2://watch record
                sm.showRecord();
                break;
            case 3://clean record
                sm.clearRecord();
                break;
            case 0://quit program
                sm.exitSystem();
                break;
            default:
                break;
        }
    }

    return 0;
}
