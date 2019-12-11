#include <iostream>
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
    Rechthoek r1;
    r1.print(cout);
    cout << "  oppervlakte: " << r1.oppervlakte() << endl
         << "  omtrek: " << r1.omtrek() << endl;

    Rechthoek r2(4,6);
    cout << r2;
    cout << "  oppervlakte: " << r2.oppervlakte() << endl
         << "  omtrek: " << r2.omtrek() << endl;

    GekleurdeRechthoek gr1;
    gr1.print(cout);
    cout << "  oppervlakte: " << gr1.oppervlakte() << endl
         << "  omtrek: " << gr1.omtrek() << endl;

    GekleurdeRechthoek gr2(5,7);
    cout << gr2;
    cout << "  oppervlakte: " << gr2.oppervlakte() << endl
         << "  omtrek: " << gr2.omtrek() << endl;

    GekleurdeRechthoek gr3(6,9,"rood");
    gr3.print(cout);
    cout << "  oppervlakte: " << gr3.oppervlakte() << endl
         << "  omtrek: " << gr3.omtrek() << endl;

    Vierkant v1;
    cout << v1;
    cout << "  oppervlakte: " << v1.oppervlakte() << endl
         << "  omtrek: " << v1.omtrek() << endl;

    Vierkant v2(10);
    v2.print(cout);
    cout << "  oppervlakte: " << v2.oppervlakte() << endl
         << "  omtrek: " << v2.omtrek() << endl;
    return 0;
}
