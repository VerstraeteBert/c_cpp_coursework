#include "Punt.h"
#include "Lijn1.h"
#include <iostream>
using namespace std;

Lijn1::Lijn1() {
   cout << "default constructor Lijn1" << endl;	
}

Lijn1::Lijn1(int x1, int y1, int x2, int y2) {
   cout << "constructor Lijn1: 4 int" << endl;
   p1 = Punt(x1,y1);
   p2 = Punt(x2,y2);
}

Lijn1::Lijn1(const Punt &p1, const Punt &p2) {
   cout << "constructor Lijn1: 2 punten" << endl;
   this->p1 = p1;
   cout << "kopie maken eerste punt\n";
   this->p2 = p2;
   cout << "kopie maken tweede punt\n";
}

void Lijn1::print() const {
   cout << "[";
   p1.print();
   cout << "-";
   p2.print();
   cout << "]";
}
