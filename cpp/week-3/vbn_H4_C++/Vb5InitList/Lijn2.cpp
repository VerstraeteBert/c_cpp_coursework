#include "Punt.h"
#include "Lijn2.h"
#include <iostream>
using namespace std;

Lijn2::Lijn2() {
   cout << "default constructor Lijn2" << endl;	
}

Lijn2::Lijn2(int x1, int y1, int x2, int y2)
        : p1(x1,y1), p2(x2,y2) {
   cout << "constructor Lijn2: 4 int" << endl;
}

Lijn2::Lijn2(const Punt &_p1, const Punt &_p2)
        : p1(_p1), p2(_p2) {
   cout << "constructor Lijn2: 2 punten" << endl;
}

void Lijn2::print() const {
   cout << "[";
   p1.print();
   cout << "-";
   p2.print();
   cout << "]";
}
