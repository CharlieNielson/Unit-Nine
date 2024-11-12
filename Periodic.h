#pragma once
#include <iostream>
//#include <sstream>
#include <fstream>
using namespace std;

class Periodic {
        public:
            void findElementNum(string);
            void findElementSymbol(string);
            string out();

        private:
            string atomic, element, symbol, mass;
};

void Periodic::findElementNum(string num) {
    ifstream ein("elements.csv", ios::in);
    bool end = true;
    
    string enda, ende, ends, endm;
    
    while (!ein.eof() && end) {
        getline(ein, enda, ',');
        getline(ein, ende, ',');
        getline(ein, ends, ',');
        getline(ein, endm, '\n');
        if (enda == num) {
            ein.close();
            end = false;
        }
    }
    atomic = enda;
    element = ende;
    symbol = ends;
    mass = endm;
}

void Periodic::findElementSymbol(string sym) {
    ifstream ein("elements.csv", ios::in);
    bool end = true;

    string enda, ende, ends, endm;
    
    while(!ein.eof() && end) {
        getline(ein, enda, ',');
        getline(ein, ende, ',');
        getline(ein, ends, ',');
        getline(ein, endm, '\n');
        if (ends == sym) {
            ein.close();
            end = false;
        }
    }
    atomic = enda;
    element = ende;
    symbol = ends;
    mass = endm;
}

string Periodic::out() {
    cout << "Number: " << atomic << "\nName: " << element << "\nSymbol: " << symbol << "\nMass: " << mass << endl;
}
