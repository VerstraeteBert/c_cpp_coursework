#include<iostream>
#include<functional>

using namespace std;

void schrijf (const string tekst, const int * c, int size) {
    cout << tekst;
    for (int i = 0; i < size; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

void vul_array(const int * a, const int * b, int * c, size_t grootte, function<int (int, int)> func) {
    for (size_t i = 0; i < grootte; i++) {
        c[i] = func(a[i], b[i]);
    }
}

int main(){
    const int GROOTTE = 10;
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[] = {0,10,20,30,40,50,60,70,80,90};
    int c[GROOTTE];

    vul_array(a,b,c,GROOTTE, [](int a, int b) { return a + b; });
    schrijf("SOM:      ",c,GROOTTE);

    vul_array(a,b,c,GROOTTE, [](int a, int b) { return a * b; });
    schrijf("PRODUCT:  ",c,GROOTTE);

    vul_array(a,b,c,GROOTTE, [](int a, int b) { return a - b; });
    schrijf("VERSCHIL: ",c,GROOTTE);

    return 0;
}
