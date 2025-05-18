#include "Person.h"
#include "Utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool Person::loadFromFile(const string& filePath) 
{
    ifstream file(filePath);
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line)) 
    {
        if (line.empty()) continue;

        if (line.find("Person ID:") != string::npos)
            personID = line.substr(11);
        else if (line.find("Full Name:") != string::npos)
            fullName = line.substr(11);
        else if (line.find("Passport Number:") != string::npos)
            passportNumber = line.substr(17);
        else if (line.find("INN:") != string::npos)
            inn = line.substr(5);
        else if (line.find("Phone:") != string::npos)
            phone = line.substr(7);
        else if (line.find("Email:") != string::npos)
            email = line.substr(7);
        else if (line.find("Registered Address:") != string::npos)
            registeredAddress = line.substr(20);
        else if (line.find("Blacklist Status:") != string::npos)
            blacklistStatus = parseBool(line.substr(18));
        else if (line.find("Trusted Receiver:") != string::npos)
            trustedReceiver = parseBool(line.substr(18));
        else if (line.find("Date of Verification:") != string::npos)
            verificationDate = line.substr(23);
    }

    return true;
}

bool Person::validateData(string& errorMessage) const 
{
    if (personID.empty() || fullName.empty() || passportNumber.empty() || inn.empty() ||
        phone.empty() || email.empty() || registeredAddress.empty() || verificationDate.empty()) {
        errorMessage = "Missing required fields in person data.";
        return false;
    }

    if (blacklistStatus) 
    {
        errorMessage = "Person is in blacklist.";
        return false;
    }

    return true;
}