#pragma once
#include <string>
using namespace std;

class Sendler {
private:
    string country;
    string type; // "Individual" или "Organization"
    string fullName;
    string passportNumber; // Только для физических лиц из РФ
    string inn;
    string phone;
    string address;

public:
    Sendler() {};
    Sendler(string c, string t, string name, string pass, string i, string p, string a)
        : country(c), type(t), fullName(name), passportNumber(pass),
        inn(i), phone(p), address(a) {
    }

    string getCountry() { return country; }
    string getType() { return type; }
    string getFullName() { return fullName; }
    string getPassportNumber() { return passportNumber; }
    string getINN() { return inn; }
    string getPhone() { return phone; }
    string getAddress() { return address; }

    bool checkInformation() {
        if (country == "Russia") {
            if (type == "Individual") {
                return !fullName.empty() &&
                    !passportNumber.empty() &&
                    !inn.empty() &&
                    !phone.empty() &&
                    !address.empty();
            }
            else if (type == "Organization") {
                return !fullName.empty() &&
                    !inn.empty() &&
                    !address.empty();
            }
            else {
                return false;
            }
        }
        else {
            // Иностранцы: и физ, и юр — только страна и имя/наименование
            return !country.empty() && !fullName.empty();
        }
    }
};