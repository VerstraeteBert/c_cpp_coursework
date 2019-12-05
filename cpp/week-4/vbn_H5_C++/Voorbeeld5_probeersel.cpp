#include <iostream>
using namespace std;

class A {
   public:
      A();
	  A(int i, int *p);
      A(const A &a);
      ~A();
      void print() const;
      A& operator=(const A&);
      
   private:
      int grA;
      int *tabA;
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

A& A::operator=(const A& a) {
   delete[] tabA;
   grA = a.grA;
   if (grA > 0) {
   	   tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          tabA[i] = a.tabA[i];
   }
   return *this;
}

int main () {
   int pA[4] = {12, 7, 16, 11};
   A a1(4, pA);
   cout << "a1.print();" << endl;
   a1.print();
   A a2 = a1;
   cout << "A a2 = a1;\n";
   cout << "a2.print();" << endl;
   a2.print();
   a1 = a1;
   cout << "a1 = a1;\n";
   cout << "a1.print();" << endl;
   a1.print();
   return 0;
}
