#include <iostream>
using namespace std;

int fac(int getal) {
    if (getal < 0)
        throw "exceptie: negatief getal!"; 
    int res = 1;
    for (int i = 2 ; i <= getal ; i++)
        res *= i;
    return res;
}
 
int main() {
    int getal;
    cout << "getal: ";
    cin >> getal;
    try {
        cout << getal << "! = " 
             << fac(getal) << endl;
        cout << "einde1" << endl;
    }
    catch (...) {
        cout << "oei, een exceptie" << endl;
    } 
    cout << "einde2" << endl;
    return 0;
}
