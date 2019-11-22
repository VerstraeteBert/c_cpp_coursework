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

template <class T>
ostream& operator<<(ostream& out, const vector<T> & vectors) {
    cout << endl;
    for (T x : vectors) {
        cout << x << " ";
    }
    return out;
}

int main() {
    vector<int> vect_i;
    vect_i.reserve(10);
    for (int i = 0; i < 10; i++) {
        vect_i.push_back(i);
    }
    cout << vect_i;

    vector<bool> vect_b = {true, false, true};
    cout << vect_b;

    vector<double> vect_d = { 10.2, 30.49, -90.2};
    cout << vect_d;

    vector<Persoon> vect_p;
    vect_p.reserve(1);
    Persoon p;
    initialiseer(p, "bert", 20, 30.56);
    vect_p.push_back(p);
    cout << vect_p;

    vector<vector<Persoon>> vector_v = { vect_p };
    cout << vector_v;

    return 0;
}
