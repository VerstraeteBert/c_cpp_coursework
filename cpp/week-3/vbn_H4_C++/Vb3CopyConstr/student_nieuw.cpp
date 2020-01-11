#include <iostream>
#include <string>
using namespace std;

class student {
   public:
      student(const student &); //NIEUW!!!! 	  
	  student(int, const string &, int, const int *);	  
      student(int nr, const string &nm);
      student();
      ~student(); 
      void print() const;
      void wijzig_punt(int, int);
      void wijzig_naam(const string &);
      
   private:
      int stnr;
      string naam;
      int aantal_punten;
      int *punten;
};

int main () {  
   int ptn[4] = {12, 7, 16, 11};
   student s1(20021923,"Jef Bracke",4,ptn);
   student s2(20021005,"Tom Put");
   s1.print();
   s2.print();
   student s3(s1);
   s3.wijzig_naam("Leo Maes");
   s3.wijzig_punt(1,10);
   s3.print();
   s1.print();  
   return 0;
}

//NIEUW!!!
student::student(const student &st) 
   : student(st.stnr, st.naam, st.aantal_punten, st.punten) {}

student::student(int nr, const string &nm, int aant, const int *ptn) {
   stnr = nr; 
   naam = nm;
   aantal_punten = aant;
   if (aantal_punten > 0) {
   	   punten = new int[aantal_punten];
       for(int i=0 ; i<aantal_punten ; i++)
          punten[i] = ptn[i];
   }
   else punten = nullptr;
}

student::student(int nr, const string &nm) 
   : student(nr,nm,0,nullptr) {}
student::student() : student(0,"",0,nullptr) {}

student::~student() {
   delete[] punten;
   cout << "en de punten van " << naam << " zijn weg...\n";
}

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

