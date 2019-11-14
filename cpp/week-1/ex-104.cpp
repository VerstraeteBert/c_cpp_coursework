#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//const int MAX_LEN = 10;
//const int MIN_LEN = 5;
const int ARR_SIZE = 10;

string genereer_string(int);
void vul_array_met_strings(string [], int, int);
void schrijf (const string [], int);
void bepaal_min_en_max(const string [], int, string &, string &);
void splits_woorden(string [], int &, const string &);

int main () {
    srand(time(NULL));

//    cout << "Geef een getal in tussen " << MIN_LEN << " en " << MAX_LEN << ":" << endl;
//    int strlen;
//    std::cin >> strlen;
//    while (strlen < MIN_LEN  || strlen > MAX_LEN) {
//        cin.clear();
//        cin.ignore(INT_MAX, '\n');
//        cout << "Probeer opnieuw" << endl;
//        std::cin >> strlen;
//    }
//    cin.clear();
//    cin.ignore(INT_MAX, '\n');
//
//    string arr [ARR_SIZE];
//    vul_array_met_strings(arr, ARR_SIZE, strlen);
//    schrijf(arr, ARR_SIZE);
//    string min, max;
//    bepaal_min_en_max(arr, ARR_SIZE, min, max);
//    cout << min << endl;
//    cout << max << endl;

    int count;
    cout << "geef een zin in ajb" << endl;
    string gelezen;
    getline(cin, gelezen);

    string gesplitst [ARR_SIZE];
    splits_woorden(gesplitst, count, gelezen);
    string max; string min;
    bepaal_min_en_max(gesplitst, count, min, max);
    cout << "Max is: " << max << ", min is: " << min << endl;
    return 0;
}

string genereer_string(int len) {
    string str;
    for (int i = 0; i < len; i++) {
        int random = rand() % 26;
        str += 'a' + random;
    }
    return str;
}

void vul_array_met_strings(string strings [], int num_str, int len_str) {
    for (int i = 0; i < num_str; i++) {
        strings[i] = genereer_string(len_str);
    }
}

void schrijf(const string strings [], int size) {
    for (int i = 0; i < size; i++) {
        cout << strings[i] << " ";
    }
    cout << endl;
}

void bepaal_min_en_max(const string strings [], int num, string &min, string &max) {
    if (num < 1) return;
    min = strings[0];
    max = strings[0];
    for (int i = 1; i < num; i++) {
        if (strings[i] < min) min = strings[i];
        if (strings[i] > max) max = strings[i];
    }
}

void splits_woorden(string strings [], int &size, const string &zin) {
    size = 0;
    size_t str_len = zin.length();
    size_t l = 0;

    while (l < str_len && isspace(zin[l])) {
        l++;
    }
    size_t r = zin.find(" ", l);

    while (size < ARR_SIZE && l < str_len && r < str_len && r != string::npos) {
        strings[size] = zin.substr(l, r - l);
        size++;
        l = r;
        while (l < str_len && isspace(zin[l])) {
            l++;
        }
        r = zin.find(" ", l);
    }

    if (r == string::npos && size < ARR_SIZE) {
        strings[size] = zin.substr(l, str_len - l);
        size++;
    }
}
