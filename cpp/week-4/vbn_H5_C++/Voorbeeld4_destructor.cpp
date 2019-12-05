#include <iostream>
using namespace std;

class A {
   public:
      A();
	  A(int i, int *p);
      A(const A &a);
      ~A();
      void print() const;
      void wijzigA(int, int);
      
   private:
      int grA;
      int *tabA;
};

class B : public A {
   public:
      B(int iA, int *pA, int iB, int *pB);
      B(const B &b); 
      ~B();
      void print() const;
      void wijzigB(int, int);
      
   private:
      int grB;
      int *tabB;
};

A::A(int i, int *p) : grA(i), tabA(nullptr) {
   if (grA > 0) {
   	   tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          tabA[i] = p[i];
   }
}

A::A() : A(0,nullptr) {}
A::A(const A &a) : A(a.grA, a.tabA) {}

A::~A() {
   cout << "destructor A" << endl;
   delete[] tabA;
}

void A::print() const {
   for (int i=0 ; i<grA ; i++)
      cout << tabA[i] << "  ";
   cout << endl;
}

void A::wijzigA(int index, int nieuw) {
   if (index < grA)
      tabA[index] = nieuw;
}

B::B(int iA, int *pA, int iB, int *pB) : 
                        A(iA,pA), grB(iB), tabB(nullptr) {
   if (grB > 0) {
   	   tabB = new int[grB];
       for(int i=0 ; i<grB ; i++)
          tabB[i] = pB[i];
   }
}

B::B(const B &b) : A(b), grB(b.grB), tabB(nullptr) {
   if (grB > 0) {
   	   tabB = new int[grB];
       for(int i=0 ; i<grB ; i++)
          tabB[i] = b.tabB[i];
   }
}
//opm: indien A(b) niet vermeld wordt, 
//wordt de default-constructor van A opgeroepen 

B::~B() {
   cout << "destructor B" << endl;
   delete[] tabB;
}

void B::print() const {
   A::print();
   for (int i=0 ; i<grB ; i++)
      cout << tabB[i] << "  ";
   cout << endl;
}

void B::wijzigB(int index, int nieuw) {
   if (index < grB)
      tabB[index] = nieuw;
}

int main () {
   int pA[4] = {12, 7, 16, 11};
   int pB[5] = {2, 8, 3, 5, 9};
   A a(4, pA);
   cout << "a.print();" << endl;
   a.print();
   
   // B b0;
   // er is geen default default-constructor aangezien B
   // een andere constructor voorziet

   B b1(4, pA, 5, pB);
   cout << "b1.print();" << endl;
   b1.print();  
   
   B b2(b1);
   cout << "b2.print();" << endl;
   b2.print(); 
   b2.wijzigA(2,-6);
   b2.wijzigB(4,0);
   cout << "na b2.wijzigA(2,-6); en b2.wijzigB(4,0);\n";
   cout << "b2.print();" << endl;
   b2.print();
   cout << "b1.print();" << endl;
   b1.print();  
   
   cout << "b2.A::print();" << endl;
   b2.A::print();

   return 0;
}
