#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

const int N = 4;

string genereer_string(int);
void vul_array_met_strings(string [], int, int);
void schrijf(const string [], int);
void bepaal_min_en_max(const string [], int, string&, string&);
void splits_woorden(string [], int, const string&);

int main() {
    srand(time(NULL));
    int len;
    cout << "Geef een getal in tussen 1 en 4" << endl;
    cin >> len;
    while (len < 1 || len > 4) {
        cout << "Fout: getal niet tussen 1 en 4" << endl;
        cin.clear();
        fflush(stdin);
        cin >> len;
    }
    string strings [N];
    vul_array_met_strings(strings, N, len);
    schrijf(strings, N);
    string min;
    string max;
    bepaal_min_en_max(strings, N, min, max);
    cout << min << endl << max << endl;
    return 0;
}

string genereer_string(int len) {
    string s;
    for (int i = 0; i < len; i++) {
        s += 'a' + rand() % 26;
    }
    return s;
}

void vul_array_met_strings(string tab [], int n, int len) {
    for (int i = 0; i < n; i++) {
        tab[i] = genereer_string(len);
    }
}

void schrijf(const string strings [], int size) {
    for (int i = 0; i < size; i++) {
        cout << strings[i] << endl;
    }
}

void bepaal_min_en_max(const string strings [], int size, string& min, string& max) {
    max = strings[0];
    min = strings[0];
    for (int i = 0; i < size; i++) {
        if (strings[i] > max) {
            max = strings[i];
        }
        if (strings[i] < min) {
            min = strings[i];
        }
    }
}

void splits_woorden(string tab [], int& aantal, const string& zin) {
    int i = 0;
    int start = 0;
    int next_space = zin.find(" ");
    while(i < N && next_space != string::npos) {
        tab[i] = zin.substr(start, next_space - start);
        start = next_space + 1;
        next_space = zin.find(" ", start);
        i++;
    }
    if (i < N) {
        tab[i] = zin.substr(start);
        i++;
    }
    aantal = i;
}
