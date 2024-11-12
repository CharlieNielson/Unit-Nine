#include <iostream>
#include <fstream>
#include "Periodic.h"
using namespace std;

int menu(int &choose) {
    int end = 0;
    cout << "1. Search by Atomic Number\n2. Search by Abbreviation\n3. Quit\nChoose one: ";
    while (end > 3 || end < 1) {
        cin >> end;
        if (end > 3 || end < 1) {
            cout << "\nInvald response.\nChoose one: ";
        }
    }
}

int main() {
    Periodic p;
    int choose = 0;
    string thing;
    
    while (choose < 3) {
        choose = menu(choose);
        if (choose = 1) {
            cout << "\nEnter the Atomic Number: ";
            cin >> thing;
            p.findElementNum(thing);
            p.out();
        } else if (choose = 2) {
            cout << "\nEnter the Symbol: ";
            cin >> thing;
            p.findElementSymbol(thing);
            p.out();
        }
    }

    return 17;
}
