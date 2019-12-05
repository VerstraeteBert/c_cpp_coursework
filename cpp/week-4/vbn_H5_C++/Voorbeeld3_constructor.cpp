#include <iostream>
using namespace std;

class A {
 public:
   A(int vA = -1);
   int getVarA() const;
 private:
   int varA; 
};

class B : public A {
 public:
   B(int vB = -2);
   B(int vA, int vB);
   int getVarB() const;
 private:
   int varB;
};

A::A(int vA) : varA(vA) {}

int A::getVarA() const {
	return varA;
}

B::B(int vB) : varB(vB) {}
B::B(int vA, int vB) : A(vA), varB(vB) {}

int B::getVarB() const {
	return varB;
}

int main () {
   B b1;
   cout << "B b1;" << endl;
   cout << "  varA: " << b1.getVarA() << endl
        << "  varB: " << b1.getVarB() << endl;

   B b2(8);
   cout << "B b2(8);" << endl;
   cout << "  varA: " << b2.getVarA() << endl
        << "  varB: " << b2.getVarB() << endl;
        
   B b3(2,7);
   cout << "B b3(2,7);" << endl;
   cout << "  varA: " << b3.getVarA() << endl
        << "  varB: " << b3.getVarB() << endl;

   return 0;
}

