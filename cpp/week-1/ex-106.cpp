#include <iostream>

using namespace std;

void schrijf(const int [], int, bool = false, char =  ' ');

int main () {
    int t [] = {1, 3, 5, 7, 9, 11, 13};
    schrijf(t, 7);
    schrijf(t, 7, true);
    schrijf(t, 7, false, '-');
    schrijf(t, 7, true, '-');
    return 0;
}

// default waarden niet herhalen
void schrijf (const int arr [], int aantal, bool achterstevoren, char tussenteken) {
    if (aantal < 1) return;
    if (achterstevoren) {
        cout << arr[aantal - 1];
        for (int i = aantal - 2; i >= 0; i--) {
            cout << tussenteken;
            cout << arr[i];
        }
    } else {
        cout << arr[0];
        for (int i = 1; i < aantal; i++) {
            cout << tussenteken;
            cout << arr[i];
        }
    }
    cout << endl;
}
