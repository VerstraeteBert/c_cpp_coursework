#include <fstream>
#include <iostream>

using namespace std;

int main () {
    int freq [26] = { 0 };
    ifstream inv; inv.open("../../fixtures/lord.txt");
    if (!inv.is_open()) {
        cout << "Openen niet gelukt";
        return 1;
    }
    string line;
    getline(inv, line);
    while (!inv.fail()) {
        int len = line.length();
        for (int i = 0; i < len; i++) {
            char curr = line[i];
            if (curr >= 'a' && curr <= 'z') {
                freq[curr - 'a']++;
            }
        }
        getline(inv, line);
    }
    inv.close();
    if (!inv.eof()) {
        cout << "Er ging iets fout tijdens het lezen van het bestand" << endl;
        return 1;
    }
    for (int i = 0; i < 26; i++) {
        cout <<  (char) ('a' + i) << ": " << freq[i] << endl;
    }
    return 0;
}
