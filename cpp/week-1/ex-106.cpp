#include <iostream>

using namespace std;

void schrijf(const int ints [], int len, bool achterstevoren = false, char tussenteken = ' ');

int main () {
    int t [] = {1, 3, 5, 7, 9, 11, 13};
    schrijf(t, 7);
    schrijf(t, 7, true);
    schrijf(t, 7, false, '-');
    schrijf(t, 7, true, '-');
    return 0;
}

void schrijf(const int ints [], int len, bool achterstevoren, char tussenteken) {
    if (!achterstevoren) {
        cout << ints[0];
        for (int i = 1; i < len; i++) {
            cout << tussenteken << ints[i];
        }
    } else {
        cout << ints[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            cout << tussenteken << ints[i];
        }
    }
    cout << endl;
}
