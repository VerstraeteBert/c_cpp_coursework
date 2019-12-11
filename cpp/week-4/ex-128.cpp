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
    GekleurdeRechthoek();
    GekleurdeRechthoek(int, int, const string& = "onbekend");

    void print(ostream&) const;

protected:
    string kleur;
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

class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek {
public:
    GekleurdVierkant(int = 1, const string& = "onbekend");
    void print(ostream &) const;
};

GekleurdVierkant::GekleurdVierkant(int zijde, const string& kleur)
    : GekleurdeRechthoek(zijde, zijde, kleur), Vierkant(zijde) {};

void GekleurdVierkant::print(ostream & out) const {
    Vierkant::print(out);
    // kleur is protected
    out << " kleur: " << kleur << endl;
}

// moet herschreven worden -> ambiguous base
ostream& operator<<(ostream& out, const GekleurdVierkant& v) {
    v.print(out);
    return out;
}

int main () {
    GekleurdVierkant gv1;
    gv1.print(cout);
    cout << "  oppervlakte: " << gv1.Vierkant::oppervlakte() << endl
         << "  omtrek: " << gv1.Vierkant::omtrek() << endl;

    GekleurdVierkant gv2(12);
    gv2.print(cout);
    cout << "  oppervlakte: " << gv2.Vierkant::oppervlakte() << endl
    << "  omtrek: " << gv2.Vierkant::omtrek() << endl;

    GekleurdVierkant gv3(15,"geel");
    cout << gv3;
    cout << "  oppervlakte: " << gv3.Vierkant::oppervlakte() << endl
    << "  omtrek: " << gv3.Vierkant::omtrek() << endl;

    return 0;
}
