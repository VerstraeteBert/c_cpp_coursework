#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream inv("../../fixtures/lord.txt");
    if (!inv.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }
    int occurences [26] = { 0 };
    char curr_char;
    inv >> curr_char;
    while (!inv.fail()) {
        if ('a' <= curr_char && curr_char <= 'z') {
            occurences[curr_char - 'a']++;
        }
        inv >> curr_char;
    }
    for (int i = 0; i < 26; i++) {
        cout << (char) ('a' + i) << ": " << occurences[i] << endl;
    }
    inv.close();
}
