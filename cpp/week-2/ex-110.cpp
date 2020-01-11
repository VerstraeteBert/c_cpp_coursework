#include<iostream>
#include<functional>

using namespace std;

void schrijf(const string& s, const int arr [], int len) {
    cout << s;
    for (int i = 0; i < len - 1; i++) {
        cout << arr[i] << " , ";
    }
    cout << arr[len - 1] << endl;
}

void vul_array(const int a [], const int b [], int c [], int len, function<int (int, int)> cb) {
    for (int i = 0; i < len; i++) {
        c[i] = cb(a[i], b[i]);
    }
}

int main(){
    const int GROOTTE = 10;
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[] = {0,10,20,30,40,50,60,70,80,90};
    int c[GROOTTE];

    vul_array(a,b,c,GROOTTE, [](int a, int b) -> int {
        return a + b;
    });
    schrijf("SOM:      ",c,GROOTTE);

    vul_array(a,b,c,GROOTTE, [](int a, int b) -> int {
        return a * b;
    });
    schrijf("PRODUCT:  ",c,GROOTTE);

    vul_array(a,b,c,GROOTTE, [](int a, int b) -> int {
        return a - b;
    });
    schrijf("VERSCHIL: ",c,GROOTTE);

    return 0;
}
