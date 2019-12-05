#include <iostream>
using namespace std;

class A {
 public:
  void setVarA(int i);
  int getVarA() const;
 private:
  int varA; 
};

class B : public A {
 public:
  void setVarB(int i);
  int getVarB() const;
 private:
  int varB;
};

void A::setVarA(int i) {
   varA = i;	
}

int A::getVarA() const {
	return varA;
}

void B::setVarB(int i) {
   varB = i ;
}

int B::getVarB() const {
	return varB;
}

int main () {
   B b;    
   b.setVarA(8); 
   b.setVarB(11); 
   cout << "varA: " << b.getVarA() << endl
        << "varB: " << b.getVarB() << endl;
   return 0;
}

