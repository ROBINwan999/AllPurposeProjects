#include <fstream>
#include <iostream>
#include <map>
#include <iomanip>
#include "StudentManager.h"

using namespace std;

StudentManager::StudentManager() {
    readFile();
}

void StudentManager::readFile() {
    ifstream inFile("input.txt");
    string tmp;
    getline(inFile, tmp);

    Student stu;
    while (inFile.good()) {
        getline(inFile, tmp, ',');
        stu.setId(stoi(tmp));
        getline(inFile, tmp, ',');
        stu.setName(tmp);
        getline(inFile, tmp, ',');
        stu.setMath(stoi(tmp));
        getline(inFile, tmp, ',');
        stu.setEnglish(stoi(tmp));
        getline(inFile, tmp, ',');
        stu.setC(stoi(tmp));
        getline(inFile, tmp, '\n');
        stu.setDataStructure(stoi(tmp));
        inFile.peek();

        students_.push_back(stu);
    }

    inFile.close();
}

void StudentManager::printMenu() {
    cout << "************************************\n";
    cout << "欢迎来到学生成绩分析系统！\n";
    cout << "1. 各科成绩排名\n";
    cout << "2. 平均分排名\n";
    cout << "3. 均分，最高分，最低分，各分数区间人数\n";
    cout << "4. 平均绩点\n";
    cout << "5. 通过姓名查成绩\n";
    cout << "6. 通过学号查成绩\n";
    cout << "7. 添加学生\n";
    cout << "8. 删除学生\n";
    cout << "0. 退出系统\n";
    cout << "************************************\n";
}

void StudentManager::menuOption() {
    int user_selection = 0;

    while (true) {
        printMenu();
        cout << "请输出您的选择：\n";
        cin >> user_selection;
        if (cin.fail()) {
            cout << "输入错误！\n";
            exit(0);
        }

        switch (user_selection) {
            case 1:
                menuOption1();
                break;
            case 2:
                menuOption2();
                break;
            case 3:
                menuOption3();
                break;
            case 4:
                menuOption4();
                break;
            case 5:
                menuOption5();
                break;
            case 6:
                menuOption6();
                break;
            case 7:
                menuOption7();
                break;
            case 8:
                menuOption8();
                break;
            case 0:
                cout << "感谢使用，欢迎下次光临！\n";
                exit(0);
            default:
                cout << "输入错误选项,请重新输入！\n";
                break;
        }
    }
}

void StudentManager::mathRanking() {
    for (int i = 0; i < students_.size() - 1; ++i) {
        for (int j = 0; j < students_.size() - i - 1; ++j) {
            if (students_[j].getMath() < students_[j + 1].getMath()) {
                swap(students_[j], students_[j + 1]);
            }
        }
    }

    cout << "数学成绩排名:\n";
    for (int i = 0; i < students_.size(); ++i) {
        cout << "第" << i + 1 << "名: " << students_[i].getName() << " 数学成绩: " << students_[i].getMath() << "\n";
    }
}

void StudentManager::EnglishRanking() {
    for (int i = 0; i < students_.size() - 1; ++i) {
        for (int j = 0; j < students_.size() - i - 1; ++j) {
            if (students_[j].getEnglish() < students_[j + 1].getEnglish()) {
                swap(students_[j], students_[j + 1]);
            }
        }
    }

    cout << "英语成绩排名:\n";
    for (int i = 0; i < students_.size(); ++i) {
        cout << "第" << i + 1 << "名: " << students_[i].getName() << " 英语成绩: " << students_[i].getEnglish() << "\n";
    }
}

void StudentManager::CRanking() {
    for (int i = 0; i < students_.size() - 1; ++i) {
        for (int j = 0; j < students_.size() - i - 1; ++j) {
            if (students_[j].getC() < students_[j + 1].getC()) {
                swap(students_[j], students_[j + 1]);
            }
        }
    }

    cout << "C语言成绩排名:\n";
    for (int i = 0; i < students_.size(); ++i) {
        cout << "第" << i + 1 << "名: " << students_[i].getName() << " C语言成绩: " << students_[i].getC() << "\n";
    }
}

void StudentManager::dataStructureRanking() {
    for (int i = 0; i < students_.size() - 1; ++i) {
        for (int j = 0; j < students_.size() - i - 1; ++j) {
            if (students_[j].getDataStructure() < students_[j + 1].getDataStructure()) {
                swap(students_[j], students_[j + 1]);
            }
        }
    }

    cout << "数据结构成绩排名:\n";
    for (int i = 0; i < students_.size(); ++i) {
        cout << "第" << i + 1 << "名: " << students_[i].getName() << " 数据结构成绩: " << students_[i].getDataStructure()
             << "\n";
    }
}

void StudentManager::menuOption1() {
    mathRanking();
    EnglishRanking();
    CRanking();
    dataStructureRanking();
}

void StudentManager::averageRanking() {
    map<string, int> average_ranking;

    for (auto stu: students_) {
        int avg = (stu.getMath() + stu.getEnglish() + stu.getC() + stu.getDataStructure()) / 4;
        average_ranking.insert({stu.getName(), avg});
    }

    cout << "平均成绩排名:\n";
    int idx = 1;
    for (auto i: average_ranking) {
        cout << "第" << idx << "名: " << i.first << " 平均分: " << i.second << "\n";
        idx++;
    }
}

void StudentManager::menuOption2() {
    averageRanking();
}

int StudentManager::highestMath() {
    int max = INT_MIN;
    for (auto &student: students_) {
        if (student.getMath() > max) {
            max = student.getMath();
        }
    }

    return max;
}

int StudentManager::lowestMath() {
    int min = INT_MAX;
    for (auto &student: students_) {
        if (student.getMath() < min) {
            min = student.getMath();
        }
    }

    return min;
}

int StudentManager::highestEnglish() {
    int max = INT_MIN;
    for (auto &student: students_) {
        if (student.getEnglish() > max) {
            max = student.getEnglish();
        }
    }

    return max;
}

int StudentManager::lowestEnglish() {
    int min = INT_MAX;
    for (auto &student: students_) {
        if (student.getEnglish() < min) {
            min = student.getEnglish();
        }
    }

    return min;
}

int StudentManager::highestC() {
    int max = INT_MIN;
    for (auto &student: students_) {
        if (student.getC() > max) {
            max = student.getC();
        }
    }

    return max;
}

int StudentManager::lowestC() {
    int min = INT_MAX;
    for (auto &student: students_) {
        if (student.getC() < min) {
            min = student.getC();
        }
    }

    return min;
}

int StudentManager::highestDataStructure() {
    int max = INT_MIN;
    for (auto &student: students_) {
        if (student.getDataStructure() > max) {
            max = student.getDataStructure();
        }
    }

    return max;
}

int StudentManager::lowestDataStructure() {
    int min = INT_MAX;
    for (auto &student: students_) {
        if (student.getDataStructure() < min) {
            min = student.getDataStructure();
        }
    }

    return min;
}

vector<int> StudentManager::subjectAverage() {
    int math_sum = 0;
    int English_sum = 0;
    int C_sum = 0;
    int data_structure_sum = 0;

    for (auto &student: students_) {
        math_sum += student.getMath();
        English_sum += student.getEnglish();
        C_sum += student.getC();
        data_structure_sum += student.getDataStructure();
    }

    vector<int> avg;
    int size = (int) students_.size();
    avg.push_back(math_sum / size);
    avg.push_back(English_sum / size);
    avg.push_back(C_sum / size);
    avg.push_back(data_structure_sum / size);

    return avg;
}

vector<int> StudentManager::below60() {
    int math_count = 0;
    int English_count = 0;
    int C_count = 0;
    int data_structure_count = 0;

    for (auto &student: students_) {
        if (student.getMath() < 60)
            math_count++;
        if (student.getEnglish() < 60)
            English_count++;
        if (student.getC() < 60)
            C_count++;
        if (student.getDataStructure() < 60)
            data_structure_count++;
    }

    vector<int> below60;
    below60.push_back(math_count);
    below60.push_back(English_count);
    below60.push_back(C_count);
    below60.push_back(data_structure_count);

    return below60;
}

vector<int> StudentManager::between60to69() {
    int math_count = 0;
    int English_count = 0;
    int C_count = 0;
    int data_structure_count = 0;

    for (auto &student: students_) {
        if (student.getMath() >= 60 && student.getMath() < 70)
            math_count++;
        if (student.getEnglish() >= 60 && student.getEnglish() < 70)
            English_count++;
        if (student.getC() >= 60 && student.getC() < 70)
            C_count++;
        if (student.getDataStructure() >= 60 && student.getDataStructure() < 70)
            data_structure_count++;
    }

    vector<int> between60to69;
    between60to69.push_back(math_count);
    between60to69.push_back(English_count);
    between60to69.push_back(C_count);
    between60to69.push_back(data_structure_count);

    return between60to69;
}

vector<int> StudentManager::between79to79() {
    int math_count = 0;
    int English_count = 0;
    int C_count = 0;
    int data_structure_count = 0;

    for (auto &student: students_) {
        if (student.getMath() >= 70 && student.getMath() < 80)
            math_count++;
        if (student.getEnglish() >= 70 && student.getEnglish() < 80)
            English_count++;
        if (student.getC() >= 70 && student.getC() < 80)
            C_count++;
        if (student.getDataStructure() >= 70 && student.getDataStructure() < 80)
            data_structure_count++;
    }

    vector<int> between79to79;
    between79to79.push_back(math_count);
    between79to79.push_back(English_count);
    between79to79.push_back(C_count);
    between79to79.push_back(data_structure_count);

    return between79to79;
}

vector<int> StudentManager::between80to89() {
    int math_count = 0;
    int English_count = 0;
    int C_count = 0;
    int data_structure_count = 0;

    for (auto &student: students_) {
        if (student.getMath() >= 80 && student.getMath() < 90)
            math_count++;
        if (student.getEnglish() >= 80 && student.getEnglish() < 90)
            English_count++;
        if (student.getC() >= 80 && student.getC() < 90)
            C_count++;
        if (student.getDataStructure() >= 80 && student.getDataStructure() < 90)
            data_structure_count++;
    }

    vector<int> between80to89;
    between80to89.push_back(math_count);
    between80to89.push_back(English_count);
    between80to89.push_back(C_count);
    between80to89.push_back(data_structure_count);

    return between80to89;
}

vector<int> StudentManager::above90() {
    int math_count = 0;
    int English_count = 0;
    int C_count = 0;
    int data_structure_count = 0;

    for (auto &student: students_) {
        if (student.getMath() > 90)
            math_count++;
        if (student.getEnglish() > 90)
            English_count++;
        if (student.getC() > 90)
            C_count++;
        if (student.getDataStructure() > 90)
            data_structure_count++;
    }

    vector<int> above90;
    above90.push_back(math_count);
    above90.push_back(English_count);
    above90.push_back(C_count);
    above90.push_back(data_structure_count);

    return above90;
}

void StudentManager::menuOption3() {
    int max_math = highestMath();
    int min_math = lowestMath();
    int max_English = highestEnglish();
    int min_English = lowestEnglish();
    int max_C = highestC();
    int min_C = lowestC();
    int max_data_structure = highestDataStructure();
    int min_data_structure = lowestDataStructure();
    vector<int> avg = subjectAverage();
    vector<int> below60_ = below60();
    vector<int> between60to69_ = between60to69();
    vector<int> between79to79_ = between79to79();
    vector<int> between80to89_ = between80to89();
    vector<int> above90_ = above90();

    cout << "\t平均成绩\t最高分\t最低分\t不及格人数\t60～69分人数\t70～79分人数\t80～89分人数\t90分以上人数\n";
    cout << "数学\t\t" << avg[0] << "\t\t" << max_math << "\t\t" << min_math << "\t\t" << below60_[0] << "\t\t\t"
         << between60to69_[0] << "\t\t\t" << between79to79_[0] << "\t\t\t" << between80to89_[0] << "\t\t\t"
         << above90_[0]
         << "\n";
    cout << "英语\t\t" << avg[1] << "\t\t" << max_English << "\t\t" << min_English << "\t\t" << below60_[1] << "\t\t\t"
         << between60to69_[1]
         << "\t\t\t" << between79to79_[1] << "\t\t\t" << between80to89_[1] << "\t\t\t" << above90_[1] << "\n";
    cout << "C语言\t" << avg[2] << "\t\t" << max_C << "\t\t" << min_C << "\t\t" << below60_[2] << "\t\t\t"
         << between60to69_[2]
         << "\t\t\t" << between79to79_[2] << "\t\t\t" << between80to89_[2] << "\t\t\t" << above90_[2] << "\n";
    cout << "数据结构\t" << avg[3] << "\t\t" << max_data_structure << "\t\t" << min_data_structure << "\t\t"
         << below60_[3] << "\t\t\t"
         << between60to69_[3] << "\t\t\t" << between79to79_[3] << "\t\t\t" << between80to89_[3] << "\t\t\t"
         << above90_[3] << "\n";
}

void StudentManager::getGpa() {
    map<string, double> gpa;
    double math_gpa, English_gpa, C_gpa, data_structure_gpa;
    for (auto stu: students_) {
        math_gpa = ((double) stu.getMath() / 100) * 5;
        English_gpa = ((double) stu.getEnglish() / 100) * 5;
        C_gpa = ((double) stu.getC()) / 100 * 5;
        data_structure_gpa = ((double) stu.getDataStructure()) / 100 * 5;
        gpa.insert({stu.getName(), (math_gpa + English_gpa + C_gpa + data_structure_gpa) / 4});
    }

    cout << "学生姓名\t\t平均绩点\n";
    for (auto i: gpa) {
        cout << i.first << "\t\t\t" << setprecision(3) << i.second << "\n";
    }
}

void StudentManager::menuOption4() {
    getGpa();
}

string StudentManager::getName() {
    string name;

    cout << "请输入要查询的学生姓名:\n";
    cin >> name;
    if (cin.fail()) {
        cout << "错误姓名!";
        exit(0);
    }

    return name;
}

void StudentManager::menuOption5() {
    string name = getName();
    bool flag = false;

    for (auto stu: students_) {
        if (stu.getName() == name) {
            flag = true;
            cout << stu << "\n";
        }
    }

    if (!flag) {
        cout << "您要查询的学生号不存在!\n";
    }
}

int StudentManager::getSid() {
    int id;

    cout << "请输入要查询的学生ID:\n";
    cin >> id;

    return id;
}

void StudentManager::menuOption6() {
    int id = getSid();
    bool flag = false;

    for (auto stu: students_) {
        if (stu.getId() == id) {
            flag = true;
            cout << stu << "\n";
        }
    }

    if (!flag) {
        cout << "您要查询的学生号不存在!\n";
    }
}

int StudentManager::getMath() {
    int math;

    cout << "请输入数学成绩:\n";
    cin >> math;
    if (math < 0 || math > 100) {
        cout << "错误成绩！";
        exit(0);
    }

    return math;
}

int StudentManager::getEnglish() {
    int English;

    cout << "请输入英语成绩:\n";
    cin >> English;
    if (English < 0 || English > 100) {
        cout << "错误成绩！";
        exit(0);
    }

    return English;
}

int StudentManager::getC() {
    int C;

    cout << "请输入C语言成绩:\n";
    cin >> C;
    if (C < 0 || C > 100) {
        cout << "错误成绩！";
        exit(0);
    }

    return C;
}

int StudentManager::getDataStructure() {
    int data_structure;

    cout << "请输入数据结构成绩:\n";
    cin >> data_structure;
    if (data_structure < 0 || data_structure > 100) {
        cout << "错误成绩！";
        exit(0);
    }

    return data_structure;
}

void StudentManager::writeFile(const Student &stu) {
    ofstream outFile("input.txt", ios::ate | ios::app);
    outFile << '\n' << stu.getId() << ',' << stu.getName() << ','
            << stu.getMath() << ',' << stu.getEnglish() << ','
            << stu.getC() << ',' << stu.getDataStructure();
    outFile.close();
}

void StudentManager::createStudent() {
    Student stu;
    stu.setName(getName());
    stu.setMath(getMath());
    stu.setEnglish(getEnglish());
    stu.setC(getC());
    stu.setDataStructure(getDataStructure());
    stu.setId(students_[students_.size() - 1].getId() + 1);
    students_.push_back(stu);
    writeFile(stu);
    cout << "添加成功!\n";
}

void StudentManager::menuOption7() {
    createStudent();
}

void StudentManager::deleteStudent() {
    int id = getSid();
    int flag = false;

    for (int i = 0; i < students_.size(); ++i) {
        if (students_[i].getId() == id) {
            flag = true;
            remove(students_.begin(), students_.end(), students_[i]);
        }
        if (flag) {
            students_[i].setId(students_[i].getId() - 1);
        }
    }

    ofstream outFile("input.txt");
    outFile << "学号,姓名,高等数学,大学英语,C语言,数据结构";
    outFile.close();
    for (int i = 0; i < students_.size() - 1; ++i) {
        writeFile(students_[i]);
    }
    cout << "删除成功！\n";

    if (!flag) {
        cout << "您要删除的学生号不存在!";
        exit(0);
    }
}

void StudentManager::menuOption8() {
    deleteStudent();
}


