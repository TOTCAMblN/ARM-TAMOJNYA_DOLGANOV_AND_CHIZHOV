#pragma once
#include <string>
#include <vector>
using namespace std;

// Класс Packege
class Packege {
private:
    string packageID;
    string trackingNumber;
    float weight;
    string category;
    string deliveryAddress;
    vector<string> hsCodes;
    bool importTaxPaid;
    string verificationDate;

public:
    // Конструктор
    Packege() {};
    Packege(string id, string track, float w, string cat, string addr,
        vector<string> hs, bool tax, string date)
        : packageID(id), trackingNumber(track), weight(w), category(cat),
        deliveryAddress(addr), hsCodes(hs), importTaxPaid(tax), verificationDate(date) {
    }

    // Геттеры
    string getPackageID() { return packageID; }
    string getTrackingNumber() { return trackingNumber; }
    float getWeight() { return weight; }
    string getCategory() { return category; }
    string getDeliveryAddress() { return deliveryAddress; }
    vector<string> getHSCodes() { return hsCodes; }
    bool getImportTaxPaid() { return importTaxPaid; }
    string getVerificationDate() { return verificationDate; }

    // Проверка на обязательные поля
    bool checkInformation() {
        return !packageID.empty() && !trackingNumber.empty() && weight > 0 &&
            !category.empty() && !deliveryAddress.empty() &&
            !hsCodes.empty() && !verificationDate.empty();
    }
};