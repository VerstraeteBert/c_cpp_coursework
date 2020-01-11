#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class student {
   public:    
      student(int, const string &, int, int *);	  
      student(int nr, const string &nm);
      student();
      student(const student &st);
      ~student() {
      	  delete[] punten;
      	  cout << "en de punten van " << naam << " zijn weg...\n";
	  }
      
      void print() const;
      void wijzig_punt(int index, int score);
      void wijzig_naam(const string &);
      
   private:
      int stnr;
      string naam;
      int aantal_punten;
      int *punten;
};

#endif // STUDENT_H
