#include <fstream>
#include <iostream>

using namespace std;

// moeten refs zijn, kan streams NIET kopiëren
void mix_schrijf(ifstream &, ifstream &, ofstream &);

int main () {
    ifstream odd("../../fixtures/stationnetje.txt");
    if (!odd.is_open()) {
        cout << "Failed to open odd file";
        return 1;
    }
    ifstream even("../../fixtures/paddestoel.txt");
    if (!even.is_open()) {
        cout << "Failed to open even file";
        return 1;
    }
    ofstream mix;
    mix.open("mix.txt");
    if (!mix.is_open()) {
        cout << "Failed to open mix file";
        return 1;
    }

    mix_schrijf(odd, even, mix);
    odd.close();
    even.close();
    mix.close();

    return 0;
}

void mix_schrijf(ifstream & odd, ifstream & even, ofstream & mix) {
    int i = 0;
    string line;
    getline(odd, line);
    even.ignore(INT_MAX, '\n');
    while (!odd.fail() && !even.fail()) {
        mix << line;
        if (i == 0) {
            getline(even, line);
            odd.ignore(INT_MAX, '\n');
        } else {
            getline(odd, line);
            even.ignore(INT_MAX, '\n');
        }
        i = (i + 1) % 2;
    }

    while (!odd.fail()) {
        getline(odd, line);
        mix << line;
    }

    while (!even.fail()) {
        getline(even, line);
        mix << line;
    }
}
