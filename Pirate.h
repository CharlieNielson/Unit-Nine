#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

// Stream is where the data goes.
// Input is into the program(cin)
// and output is out the program(cout).
// cerr is output in case of an error.

// There are text and binary files you can write to.

class Pirate {
        public:
            string translateWord(string);
            string translateSentence(string);
            void addToFile(string, string);
            string out();

        private:
            string thing;
};

string Pirate::translateWord(string word) {
    ifstream fin("pirate.csv", ios::in);
    string english, pirate;

    while(!fin.eof()) {
        getline(fin, english, ',');
        getline(fin, pirate, '\n');
        if(english == word) {
            fin.close();
            return pirate;
        }
    }

    fin.close();
    return word;
}

string Pirate::translateSentence(string sentence) {
    stringstream sentenceReader(sentence);
    string end = "";
    thing = "";

    while (sentenceReader.good()) {
        string temp;
        getline(sentenceReader, temp, ' ');
        end += translateWord(temp) + " ";
    }
    thing = end;
    return end;
}

void Pirate::addToFile(string english, string pirate) {
    ofstream fout("pirate.csv", ios::app);

    fout << "\n" << english << ", " << pirate;

    fout.close();
}

string Pirate::out() {
    return thing;
}
