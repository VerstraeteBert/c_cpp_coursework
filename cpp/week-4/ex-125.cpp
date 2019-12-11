#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Rechthoek {
public:
    Rechthoek();
    Rechthoek(int, int);
    int oppervlakte() const;
    int omtrek() const;
    // virtual declareren als je een functie wilt overschrijven in afgeleide klassen
    void virtual print(ostream&) const;
    friend ostream& operator<<(ostream &, const Rechthoek&);
private:
    int basis;
    // protected -> zelfde eigenschappen als private in de klasse waar het gedifinieerd is
    // bij overerving worden deze ook toegankelijk voor verdere afleidingen !!
protected:
    int hoogte;
};

Rechthoek::Rechthoek() : basis(1), hoogte(1) {};

Rechthoek::Rechthoek(int b, int h)  : basis(b), hoogte(h) {};

int Rechthoek::oppervlakte() const {
    return basis * hoogte;
}

int Rechthoek::omtrek() const {
    return (basis + hoogte) * 2;
}

void Rechthoek::print(ostream & out) const {
    out << "Rechthoek: " << hoogte << " op " << basis << endl;
}

ostream& operator<<(ostream & out, Rechthoek& rechthoek) {
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

GekleurdeRechthoek::GekleurdeRechthoek() : Rechthoek(), kleur("onbekend") {};

GekleurdeRechthoek::GekleurdeRechthoek(int basis, int hoogte, const string& kleur)
        : Rechthoek(basis, hoogte) {
    this->kleur = kleur;
};

void GekleurdeRechthoek::print(ostream& out) const {
    Rechthoek::print(out);
    out << "  kleur: " << this->kleur << endl;
};

// afgeleid van Rechthoek; pas aan in hoofding
class Vierkant : public Rechthoek {
public:
    Vierkant(int = 1);
    void print(ostream&) const;
    // geen extra attributen voorzien!
};

Vierkant::Vierkant(int zijde) : Rechthoek::Rechthoek(zijde, zijde) {}

void Vierkant::print(ostream& out) const {
    out << "Vierkant: zijde: " << hoogte << endl;
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
