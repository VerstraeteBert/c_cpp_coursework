#include <iostream>
#include "nmspc.cpp"  //let op: " ", niet < >

/*
using std::string;
using std::cout;
using std::cin;
using std::endl;
*/

using namespace std;
/*
void proc() {
	cout << "dit is een procedure"
	     << endl;
}*/

//onderstaande using niet toevoegen wegens
//conflict met procedure proc()
using A::proc;

//ook onderstaande using niet toevoegen wegens zelfde reden
//using namespace A;
	
int main() {

    string s;
    cout << "Geef je naam in: ";
    cin >> s;
    cout << "Dag " << s << endl;
    int getal;
    cout << "Geef nu een getal in: ";
    cin >> getal;
    cout << getal << " + 1 = " 
         << (getal + 1) << endl;
         
    A::proc();
    proc();
    return 0;
}

