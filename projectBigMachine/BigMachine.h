#pragma once
#include "Utils.h"

class BigMachine{
private:
    Documents doc;
    Packege pack;
    Sendler sender;
    Recipient recipient;
public:
    Packege getPackege() {
        return pack;
    }

    void inputData() {
        readDocuments(doc, pack, sender, recipient);
    }

    bool firstCheckCard() {
        if (doc.runFirstCheckpoint())
            return true;
        return false;
    }

    bool secondCheckCard() {
        if (checkPerson(sender, recipient) && checkHS(pack))
            return true;
        return false;
    }
    bool thirdCheclkCard() {
        if (scanerCheck(pack.getPackageID()))
            return true;
        else return false;
    }
};