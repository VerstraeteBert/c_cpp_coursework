#include <iostream>
#include <vector>
using namespace std;

class A {
   public:
   	  A();
      A(const vector<int> &);
	  A(const vector<int> &, int, int *);
      A(const A &);
      A(A &&);     
      A& operator=(const A &);
      A& operator=(A &&);
      virtual ~A();
      A operator*(int) const;
      void print() const;
      void wijzig_array(int, int);
      void wijzig_vector(int, int);
      
   private:
      int grA;
      int *tabA;
      vector<int> vA;
};

A::A(const vector<int> &v, int i, int *p) : 
              vA(v), grA(i), tabA(nullptr) {
   if (grA > 0) {
   	   tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          tabA[i] = p[i];
   }
}

A::A() : grA(0), tabA(nullptr) {}  //en de vector?
A::A(const vector<int> &v) : A(v,0,nullptr) {}


A::A(const A &a) : A(a.vA, a.grA, a.tabA) {
	cout << "copy constructor" << endl;
};


A::A(A &&a) : vA(move(a.vA)), grA(a.grA), tabA(a.tabA) {
   cout << "move constructor" << endl;
   a.grA = 0;
   a.tabA = nullptr;
}

A& A::operator=(const A& a) {
   cout << "= operator" << endl;
   if(this != &a) {
   	  vA = a.vA;
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


A& A::operator=(A&& a) {
   cout << "move operator" << endl;
   if(this != &a) {
   	  vA = move(a.vA);
      delete[] tabA;
      grA = a.grA;
      tabA = a.tabA;
      a.grA = 0;
      a.tabA = nullptr;
   }
   return *this;
}

A::~A() {
   cout << "destructor A" << endl;
   delete[] tabA;
}

A A::operator*(int f) const {
   A res;
   if (grA > 0) {
   	   res.grA = grA;
   	   res.tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          res.tabA[i] = tabA[i] * f;   	
   }
   if (vA.size() > 0) {
      res.vA.reserve(vA.size());
      for (int i=0; i<vA.size(); i++)
         res.vA.push_back(vA[i] *f);
   }
   return res;
}

void A::print() const {
   for (int i=0 ; i<grA ; i++)
      cout << tabA[i] << "  ";
   cout << endl;
   for (int i: vA)
      cout << i << "  ";
   cout << endl;
}

void A::wijzig_array(int index, int waarde) {
	tabA[index] = waarde;
}

void A::wijzig_vector(int index, int waarde) {
	vA[index] = waarde;
}

int main () {
   A a3, a5, a6;
   int pA[4] = {1, 2, 3, 4};
   vector<int> v = {-1, -2, -3};
   A a1(v, 4, pA);
   cout << "a1.print();" << endl;
   a1.print();
 
   cout << endl << "A a2(a1); a2.wijzig_array(1,20); a2.wijzig_vector(1,-20);" << endl;  
   A a2(a1); 
   a2.wijzig_array(1,20);
   a2.wijzig_vector(1,-20);
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a2.print();" << endl;
   a2.print(); 
   
   cout << endl << "a3 = a1; a3.wijzig_array(1,30); a3.wijzig_vector(1,-30);" << endl;
   a3 = a1; 
   a3.wijzig_array(1,30);
   a3.wijzig_vector(1,-30);
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a3.print();" << endl;
   a3.print();      

   cout << endl << "A a4(move(a1)); a4.wijzig_array(1,40); a4.wijzig_vector(1,-40);" << endl;
   A a4(move(a1)); 
   a4.wijzig_array(1,40);
   a4.wijzig_vector(1,-40);
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a4.print();" << endl;
   a4.print(); 

   cout << endl << "a5 = move(a2); a5.wijzig_array(1,50); a5.wijzig_vector(1,-50);" << endl;
   a5 = move(a2); 
   a5.wijzig_array(1,50);
   a5.wijzig_vector(1,-50);
   cout << "a2.print();" << endl;
   a2.print(); 
   cout << "a5.print();" << endl;
   a5.print(); 
   
   cout << endl << "a6 = a3*2;" << endl;
   a6 = a3*2;
   cout << "a3.print();" << endl;
   a3.print(); 
   cout << "a6.print();" << endl;
   a6.print(); 
          
   return 0;
}

