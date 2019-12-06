#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Rechthoek {
public:
    Rechthoek();
    Rechthoek(int, int);

    int basis;
    int hoogte;

    int oppervlakte() const;
    int omtrek() const;
    // virtual declareren als je een functie wilt overschrijven in afgeleide klassen
    void virtual print(ostream&) const;
    friend ostream& operator<<(ostream &, const Rechthoek&);
};

Rechthoek::Rechthoek() {
    this->basis = 1;
    this->hoogte = 1;
}

Rechthoek::Rechthoek(int basis, int hoogte) {
    this->basis = basis;
    this->hoogte = hoogte;
}

int Rechthoek::oppervlakte() const {
    return this->basis * this->hoogte;
}

int Rechthoek::omtrek() const {
    return this->basis * 2 + this->hoogte * 2;
}

void Rechthoek::print(ostream & out) const {
    out << "Rechthoek " << this->hoogte << " op " << this->basis << endl;
}

ostream& operator<<(ostream & out, const Rechthoek& rechthoek) {
    rechthoek.print(out);
    return out;
}

// afgeleid van Rechthoek; pas aan in hoofding
class GekleurdeRechthoek : public Rechthoek {
public:
    string kleur;
    GekleurdeRechthoek();
    GekleurdeRechthoek(int, int, const string& = "onbekend");

    void print(ostream&) const;
};

GekleurdeRechthoek::GekleurdeRechthoek() : Rechthoek() {
    this->kleur = "onbekend";
};

GekleurdeRechthoek::GekleurdeRechthoek(int basis, int hoogte, const string& kleur)
        : Rechthoek(basis, hoogte) {
    this->kleur = kleur;
};

void GekleurdeRechthoek::print(ostream& out) const {
    Rechthoek::print(out);
    out << " kleur: " << this->kleur << endl;
};

// afgeleid van Rechthoek; pas aan in hoofding
class Vierkant : public Rechthoek {
public:
    Vierkant();
    Vierkant(int);

    void print(ostream&) const;
    // geen extra attributen voorzien!
};

Vierkant::Vierkant() : Rechthoek() {};

Vierkant::Vierkant(int basis) : Rechthoek::Rechthoek(basis, basis) {}

void Vierkant::print(ostream& out) const {
    out << "Vierkant " << this->hoogte << " op " << this->basis << endl;
}

int main () {
    unique_ptr<Rechthoek> r2(new Rechthoek(4, 6));
    unique_ptr<Rechthoek> gr1(new GekleurdeRechthoek());
    unique_ptr<Rechthoek> gr3(new GekleurdeRechthoek(6, 9, "rood"));
    unique_ptr<Rechthoek> v2(new Vierkant(10));

    vector<unique_ptr<Rechthoek>> v;
    v.push_back(move(r2));
    v.push_back(move(gr1));
    v.push_back(move(gr3));
    v.push_back(move(v2));

    for(size_t i = 0; i<v.size(); i++) {
        cout << *(v[i]);
        cout << " oppervlakte: " << v[i]->oppervlakte() << endl
             << " omtrek: " << v[i]->omtrek() << endl;
    }

    return 0;
}
