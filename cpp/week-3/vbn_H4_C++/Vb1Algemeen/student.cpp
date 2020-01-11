#include <iostream>
#include <string>
using namespace std;

class student {
   public:
      student();
	  student(int nr, const string &nm);
	  student(int nr, const string &nm, int aant, const int *ptn);
      ~student();
      void print() const;
      
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
   student s3;   // geen () toevoegen!!!
   s1.print();
   s2.print();
   s3.print();
   return 0;
}

student::student(int stnr, const string &nm, int aant, const int *ptn) {
   this->stnr = stnr; 
   naam = nm;
   aantal_punten = aant;
   punten = new int[aantal_punten];
   for(int i=0 ; i<aantal_punten ; i++)
      punten[i] = ptn[i];
}

student::student(int stnr, const string &nm) {
   this->stnr = stnr; 
   naam = nm;
   aantal_punten = 0; //niet automatisch 0!!!
   punten = nullptr;
}

student::student() {
   stnr = 0; //niet automatisch 0!!!
   aantal_punten = 0;
   punten = nullptr;
   //naam is wel leeg (defaultconstructor van string is opgeroepen)
}

student::~student() {
   delete[] punten; 
   //voor bovenstaande opdracht is het belangrijk dat een lege
   //array de nullptr bevat (anders crasht het programma)
   //alternatief: controleer voor delete[] of aantal_punten > 0
   cout << "en de punten van " << naam << " zijn weg...\n";
}

void student::print() const {
   cout << stnr << ' ' << naam << '\t';
   for (int i=0 ; i<aantal_punten ; i++)
      cout << punten[i] << "  ";
   cout << endl;
}

/*
Opmerking: Om de punten van de student bij te houden,
was het véél eenvoudiger geweest om een vector te gebruiken.
Dan had je ook geen destructor moeten schrijven...
maar dat was nu net het doel van dit voorbeeld.
 */
