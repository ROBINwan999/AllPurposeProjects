#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>


using namespace std;

class speechManager {

public:
    speechManager();

    virtual ~speechManager();

    void showMenu();//print options

    void exitSystem();//quit program

    void initSpeech();//initialize speech

    void createSpeaker();//create 12 speakers

    void startSpeech();//start

    void speechDraw();//roll

    void speechContest();//contest

    void showScore();//print score

    void saveRecord();//save score in file

    void showRecord();//show the record

    void clearRecord();//clean record

    void loadRecord();//read record
    bool isFileEmpty;//check is file empty
    map<int, vector<string>> record;//container for the record

    vector<int> v1;//save speaker number for round 1
    vector<int> v2;//save all victory speaker number from round 1
    vector<int> victory;//save first 3 victory speaker number from all victories
    map<int, speaker> Aspeaker;//save all speaker and number
    int index;//save round number



};

