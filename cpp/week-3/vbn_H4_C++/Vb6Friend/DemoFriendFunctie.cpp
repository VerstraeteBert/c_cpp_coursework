#include <iostream>
using namespace std;

class A {
   private:
      int i;
   public:
      A(int _i=0):i(_i) {}
      int get_i() const;
      friend int fr(const A &);
};

int A::get_i() const {
   return i;
}

int fr(const A &a) {
   return a.i;
}

int main() {
	A a(7);
	cout << a.get_i() << "  " << fr(a);
	return 0;
}
