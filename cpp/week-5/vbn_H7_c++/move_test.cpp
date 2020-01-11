#include <string>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void write_pointer(const unique_ptr<int> &p) {
   if (p) 
     cout << *p << endl; 
   else 
     cout << "empty\n";
}

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
	for (T el : v)
	   os << el << "  ";
	return os;
}

class Persoon {
	public:
		Persoon(const string &nm, int lft) : 
		             naam(nm), leeftijd(lft) {}
		void print() const {
			cout << naam << " " << leeftijd << endl;
		}
	private:
		string naam;
		int leeftijd;
};

int main() {
   unique_ptr<int> up1, up2;
   up1 = make_unique<int>(101); 
   up2 = make_unique<int>(202);
   up2 = move(up1); 
   cout << "move-operator bij unique pointers: " << endl;                     
   cout << "up1: ";
   write_pointer(up1); 
   cout << "up2: ";
   write_pointer(up2);
   
   vector<int> v1{1,2,3,4,5};
   vector<int> v2(move(v1));
   cout << "\nmoveconstructor bij vectoren: " << endl;                     
   cout << "v1: " << v1 << endl;
   cout << "v2: " << v2 << endl;
   
   int a = 1;
   int b = move(a);
   cout << "\nmove-operator bij int\'s': " << endl;  
   cout << a << " " << b << endl;
	
   string s1 = "string1", s2 = "string2", s3 = "string3";
   s2 = move(s1);
   string s4(move(s3));
   cout << "\nmove-operator/constructor bij strings: " << endl;  
   cout << "s1: " << s1 << endl;
   cout << "s2: " << s2 << endl;
   cout << "s3: " << s3 << endl;
   cout << "s4: " << s4 << endl;
	
   Persoon p1("maya",13);
   Persoon p2(p1);
   cout << "\ncopyconstructor persoon:" << endl;
   p1.print();
   p2.print();
   Persoon p3("lore",15);
   p3 = move(p1);
   cout << "\nmoveconstructor persoon:" << endl;
   p1.print();
   p3.print();
   
   Persoon *pp1 = &p3;
   Persoon *pp2 = move(pp1);
   cout << "\nmove operator op een pointer naar persoon:" << endl;
   pp1->print();
   pp2->print();
}




