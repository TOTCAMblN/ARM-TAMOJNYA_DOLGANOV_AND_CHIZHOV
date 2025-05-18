#pragma once
#include "Package.h"
#include "Sendler.h"
#include "Recipient.h"


struct Documents {
    Packege packege;
    Sendler sendler;
    Recipient recipient;

    Documents() {};
    Documents(Packege p, Sendler s, Recipient r)
        : packege(p), sendler(s), recipient(r) {
    }

    bool runFirstCheckpoint() {
        bool check1 = packege.checkInformation();
        bool check2 = sendler.checkInformation();
        bool check3 = recipient.checkInformation();

        if (sendler.getCountry() == "Russia" && recipient.getCountry() == "Russia") return false;
        if (sendler.getCountry() != "Russia" && recipient.getCountry() != "Russia") return false;

        return check1 && check2 && check3;
    }
};