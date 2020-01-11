#include <vector>
#include <iostream>

using namespace std;

typedef struct {
    string naam;
    int leeftijd;
    double lengte;
} Persoon;

ostream& operator<<(ostream& out, const Persoon & p){
    out << p.naam << " (" << p.leeftijd << " jaar, "
        << (int)p.lengte <<"m" << (int)((p.lengte-1)*100) <<")";
    return out;
}

void initialiseer(Persoon &pers, string name, int leeftijd, double lengte) {
    pers.naam = name;
    pers.leeftijd = leeftijd;
    pers.lengte = lengte;
}

void print(const vector<int>& vect) {
    for (const int i : vect) {
        cout << i << " ";
    }
    cout << endl;
}

template <class T>
void print(const vector<T>& vect) {
    for (const T& el : vect) {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
ostream& operator<<(ostream& out, const vector<T>& vect) {
    for (const T& el : vect) {
        cout << el << " ";
    }
    cout << endl;
    return out;
}

int main() {
    vector<int> v_i;
    v_i.reserve(10);
    for (int i = 0; i < 10; i++) {
        v_i.push_back(i);
    }
    print(v_i);
    cout << v_i;

    vector<bool> v_b = {
            true,
            false,
            true
    };
    print(v_b);
    cout << v_b;

    vector<string> v_s = {
        "hanlonk",
        "test"
    };
    print(v_s);
    cout << v_s;

    vector<char> v_c = {
        't',
        'e',
        's',
        't'
    };
    print(v_c);
    cout << v_c;

    vector<vector<string>> v_v = {
            v_s,
    };
    cout << (v_v);
    return 0;
}
