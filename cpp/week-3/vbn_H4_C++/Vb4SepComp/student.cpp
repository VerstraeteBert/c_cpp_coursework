#include "student.h"
#include <string>
#include <iostream>
using namespace std;

student::student(int nr, const string &nm, int aant, int *ptn) {
   stnr = nr; 
   naam = nm;
   aantal_punten = aant;
   if (aantal_punten > 0) {
   	   punten = new int[aantal_punten];
       for(int i=0 ; i<aantal_punten ; i++)
          punten[i] = ptn[i];
   }
   else
      punten = nullptr;
}

student::student(const student &st) 
   : student(st.stnr, st.naam, st.aantal_punten, st.punten) {}
student::student(int nr, const string &nm) 
   : student(nr,nm,0,nullptr) {}
student::student() : student(0,"",0,nullptr) {}

void student::print() const {
   cout << stnr << ' ' << naam << '\t';
   for (int i=0 ; i<aantal_punten ; i++)
      cout << punten[i] << "  ";
   cout << endl;
}

void student::wijzig_punt(int index, int score) {
   if (index < aantal_punten)
      punten[index] = score;
}

void student::wijzig_naam(const string &nm) {
   naam = nm;
}
