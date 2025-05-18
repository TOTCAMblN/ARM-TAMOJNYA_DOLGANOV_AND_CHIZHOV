#include "Utils.h"
#include "BigMachine.h"

int main() {
    setlocale(LC_ALL, "Russian");
    BigMachine Scaner;
    Scaner.inputData();

    if (Scaner.firstCheckCard() && Scaner.secondCheckCard())
        if (Scaner.thirdCheclkCard()) {
            moveFolder(Scaner.getPackege().getPackageID(), "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine\\PassPackages");
            return 0;
        }
        else { moveFolder(Scaner.getPackege().getPackageID(), "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine\\BadPackages");  return 1;}
    else { moveFolder(Scaner.getPackege().getPackageID(), "C:\\Users\\LENOVO\\source\\repos\\projectBigMachine\\projectBigMachine\\BadPackages"); return 2; }
}

