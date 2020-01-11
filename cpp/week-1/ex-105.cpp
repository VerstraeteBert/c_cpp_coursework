#include <iostream>

using namespace std;

typedef struct {
    string naam;
    int leeftijd;
    double lengte;
} Persoon;

template <class T>
T grootste(T arr [], int len);

int grootte(const string& el);
double grootte(double el);

void initialiseer(Persoon & p, const string& naam, double lengte, int leeftijd);
void print(const Persoon & p);

int main () {
    double getallen[5] = {5.5, 7.7, 2.2, 9.9, 9.8};
    string woorden[3] = {"geloof", "hoop", "de liefde"};
    cout << "Grootste woord is: " << grootste<string>(woorden, 3) << endl;
    cout << "Het grootste getal is: " << grootste<double>(getallen, 5) << "." << endl;

    Persoon personen [3];
    initialiseer(personen[0], "test", 1.91, 22);
    initialiseer(personen[1], "test2", 1.81, 37);
    initialiseer(personen[2], "test3", 1.92, 3);

    for (int i = 0; i < 3; i++) {
        print(personen[i]);
    }
 }

template<class T>
T grootste(T arr [], int len) {
    T gr = arr[0];
    for (int i = 1; i < len; i++) {
        if (grootte(gr) < grootte(arr[i])) {
            gr = arr[i];
        }
    }
    return gr;
}

double grootte(double el) {
    return el;
}

int grootte(const string& el) {
    return el.size();
}

int grootte(const Persoon & p) {
    return p.lengte;
}

void initialiseer(Persoon & p, const string& naam, double lengte, int leeftijd) {
    p.naam = naam;
    p.lengte = lengte;
    p.leeftijd = leeftijd;
}

void print(const Persoon & p) {
    cout << "Dit is " << p.naam
         << ", hij/zij is " << p.lengte << "m groot"
         << " en is " << p.leeftijd << " jaar oud."
         << endl;
}