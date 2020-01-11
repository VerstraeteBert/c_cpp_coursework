#include <iostream>

using namespace std;

string omgekeerde(string& s1) {
    string new_str;
    for (int i = s1.length() - 1; i >= 0; i--) {
        new_str += s1[i];
    }
    return new_str;
}

int main(void) {
    string test = "treB";
    cout << omgekeerde(test) << endl;
}