#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream of("tekst.txt", ios::out);
    if (!of.is_open()) {
        cout << "failed to open file" << endl;
    }
    string write;
    for (int i = 0; i < 5; i++) {
        getline(cin, write);
        of << write << endl;
    }
    of.close();
}
