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

A& A::operator=(const A& a) {
   if(this != &a) {
      delete[] tabA;
      grA = a.grA;
      if (grA > 0) {
   	     tabA = new int[grA];
         for(int i=0 ; i<grA ; i++){
            tabA[i] = a.tabA[i];
         }
      }
   }
   return *this;
}

class B : public A {
   public:
   	  B();
      B(int iA, int *pA, int iB, int *pB);
      B(const B &b);
      ~B();
      void print() const;
      B& operator=(const B&);
      
   private:
      int grB;
      int *tabB;
};

B& B::operator=(const B& b) {
   if(this != &b){
      A::operator=(b);
      delete[] tabB;
      grB = b.grB;
      if (grB > 0) {
   	     tabB = new int[grB];
         for(int i=0 ; i<grB ; i++){
            tabB[i] = b.tabB[i];
         }
      }
   }
   return *this;
}

int main (){
   int pA[4] = {12, 7, 16, 11};
   int pB[5] = {2, 8, 3, 5, 9};
   A a(4, pA);
   cout << "a.print();" << endl;
   a.print();
   B b1(4, pA, 5, pB);
   cout << "b1.print();" << endl;
   b1.print();  
   B b2 = b1;
   cout << "B b2 = b1;\n";
   cout << "b2.print();" << endl;
   b2.print();
   b1 = b1;
   cout << "b1 = b1;\n";
   cout << "b1.print();" << endl;
   b1.print();
   
   return 0;
}

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

B::B(int iA, int *pA, int iB, int *pB) : 
              A(iA,pA),grB(iB),tabB(nullptr) {
   if (grB > 0) {
   	   tabB = new int[grB];
       for(int i=0 ; i<grB ; i++)
          tabB[i] = pB[i];
   }
}

B::B() : B(0,nullptr,0,nullptr) {}
B::B(const B &b) : A(b), grB(b.grB), tabB(nullptr) {
   if (grB > 0) {
   	   tabB = new int[grB];
       for(int i=0 ; i<grB ; i++)
          tabB[i] = b.tabB[i];
   }
}

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


