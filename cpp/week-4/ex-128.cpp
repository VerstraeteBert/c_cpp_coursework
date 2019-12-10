#include <iostream>
using namespace std;

class Rechthoek  {
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
    out << "Rechthoek: " << this->hoogte << " op " << this->basis << endl;
}

ostream& operator<<(ostream & out, Rechthoek& rechthoek) {
    rechthoek.print(out);
    return out;
}

// afgeleid van Rechthoek; pas aan in hoofding
class GekleurdeRechthoek : public virtual Rechthoek {
public:
    string kleur;
    GekleurdeRechthoek();
    GekleurdeRechthoek(int, int, const string& = "onbekend");

    void virtual print(ostream&) const;
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
class Vierkant : public virtual Rechthoek {
public:
    Vierkant();
    Vierkant(int);

    void virtual print(ostream&) const;
    // geen extra attributen voorzien!
};

Vierkant::Vierkant() : Rechthoek() {};

Vierkant::Vierkant(int basis) : Rechthoek::Rechthoek(basis, basis) {}

void Vierkant::print(ostream& out) const {
    out << "Vierkant: zijde: " << this->basis << endl;
}

class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek {
    public:
        GekleurdVierkant();
        GekleurdVierkant(int);
        GekleurdVierkant(int, const string&);

        void print(ostream &) const;

        friend ostream& operator<<(ostream &, const GekleurdVierkant&);
};

GekleurdVierkant::GekleurdVierkant() {};

GekleurdVierkant::GekleurdVierkant(int zijde)  {
    this-> basis = zijde;
    this-> hoogte = zijde;
};

GekleurdVierkant::GekleurdVierkant(int zijde, const string & kleur)  {
    this-> basis = zijde;
    this->hoogte = zijde;
    this->kleur = kleur;
}

ostream& operator<<(ostream& out, const GekleurdVierkant& vk) {
    vk.print(out);
    return out;
}

void GekleurdVierkant::print(ostream & out) const {
    Vierkant::print(out);
    out << "  Kleur: " << this-> kleur << endl;
}

int main () {
    GekleurdVierkant gv1;
    gv1.print(cout);
    cout << "  oppervlakte: " << gv1.oppervlakte() << endl
         << "  omtrek: " << gv1.omtrek() << endl;

    GekleurdVierkant gv2(12);
    gv2.print(cout);
    cout << "  oppervlakte: " << gv2.oppervlakte() << endl
    << "  omtrek: " << gv2.omtrek() << endl;

    GekleurdVierkant gv3(15,"geel");
    cout << gv3;
    cout << "  oppervlakte: " << gv3.oppervlakte() << endl
    << "  omtrek: " << gv3.omtrek() << endl;

    return 0;
}
