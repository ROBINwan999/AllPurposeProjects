#include "speechManager.h"

speechManager::speechManager() {
    this->initSpeech();
    this->createSpeaker();
}

void speechManager::showMenu() {
    cout << "*********************************" << endl;
    cout << "*** Welcome to speech contest ***" << endl;
    cout << "**** 1. Start speech contest ****" << endl;
    cout << "**** 2. Watch record contest ****" << endl;
    cout << "**** 3. Clean contest record ****" << endl;
    cout << "**** 0. Quit contest program ****" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

void speechManager::exitSystem() {
    cout << "Welcome back next time!" << endl;
    exit(0);
}

void speechManager::initSpeech() {
    //empty all container
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->Aspeaker.clear();

    //initialize round number
    this->index = 1;
    this->record.clear();
}

void speechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "speaker";
        name += nameSeed[i];

        speaker sp;
        sp.name = name;
        for (int j = 0; j < 2; j++) {
            sp.score[j] = 0;
        }
        this->v1.push_back(i + 10001);
        this->Aspeaker.insert(make_pair(i + 10001, sp));

    }
}

void speechManager::startSpeech() {
    //round 1
    this->speechDraw();
    this->speechContest();
    this->showScore();

    //round 2
    this->index++;
    this->speechDraw();
    speechContest();
    this->showScore();
    this->saveRecord();
    cout << "This contest is now finished!" << endl;

    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();

}

void speechManager::speechDraw() {
    cout << "round number " << this->index << " speaker is drawing" << endl;
    cout << "------------------" << endl;
    cout << "after drawing, the order aer below: " << endl;

    if (this->index == 1) {
        //round 1
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
            cout << *it << " ";
        }
    } else {
        //round 2
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

void speechManager::speechContest() {
    cout << "--------- The round " << this->index << " speech contest start right now!" << endl;

    multimap<double, int, greater<double>> groupScore;//temporary group score

    int num = 0;//record number of people, 6 people is 1 group

    vector<int> src; //container for all speakers

    if (this->index == 1) {
        src = v1;
    } else {
        src = v2;
    }

    for (vector<int>::iterator it = src.begin(); it != src.end(); it++) {
        num++;
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = rand() % 401 + 600 / 10.f;
            cout << score << " ";
            d.push_back(score);
        }
        cout << endl;
        sort(d.begin(), d.end(), greater<double>());//sorting
        d.pop_back();//get rid of min
        d.pop_front();//get rid of max

        double sum = accumulate(d.begin(), d.end(), 0);//total score
        double avg = sum / (double) d.size();//average score
        cout << "number: " << *it << "\tname: " << this->Aspeaker[*it].name << "\taverage score: " << avg << endl;
        this->Aspeaker[*it].score[this->index - 1] = avg;
        groupScore.insert(make_pair(avg, *it));//key is score,value is speaker number
        if (num % 6 == 0) {
            cout << "number " << num / 6 << " group ranking: " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end(); it++) {
                cout << "number: " << it->second << "\tname: " << this->Aspeaker[it->second].name
                     << "\tscore: " << this->Aspeaker[it->second].score[this->index - 1] << endl;
            }
            int count = 0;//take first 3
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it++, count++) {
                if (this->index == 1) {
                    v2.push_back((*it).second);
                } else {
                    victory.push_back((*it).second);
                }
            }
            groupScore.clear();
        }
    }
    cout << "----- round " << this->index << " contest finished! -----" << endl;
}

void speechManager::showScore() {
    cout << "----- round " << this->index << "  qualifying speaker information as below: -----" << endl;
    vector<int> v;
    if (this->index == 1) {
        v = v2;
    } else {
        v = victory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "number: " << *it << "\tname: " << this->Aspeaker[*it].name
             << "\tscore: " << this->Aspeaker[*it].score[this->index - 1] << endl;
    }
    cout << endl;
    this->showMenu();
}

void speechManager::saveRecord() {
    ofstream ofs;
    ofs.open(("/Users/robin/CLionProjects/Speech Contest Process Management System/speech.csv"), ios::out | ios::app);
    for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++) {
        ofs << *it << "," << this->Aspeaker[*it].score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "Record is saved!" << endl;

    this->isFileEmpty = false;
}

void speechManager::loadRecord() {
    ifstream ifs(("/Users/robin/CLionProjects/Speech Contest Process Management System/speech.csv"), ios::in);

    if (!ifs.is_open()) {
        this->isFileEmpty = true;
        //cout << "file is empty!" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->isFileEmpty = true;
        //cout << "file is empty!" << endl;
        ifs.close();
        return;
    }

    this->isFileEmpty = false;
    ifs.putback(ch);
    string data;
    int index = 0;
    while (ifs >> data) {
        vector<string> v;//store 6 strings
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                //do not find
                break;
            }
            string temp = data.substr(start, pos - start);
            v.push_back(temp);
            start = pos + 1;
        }
        this->record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}

void speechManager::showRecord() {
    if (this->isFileEmpty) {
        cout << "file does not exist or is empty!" << endl;
    } else {
        for (int i = 0; i < this->record.size(); i++) {
            cout << "The " << i + 1 << " generation contest: " << endl;
            cout << "First champion: " << this->record[i][0] << " Score: " << this->record[i][1] << endl;
            cout << "Second champion: " << this->record[i][2] << " Score: " << this->record[i][3] << endl;
            cout << "Third champion: " << this->record[i][4] << " Score: " << this->record[i][5] << endl;
        }
    }
}

void speechManager::clearRecord() {
    cout << "Are you sure want to clean record?" << endl;
    cout << "1 -- Yes" << endl;
    cout << "2 -- No" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
        ofstream ofs(("/Users/robin/CLionProjects/Speech Contest Process Management System/speech.csv"), ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        cout << "clean successful!" << endl;
    }
}

speechManager::~speechManager() {

}
