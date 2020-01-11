#include <fstream>
#include <iostream>

using namespace std;

void mix_schrijf(ifstream& odd, ifstream& even, ofstream& mix);

int main () {
    ifstream odd("../../fixtures/stationnetje.txt");
    if (!odd.is_open()) {
        cout << "Failed to open odd file" << endl;
    }

    ifstream even("../../fixtures/paddestoel.txt");
    if (!even.is_open()) {
        cout << "Failed to open even file" << endl;
    }

    ofstream mix("./mix.txt");
    if (!mix.is_open()) {
        cout << "Failed to open output file" << endl;
    }

    mix_schrijf(odd, even, mix);

    return 0;
}

void mix_schrijf(ifstream& odd, ifstream& even, ofstream& mix) {
    int even_or_odd = 1;
    string line;
    while (!odd.fail() && !even.fail()) {
        if (even_or_odd % 2 == 1) {
            getline(odd, line);
            odd.ignore(INT_MAX, '\n');
        } else {
            getline(even, line);
            even.ignore(INT_MAX, '\n');
        }
        mix << line;
        even_or_odd++;
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

