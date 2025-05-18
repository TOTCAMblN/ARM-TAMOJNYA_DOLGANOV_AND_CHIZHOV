#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Documents.h"

using namespace std;
namespace fs = filesystem;

// Функции для удаления пробелов
static inline void ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(),
        [](unsigned char ch) { return !isspace(ch); }));
}

static inline void rtrim(string& s) {
    s.erase(find_if(s.rbegin(), s.rend(),
        [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
}

static inline void trim(string& s) {
    ltrim(s);
    rtrim(s);
}

bool readDocuments(Documents& doc, Packege& pack, Sendler& sender, Recipient& recipient) {
    string basePath = "packages";

    fs::path firstSubfolder;
    for (const auto& entry : fs::directory_iterator(basePath)) {
        if (entry.is_directory()) {
            firstSubfolder = entry.path();
            break;
        }
    }

    if (firstSubfolder.empty()) {
        cout << "Нет доступных подпапок в 'packages'" << endl;
        return false;
    }

    fs::path docPath = firstSubfolder / "document.txt";
    if (!fs::exists(docPath)) {
        cout << "Файл 'document.txt' не найден в " << firstSubfolder << endl;
        return false;
    }

    ifstream file(docPath);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл document.txt" << endl;
        return false;
    }

    string line;

    // Переменные для временного хранения данных
    string packageID, trackingNumber, category, deliveryAddress, verificationDate;
    float weight = 0.0f;
    bool importTaxPaid = false;
    vector<string> hsCodes;

    // Для Sendler
    string s_country, s_type, s_fullName, s_passport, s_inn, s_phone, s_address;

    // Для Recipient
    string r_country, r_type, r_fullName, r_passport, r_inn, r_phone, r_address;

    bool readingSendler = false;
    bool readingRecipient = false;

    while (getline(file, line)) {
        trim(line);
        if (line.empty()) continue;

        if (line.find("Package ID:") == 0) {
            packageID = line.substr(11);
            trim(packageID);
        }
        else if (line.find("Tracking Number:") == 0) {
            trackingNumber = line.substr(16);
            trim(trackingNumber);
        }
        else if (line.find("Weight:") == 0) {
            string temp = line.substr(7);
            trim(temp);
            size_t posKg = temp.find("kg");
            if (posKg != string::npos) temp.erase(posKg);
            trim(temp);
            weight = stof(temp);
        }
        else if (line.find("Category:") == 0) {
            category = line.substr(9);
            trim(category);
        }
        else if (line.find("Delivery Address:") == 0) {
            deliveryAddress = line.substr(17);
            trim(deliveryAddress);
        }
        else if (line.find("Sendler:") == 0) {
            readingSendler = true;
            readingRecipient = false;
        }
        else if (line.find("Recipient:") == 0) {
            readingSendler = false;
            readingRecipient = true;
        }
        else if (line.find("Country:") == 0) {
            string val = line.substr(8);
            trim(val);
            if (readingSendler) s_country = val;
            else if (readingRecipient) r_country = val;
        }
        else if (line.find("Type:") == 0) {
            string val = line.substr(5);
            trim(val);
            if (readingSendler) s_type = val;
            else if (readingRecipient) r_type = val;
        }
        else if (line.find("Full Name:") == 0) {
            string val = line.substr(11);
            trim(val);
            if (readingSendler) s_fullName = val;
            else if (readingRecipient) r_fullName = val;
        }
        else if (line.find("Passport Number:") == 0) {
            string val = line.substr(17);
            trim(val);
            if (readingSendler) s_passport = val;
            else if (readingRecipient) r_passport = val;
        }
        else if (line.find("INN:") == 0) {
            string val = line.substr(4);
            trim(val);
            if (readingSendler) s_inn = val;
            else if (readingRecipient) r_inn = val;
        }
        else if (line.find("Phone:") == 0) {
            string val = line.substr(6);
            trim(val);
            if (readingSendler) s_phone = val;
            else if (readingRecipient) r_phone = val;
        }
        else if (line.find("Address:") == 0) {
            string val = line.substr(8);
            trim(val);
            if (readingSendler) s_address = val;
            else if (readingRecipient) r_address = val;
        }
        else if (line.find("HS Code:") == 0) {
            string val = line.substr(8);
            trim(val);
            hsCodes.push_back(val);
        }
        else if (line.find("Import Tax Paid:") == 0) {
            string val = line.substr(16);
            trim(val);
            importTaxPaid = (val == "true");
        }
        else if (line.find("Verification Date:") == 0) {
            verificationDate = line.substr(18);
            trim(verificationDate);
        }
    }

    file.close();

    // Заполняем переданные объекты
    pack = Packege(packageID, trackingNumber, weight, category, deliveryAddress, hsCodes, importTaxPaid, verificationDate);
    sender = Sendler(s_country, s_type, s_fullName, s_passport, s_inn, s_phone, s_address);
    recipient = Recipient(r_country, r_type, r_fullName, r_passport, r_inn, r_phone, r_address);
    doc = Documents(pack, sender, recipient);

    return true;
}

// Объявления вспомогательных функций
static inline void trim(string& s);

// Для Sendler
static bool checkRussianIndividualSender(const string& passport, Sendler& sender);
static bool checkRussianOrganizationSender(const string& inn, Sendler& sender);

// Для Recipient
static bool checkRussianIndividualRecipient(const string& passport, Recipient& recipient);
static bool checkRussianOrganizationRecipient(const string& inn, Recipient& recipient);

// Общая для обоих типов
static bool checkForeignEntity(const string& type, const string& name);

// Основная функция проверки
bool checkPerson(Sendler& sender, Recipient& recipient);



static bool checkRussianIndividualSender(const string& passport, Sendler& sender) {
    string filename = "database/Russian/Individual/" + passport + ".txt";
    ifstream file(filename);

    file.seekg(0, ios::end);
    if (file.tellg() == 0) {
        cerr << "Файл открыт, но пустой: " << filename << endl;
        return false;
    }
    file.seekg(0); // вернуться к началу

    if (!file.is_open()) return false;

    string line;
    vector<pair<string, string>> fileData;
    
    int stringChecker = 6;
    int counter = 0;
    while (getline(file, line)) {
        counter++;
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            string key = line.substr(0, colonPos);
            string value = line.substr(colonPos + 1);
            trim(key);
            trim(value);
            fileData.emplace_back(key, value);
        }
    }
    if (counter != stringChecker)
        return false;

    bool blackList = false;
    bool dataMatch = true;

    for (const auto& [key, value] : fileData) {
        if (key == "Black List") {
            blackList = (value == "true");
        }
        else if (key == "Full Name" && value != sender.getFullName()) {
            dataMatch = false;
        }
        else if (key == "Passport Number" && value != sender.getPassportNumber()) {
            dataMatch = false;
        }
        else if (key == "INN" && value != sender.getINN()) {
            dataMatch = false;
        }
        else if (key == "Phone" && value != sender.getPhone()) {
            dataMatch = false;
        }
        else if (key == "Address" && value != sender.getAddress()) {
            dataMatch = false;
        }
    }

    return dataMatch && !blackList;
}

static bool checkRussianOrganizationSender(const string& inn, Sendler& sender) {
    string filename = "database/Russian/Organization/" + inn + ".txt";
    ifstream file(filename);

    if (!file.is_open()) return false;

    string line;
    vector<pair<string, string>> fileData;

    int stringChecker = 5;
    int counter = 0;
    while (getline(file, line)) {
        counter++;
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            string key = line.substr(0, colonPos);
            string value = line.substr(colonPos + 1);
            trim(key);
            trim(value);
            fileData.emplace_back(key, value);
        }
    }

    if (counter != stringChecker)
        return false;

    bool blackList = false;
    bool dataMatch = true;

    for (const auto& [key, value] : fileData) {
        if (key == "Black List") {
            blackList = (value == "true");
        }
        else if (key == "Full Name" && value != sender.getFullName()) {
            dataMatch = false;
        }
        else if (key == "INN" && value != sender.getINN()) {
            dataMatch = false;
        }
        else if (key == "Address" && value != sender.getAddress()) {
            dataMatch = false;
        }
    }

    return dataMatch && !blackList;
}

static bool checkRussianIndividualRecipient(const string& passport, Recipient& recipient) {
    string filename = "database/Russian/Individual/" + passport + ".txt";
    ifstream file(filename);

    if (!file.is_open()) return false;

    string line;
    vector<pair<string, string>> fileData;

    int stringChecker = 6;
    int counter = 0;
    while (getline(file, line)) {
        counter++;
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            string key = line.substr(0, colonPos);
            string value = line.substr(colonPos + 1);
            trim(key);
            trim(value);
            fileData.emplace_back(key, value);
        }
    }

    if (counter != stringChecker)
        return false;

    bool blackList = false;
    bool dataMatch = true;

    for (const auto& [key, value] : fileData) {
        if (key == "Black List") {
            blackList = (value == "true");
        }
        else if (key == "Full Name" && value != recipient.getFullName()) {
            dataMatch = false;
        }
        else if (key == "Passport Number" && value != recipient.getPassportNumber()) {
            dataMatch = false;
        }
        else if (key == "INN" && value != recipient.getINN()) {
            dataMatch = false;
        }
        else if (key == "Phone" && value != recipient.getPhone()) {
            dataMatch = false;
        }
        else if (key == "Address" && value != recipient.getAddress()) {
            dataMatch = false;
        }
    }

    return dataMatch && !blackList;
}

static bool checkRussianOrganizationRecipient(const string& inn, Recipient& recipient) {
    string filename = "database/Russian/Organization/" + inn + ".txt";
    ifstream file(filename);

    if (!file.is_open()) return false;

    string line;
    vector<pair<string, string>> fileData;

    int stringChecker = 5;
    int counter = 0;
    while (getline(file, line)) {
        counter++;
        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            string key = line.substr(0, colonPos);
            string value = line.substr(colonPos + 1);
            trim(key);
            trim(value);
            fileData.emplace_back(key, value);
        }
    }

    if (counter != stringChecker)
        return false;

    bool blackList = false;
    bool dataMatch = true;

    for (const auto& [key, value] : fileData) {
        if (key == "Black List") {
            blackList = (value == "true");
        }
        else if (key == "Full Name" && value != recipient.getFullName()) {
            dataMatch = false;
        }
        else if (key == "INN" && value != recipient.getINN()) {
            dataMatch = false;
        }
        else if (key == "Address" && value != recipient.getAddress()) {
            dataMatch = false;
        }
    }

    return dataMatch && !blackList;
}

static bool checkForeignEntity(const string& type, const string& name) {
    string filename = "database/Foreign/" + type + "/blacklist.txt";
    ifstream file(filename);

    if (!file.is_open()) return true;

    string line;
    while (getline(file, line)) {
        trim(line);
        if (line == name) return false;
    }
    return true;
}

bool checkPerson(Sendler& sender, Recipient& recipient) {
    // Проверка отправителя
    if (sender.getCountry() == "Russia") {
        if (sender.getType() == "Individual") {
            string passport = sender.getPassportNumber();
            replace(passport.begin(), passport.end(), ' ', '_');
            if (!checkRussianIndividualSender(passport, sender)) {
                return false;
            }
        }
        else if (sender.getType() == "Organization") {
            if (!checkRussianOrganizationSender(sender.getINN(), sender)) {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        if (!checkForeignEntity(sender.getType(), sender.getFullName())) {
            return false;
        }
    }

    // Проверка получателя
    if (recipient.getCountry() == "Russia") {
        if (recipient.getType() == "Individual") {
            string passport = recipient.getPassportNumber();
            replace(passport.begin(), passport.end(), ' ', '_');
            if (!checkRussianIndividualRecipient(passport, recipient)) {
                return false;
            }
        }
        else if (recipient.getType() == "Organization") {
            if (!checkRussianOrganizationRecipient(recipient.getINN(), recipient)) {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        if (!checkForeignEntity(recipient.getType(), recipient.getFullName())) {
            return false;
        }
    }

    return true;
}

bool checkHS(Packege packege) {
    ifstream file("database/HSblacklist.txt");
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл HSblacklist.txt" << endl;
        return false;
    }

    vector<string> blacklist;
    string line;
    while (getline(file, line)) {
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (!line.empty()) {
            blacklist.push_back(line);
        }
    }

    file.close();
    vector<string> hsCodes = packege.getHSCodes();
    for (const string& hs : hsCodes) {
        for (const string& blocked : blacklist) {
            if (hs == blocked) {
                return false;
            }
        }
    }

    return true;
}

bool scanerCheck(const string& path) {
    string sourcePath = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine\\packages\\" + path + "\\scaner.png";
    string destinationPath = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\scaner.png";
    string pythonScriptPath = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\scaner.py";

    try {
        // Перемещение файла
        fs::copy_file(sourcePath, destinationPath, fs::copy_options::overwrite_existing);
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Ошибка при копировании файла.";
    }

    // Запуск Python скрипта
    string command = "python \"" + pythonScriptPath + "\"";
    int result = system(command.c_str());
    if (result == 0) {
        return true;
    }
    return false;
}

bool moveFolder(const string& folderName, const string& destBase) {
    string sourceBase = "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine\\packages\\";

    fs::path sourcePath = fs::path(sourceBase) / folderName;
    fs::path destPath = fs::path(destBase) / folderName;

    try {
        if (!fs::exists(sourcePath)) {
            cerr << "Исходная папка не найдена: " << sourcePath << endl;
            return false;
        }

        fs::rename(sourcePath, destPath);
        return true;
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Ошибка при перемещении папки: " << e.what() << endl;
        return false;
    }
}