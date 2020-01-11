#include "Punt.h"
#include "Lijn1.h"
#include "Lijn2.h"
#include <iostream>
using namespace std;

int main() {
   cout << "\nLijn1 l1;" << endl;	
   Lijn1 l1;
   cout << "print l1: ";
   l1.print();
   cout << endl;
   
   cout << "\nLijn2 l2;" << endl;	
   Lijn2 l2;
   cout << "print l2: ";
   l2.print();
   cout << endl;
   
   cout << "\nLijn1 l3(1,2,3,4);" << endl;	
   Lijn1 l3(1,2,3,4);
   cout << "print l3: ";
   l3.print();
   cout << endl;
   
   cout << "\nLijn2 l4(1,2,3,4);" << endl;	
   Lijn2 l4(1,2,3,4);
   cout << "print l4: ";
   l4.print();
   cout << endl;
   
   cout << "\nPunt p1(5,6), p2(7,8);" << endl;  
   Punt p1(5,6), p2(7,8);
   
   cout << "\nLijn1 l5(p1,p2);" << endl;
   Lijn1 l5(p1,p2);
   cout << "print l5: ";
   l5.print();
   cout << endl;
   
   cout << "\nLijn2 l6(p1,p2);" << endl;
   Lijn2 l6(p1,p2);
   cout << "print l6: ";
   l6.print();
   return 0;
}
