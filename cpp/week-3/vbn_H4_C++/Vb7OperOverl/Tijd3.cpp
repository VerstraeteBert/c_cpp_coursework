/* Tijd3.cpp
	uitbreiding van de klasse Tijd uit Tijd2.cpp
	met de extra definitie van
    	operator[]
        (friend) operator * : int * tijd
		friend operatoren >> en << 
		                       
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Tijd {
   private:
      int uur, min, sec;
      void herbereken();
   public:
      Tijd(int u=0, int m=0, int s=0) :
	     uur(u), min(m), sec(s) {}
      void print(bool s=true) const;
      Tijd operator+(const Tijd &t) const;
      Tijd operator*(int f) const;
      bool operator<(const Tijd &t) const;
      Tijd operator-() const;
      Tijd& operator+=(const Tijd &t);
	  Tijd& operator++();
	  Tijd operator++(int);  
	  int& operator[](int);
	  //friend Tijd operator*(int f, const Tijd &t); 
	  friend ostream& operator<<(ostream& os, const Tijd& t);
      friend istream& operator>>(istream& is, Tijd& t);       
}; // Tijd

void Tijd::herbereken() {
   int hulp = sec;
   sec = hulp % 60;
   hulp = min + hulp/60;
   min = hulp % 60;
   uur = uur + hulp/60;
}

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

Tijd Tijd::operator-() const { 
   return Tijd(-uur, -min, -sec); 
}

Tijd& Tijd::operator+=(const Tijd &t) {
   sec += t.sec;
   min += t.min;
   uur += t.uur;
   herbereken();
   return *this;
}

Tijd& Tijd::operator++() {
   sec++; herbereken();
   return *this;
}
	  
Tijd Tijd::operator++(int a) {
	Tijd temp(*this);
	sec++; herbereken();
	return temp;
}

int& Tijd::operator[] (int i) {
  if (i==0) return uur;
  else if (i==1) return min;
  else return sec;
}

Tijd operator*(int f, const Tijd &t) {
   /*
   Tijd tmp = Tijd(t.uur*f,t.min*f,t.sec*f);
   tmp.herbereken();
   return tmp;
   */  
   return t*f;
}

ostream& operator<<(ostream& os, const Tijd& t) {
   os << setw(2) << setfill('0') << t.uur << ':'
	  << setw(2) << setfill('0') << t.min << ':'
      << setw(2) << setfill('0') << t.sec;
   return  os;
}
 
istream& operator>>(istream& is, Tijd& t){
   is >> t.uur >> t.min >> t.sec;
   t.herbereken();
   return is;
}

int main() {
   Tijd t1(5,45,51), t2; 
   cout << "t1: " << t1 << endl; 
   t1[2]=0;
   t1[0]++;
   cout << "t1: " << t1 << endl;
   cout<<"Geef eens een tijd op (u m s): ";
   cin >> t1;
   cout << "nieuwe t1: " << t1 << endl;   
   t2 = 2*t1;
   cout << "t2 (=2*t1): " << t2 << endl;
   return 0;
}

