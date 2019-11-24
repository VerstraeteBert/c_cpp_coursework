#include <iostream>

using namespace std;

typedef struct {
    string naam;
    int leeftijd;
    double lengte;
} persoon;

template <typename T, typename E>
T grootste (T [], int);
int grootte(const & string);
double grootte(double);
double grootte(const persoon &);
void initialiseer(persoon &, string, int, double);
void print(const persoon &);


int main () {
    double getallen[5] = {5.5, 7.7, 2.2, 9.9, 9.8};
    string woorden[3] = {"geloof", "hoop", "de liefde"};
    cout << "Grootste woord is: " << grootste<string, int>(woorden, 3) << endl;
    cout << "Het grootste getal is: " << grootste<double, double>(getallen, 5) << "." << endl;

    persoon personen [3];
    initialiseer(personen[0], "Bert", 22, 1.92);
    initialiseer(personen[1], "Michiel", 21, 1.34);
    initialiseer(personen[2], "Wim", 73, 1.72);
    print(personen[2]);
    persoon p = grootste<persoon, double>(personen, 3);
    print(p);
}

void print(const persoon &pers) {
    cout << "Dit is " << pers.naam
        << " hij is " << pers.leeftijd << " jaar oud"
        << " en is " << pers.lengte << "m groot."
        << endl;
}

void initialiseer(persoon &pers, string name, int leeftijd, double lengte) {
    pers.naam = name;
    pers.leeftijd = leeftijd;
    pers.lengte = lengte;
}

template <class T, class E>
T grootste (T  arr [], int size) {
    T grootste = arr[0];
    E max_grootte = grootte(arr[0]);
    for (int i = 1; i < size; i++) {
        E curr_grootte = grootte(arr[i]);
        if (max_grootte < curr_grootte) {
            grootste = arr[i];
            max_grootte = curr_grootte;
        }
    }
    return grootste;
}

double grootte(double el) {
    return el;
}

int grootte (const string & el) {
    return el.length();
}

double grootte(const persoon & p) {
    return p.lengte;
}
