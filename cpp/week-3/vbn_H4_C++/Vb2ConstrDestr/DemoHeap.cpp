#include <iostream>
using namespace std;

class myclass {
   private:
      int i;
      
   public:
      myclass(int i);
      ~myclass() {
         cout << "Destructor object " << i <<endl;
      }
};

myclass::myclass(int i) {
   cout << "Constructor object "<< i << endl;
   this->i = i;
}

int main() {
 myclass *a = new myclass(1);
 for (int i=2 ; i<4 ; i++) 
	myclass *b = new myclass(i);
 delete a;
 return 0;
}


