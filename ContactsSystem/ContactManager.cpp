#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "ContactManager.h"

using namespace std;

enum class user_options : int {
    add_contact = 1,
    delete_contact = 2,
    modify_contact = 3,
    search_contact = 4,
    print_contact = 5,
    clear_contact = 6,
    quit_system = 0
};

ContactManager::ContactManager() {
    readFile();
}

void ContactManager::readFile() {
    ifstream ifs("contact.csv");
    string temp;

    getline(ifs, temp);

    Address address;
    Contact contact;

    while (ifs.good()) {
        getline(ifs, temp, ',');
        contact.setName(temp);
        getline(ifs, temp, ',');
        contact.setGender(temp);
        getline(ifs, temp, ',');
        contact.setPhone(stol(temp));
        getline(ifs, temp, ',');
        address.setCity(temp);
        getline(ifs, temp, '\n');
        address.setCountry(temp);
        contact.setAddress(address);

        contact_list_.insert({contact.getName(), contact});
        ifs.peek();
    }

    ifs.close();
}

void ContactManager::printMenu() {
    cout << "*********************************\n";
    cout << "*\t\t欢迎来到通讯录管理系统!\t\t*\n";
    cout << "*\t\t1. 新增联系人\t\t\t\t*\n";
    cout << "*\t\t2. 删除联系人\t\t\t\t*\n";
    cout << "*\t\t3. 修改联系人\t\t\t\t*\n";
    cout << "*\t\t4. 查询联系人\t\t\t\t*\n";
    cout << "*\t\t5. 列出所有联系人\t\t\t*\n";
    cout << "*\t\t6. 清空联系人\t\t\t\t*\n";
    cout << "*\t\t0. 退出系统\t\t\t\t*\n";
    cout << "**********************************\n";
}

void ContactManager::menuOption() {
    int user_selection = 0;

    while (true) {
        printMenu();
        cout << "请输出你的选择:\n";
        cin >> user_selection;

        if (cin.fail()) {
            cout << "非法输入!\n";
            exit(0);
        }

        switch (user_selection) {
            case static_cast<int>(user_options::add_contact):
                addContact();
                break;
            case static_cast<int>(user_options::delete_contact):
                deleteContact();
                break;
            case static_cast<int>(user_options::modify_contact):
                modifyContact();
                break;
            case static_cast<int>(user_options::search_contact):
                searchContact();
                break;
            case static_cast<int>(user_options::print_contact):
                printContact();
                break;
            case static_cast<int>(user_options::clear_contact):
                clearContact();
                break;
            case static_cast<int>(user_options::quit_system):
                cout << "感谢使用，欢迎下次光临!\n";
                exit(0);
            default:
                cout << "请重新输入正确的选项!\n";
                break;
        }
    }
}

bool ContactManager::hasNumber(const string &str) {
    for (auto ch: str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

string ContactManager::createName() {
    string name;

    while (true) {
        cout << "请输入联系人姓名:\n";
        cin >> name;

        if (hasNumber(name))
            cout << "错误姓名，请重新输入正确姓名!\n";
        else
            return name;
    }
}

string ContactManager::chooseGender() {
    int select = 0;
    while (true) {
        cout << "1 --- 男\n";
        cout << "2 --- 女\n";
        cout << "请选择性别:\n";
        cin >> select;

        if (cin.fail()) {
            cout << "非法输入!\n";
            exit(0);
        }

        if (select == 1)
            return "Male";
        else if (select == 2)
            return "Female";
        else if (select != 1 && select != 2)//如果用户输入不是提供的选项
            cout << "请选择正确的选项!\n";
    }
}

size_t ContactManager::createPhone() {
    size_t phone = 0;
    cout << "请输入联系人手机号:\n";
    cin >> phone;

    if (cin.fail()) {
        cout << "非法输入!\n";
        exit(0);
    }

    return phone;
}

string ContactManager::addCity() {
    string city;

    while (true) {
        cout << "请输入联系人所在城市:\n";
        cin >> city;

        if (hasNumber(city))
            cout << "错误城市，请重新输入正确城市!\n";
        else
            return city;
    }
}

string ContactManager::addCountry() {
    string country;

    while (true) {
        cout << "请输入联系人所在国家:\n";
        cin >> country;

        if (hasNumber(country))
            cout << "错误国家，请重新输入正确国家!\n";
        else
            return country;
    }
}

bool ContactManager::isExist(const string &name) {
    for (auto i: contact_list_) {
        if (strcasecmp(i.first.c_str(), name.c_str()) == 0) {//忽略大小写比较
            return true;
        }
    }
    return false;
}

bool ContactManager::isContinue() {
    int select = 0;

    while (true) {
        cout << "该联系人姓名已存在，是否继续添加?\n";
        cout << "1 --- 是\n";
        cout << "2 --- 否\n";
        cout << "请选择:\n";
        cin >> select;

        if (select == 2)
            return false;
        else if (select == 1)
            return true;
        else if (!isdigit(select))
            cout << "请重新输入!\n";
        else if (select != 1 && select != 2)
            cout << "请输入正确选项!\n";
    }
}

void ContactManager::writeFile(const Contact &contact) {
    ofstream ofs("contact.csv", ios::app);

    ofs << contact.getName() << ',' << contact.getGender() << ','
        << contact.getPhone() << ',' << contact.getAddress().getCity() << ','
        << contact.getAddress().getCountry() << '\n';

    ofs.close();
}

void ContactManager::addContact() {
    Contact contact;
    Address address;

    string name = createName();

    if (isExist(name)) {
        if (!isContinue()) {
            return;
        }
    }

    contact.setName(name);
    contact.setGender(chooseGender());
    contact.setPhone(createPhone());

    address.setCity(addCity());
    address.setCountry(addCountry());
    contact.setAddress(address);

    contact_list_.insert({contact.getName(), contact});
    writeFile(contact);
    cout << "联系人添加成功!\n";
}

void ContactManager::deleteInFile(const string &name) {
    ifstream ifs("contact.csv");
    string data, line, temp;

    while (getline(ifs, line)) {
        stringstream ss(line);
        getline(ss, temp, ',');

        if (strcasecmp(temp.c_str(), name.c_str()) == 0)
            continue;
        else
            data += (line + '\n');
    }
    ifs.close();

    ofstream ofs("contact.csv");
    ofs.flush();
    ofs << data;
    ofs.close();
}

string ContactManager::getName(const string &name) {
    string origin_format_name;
    for (const auto &i: contact_list_) {
        if (strcasecmp(i.first.c_str(), name.c_str()) == 0) {//忽略大小写比较
            origin_format_name = i.first;
        }
    }
    return origin_format_name;
}

void ContactManager::deleteContact() {
    string name = createName();
    if (!isExist(name)) {
        cout << "联系人不存在!\n";
        return;
    }

    //1. 从内存（数据结构）中删除
    name = getName(name);
    contact_list_.erase(name);

    //2. 从硬盘（文件）中删除
    deleteInFile(name);

    cout << "联系人删除成功!\n";
}

void ContactManager::printContact() {
    cout << left << setw(20) << "姓名"
         << left << setw(20) << "性别"
         << left << setw(20) << "\t手机号"
         << left << setw(20) << "\t\t城市"
         << "国家\n";
    cout << "-----------------------------------------"
            "-----------------------------------\n";
    for (auto i: contact_list_) {
        cout << left << setw(12) << i.first << left << setw(6) << '|'
             << left << setw(12) << i.second.getGender() << left << setw(6) << '|'
             << left << setw(12) << i.second.getPhone() << left << setw(6) << '|'
             << left << setw(12) << i.second.getAddress().getCity() << left << setw(6) << '|'
             << i.second.getAddress().getCountry() << '\n';
    }
}


void ContactManager::modifyContact() {
    string name = createName();
    if (!isExist(name)) {
        cout << "联系人不存在!\n";
        return;
    }

    cout << "找到此联系人，开始进行修改!\n";
    name = getName(name);
    contact_list_.erase(name);
    deleteInFile(name);

    Contact contact;
    Address address;

    contact.setName(createName());
    contact.setGender(chooseGender());
    contact.setPhone(createPhone());

    address.setCity(addCity());
    address.setCountry(addCountry());
    contact.setAddress(address);

    contact_list_.insert({contact.getName(), contact});
    writeFile(contact);
    cout << "联系人修改成功!\n";
}

void ContactManager::searchContact() {
    string name = createName();
    if (!isExist(name)) {
        cout << "联系人不存在!\n";
        return;
    }

    name = getName(name);
    auto itr = contact_list_.find(name);

    cout << left << setw(20) << "姓名"
         << left << setw(20) << "性别"
         << left << setw(20) << "\t手机号"
         << left << setw(20) << "\t\t城市"
         << "国家\n";
    cout << "-----------------------------------------"
            "-----------------------------------\n";
    cout << left << setw(12) << itr->first << left << setw(6) << '|'
         << left << setw(12) << itr->second.getGender() << left << setw(6) << '|'
         << left << setw(12) << itr->second.getPhone() << left << setw(6) << '|'
         << left << setw(12) << itr->second.getAddress().getCity() << left << setw(6) << '|'
         << itr->second.getAddress().getCountry() << '\n';
}

void ContactManager::clearContact() {
    char ans;
    cout << "是否确定要清空联系人？[ y / n ]:\n";
    cout << "请确认:\n";
    cin >> ans;

    if (ans == 'y' || ans == 'Y') {
        contact_list_.clear();
        ofstream ofs("contact.csv");
        ofs << "Name" << ',' << "Gender" << ',' << "Phone" << ',' << "City" << ',' << "Country" << '\n';
        ofs.close();
        cout << "通讯录清空完毕!\n";
    } else if (ans == 'n' || ans == 'N') {
        cout << "已停止清空\n";
    } else if (isdigit(ans)) {
        cout << "非法输入!\n";
        exit(0);
    }
}
