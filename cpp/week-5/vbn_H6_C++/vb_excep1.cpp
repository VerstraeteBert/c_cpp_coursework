#include <iostream>
using namespace std;

int fac(int);

int main() {
    int getal;
    cout << "getal: ";
    cin >> getal;
    cout << getal << "! = " << fac(getal) << endl;
    cout << "einde" << endl;
    return 0;
}

int fac(int getal) {
    if (getal < 0)
        throw "exceptie: negatief getal!"; 
    int res = 1;
    for (int i = 2 ; i <= getal ; i++)
        res *= i;
    return res;
} 


