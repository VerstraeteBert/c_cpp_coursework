/* Tijd1.cpp
	met de definitie van
                        operator +
                        operator <
                        operator * : tijd * int
	met een private lidfunctie om de tijd te herschikken,
    toegepast in de operatoren die hiervoor staan vermeld
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Tijd {
   private:
      int uur, min, sec;
      void herbereken();
   public:
      Tijd(int u=0, int m=0, int s=0); 
      void print(bool s=true) const;
      Tijd operator+(const Tijd &) const;
      Tijd operator*(int) const;
      bool operator<(const Tijd &) const;
}; // Tijd

void Tijd::herbereken() {
   int hulp = sec;
   sec = hulp % 60;
   hulp = min + hulp/60;
   min = hulp % 60;
   uur = (uur + hulp/60) % 24;
}

Tijd::Tijd(int u, int m, int s) :
	     uur(u), min(m), sec(s) {}

void Tijd::print(bool s) const {
   cout << setw(2) << setfill('0') << uur << ':'
	    << setw(2) << setfill('0') << min;
   if (s)
      cout << ':' << setw(2) << setfill('0') << sec;
}

Tijd Tijd::operator+(const Tijd &t) const {
   Tijd som(uur+t.uur, min+t.min, sec+t.sec);
   som.herbereken();
   return som;
}

Tijd Tijd::operator*(int factor) const {
   Tijd tmp(uur*factor, min*factor, sec*factor);
   tmp.herbereken();
   return tmp;
}

bool Tijd::operator<(const Tijd &t) const {
   return uur*3600+min*60+sec < 
          t.uur*3600+t.min*60+t.sec;
}

int main() {
   Tijd t0, t1(1,51,51), t2(5,30,11), t3;
   cout << "t0: ";
   t0.print(false); 
   cout << endl << "t1: ";
   t1.print(); 
   cout << endl << "t2: ";
   t2.print();
   t0 = t1+t2;
   cout << endl << "t0 (=t1+t2): ";
   t0.print();
   t3 = t2*2;
   cout << endl << "t3 (=t2*2): ";
   t3.print();
   if (t1<t2)
      cout << endl << "t1 < t2";
   return 0;
}

