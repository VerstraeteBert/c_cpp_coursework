// DemoDestructor1.cpp
// "gewone" destructor

#include <iostream>
using namespace std;

class Basis {
   protected:
   	  int i;
   public:
      Basis(int _i) : i(_i) {
         cout<<"constructor van basis "<< i << endl;
      }
      ~Basis() {
         cout<<"destructor van basis "<< i << endl;
      }
};
 
class Afgeleid : public Basis {
   public:
      Afgeleid(int i) : Basis(i) {
         cout<<"constructor van afgeleid " << i << endl;
      }
      ~Afgeleid() {
         cout<<"destructor van afgeleid " << i << endl;
      }
};

int main() {
   cout << "Basis b1(1);" << endl;
   Basis b1(1);
   
   cout << "\nAfgeleid a(2);" << endl;
   Afgeleid a(2);
   
   cout << "\nBasis *b2 = new Basis(3);" << endl;
   Basis *b2 = new Basis(3);
   cout << "\ndelete b2;" << endl;
   delete b2;
   
   cout << "\nBasis *b3 = new Afgeleid(4);" << endl;
   Basis *b3 = new Afgeleid(4); 
   cout << "\ndelete b3;" << endl;
   delete b3;

   cout << endl;
   return 0;
}

