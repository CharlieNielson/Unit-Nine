#include <iostream>
#include <fstream>


using namespace std;


enum Choices{WRITE = 1, READ, QUIT };


void saveFavorites();
void readFavorites();
string getFilename();
int menu();


int main() {
 cout << "Top 10 Favorites List" << endl;
 int choice;
 string name;


 do{
   choice = menu();
   switch(choice){
     case WRITE:
       saveFavorites();
       break;
     case READ:
       readFavorites();
       break;
   }


 }while(choice != QUIT);
}


void saveFavorites(){
 ofstream fout(getFilename(), ios::out);
 cout << "Enter your top five favorites: " << endl;
 string temp;
 for(int i = 0;i < 5; i++){
   cout << (i+1) << ": ";
   cin >> temp;
   fout << temp;
   if(i < 4)
fout << endl;
 }
 fout.close();
}


void readFavorites(){
 ifstream fin(getFilename(), ios::in);
 int count = 1;
 string temp;
 while(!fin.eof()){
   fin >> temp;
   cout << count << ": " << temp << endl;
   count ++;
 }
 fin.close();
}




string getFilename(){
 string name;
 cout << "Enter your first name: ";
 cin >> name;
 return name + ".txt";
}


int menu(){
 int choice;
 cout << endl;
 cout << "1. Save Favorites" << endl;
 cout << "2. Load Favorites:" << endl;
 cout << "3. Quit" << endl;
 cout << "Choose one: ";
 cin >> choice;
 return choice;
}


