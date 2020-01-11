#include "Punt.h"
#include <iostream>
using namespace std;

Punt::Punt() : x(0), y(0) {
   cout << "default constructor Punt" << endl;
}

Punt::Punt(int _x, int _y) : x(_x), y(_y) {
   cout << "constructor Punt 2 int" << endl;
}

Punt::Punt(const Punt &p) : x(p.x), y(p.y) {
   cout << "copyconstructor Punt" << endl;
}

void Punt::print() const {
   cout << "(" << x << "," << y << ")";
}
