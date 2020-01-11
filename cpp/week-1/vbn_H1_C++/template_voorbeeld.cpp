#include <iostream>

template<typename T1, typename T2>
void test(int, const T1&, const T2 &);

void test(int, char, double);

int main() {
   test(1,2,3);
   test(1,'2',3);
   test(1,'2',3.0);
   test(1,2,3.0);
}

template<typename T1, typename T2>
void test(int i, const T1& t1, const T2 & t2) {
	std::cout<<"versie met templates" << std::endl
	         << i << " " << t1 << " " << t2 << std::endl;
}
//merk op: zowel bij declaratie als definitie van de functie moet
//template vermeld worden

void test(int i, char ch, double d) {
	std::cout<<"versie zonder templates" << std::endl
	         << i << " " << ch << " " << d << std::endl;
}
