#include <iostream>
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

    virtual void print(ostream&) const;
};

GekleurdeRechthoek::GekleurdeRechthoek() : Rechthoek() {
    this->kleur = "onbekend";
};

// afgeleid van Rechthoek; pas aan in hoofding
class Vierkant : public Rechthoek {
public:
    Vierkant();
    Vierkant(int);

    virtual void print(ostream&) const;
    // geen extra attributen voorzien!
};

Vierkant::Vierkant() : Rechthoek() {};

Vierkant::Vierkant(int basis) : Rechthoek::Rechthoek(basis, basis) {}

void Vierkant::print(ostream& out) const {
    out << "Vierkant " << this->hoogte << " op " << this->basis << endl;
}

class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek {
    // geen extra attributen voorzien!
    public:
        GekleurdVierkant() : Vierkant(), GekleurdeRechthoek() {};
        void print(ostream&) const;
};

void GekleurdVierkant::print(ostream &) const {

}

int main () {
    GekleurdVierkant gv1;
        cout << GekleurdVierkant(gv1);
    cout << "  oppervlakte: " << gv1.Vierkant::oppervlakte()
         << "  omtrek: " << gv1.Vierkant::omtrek();

//    GekleurdVierkant gv2(12);
//    gv2.print(cout);
//    cout << "  oppervlakte: " << ...
//    << "  omtrek: " << ...
//
//    GekleurdVierkant gv3(15,"geel");
//    cout << gv3;
//    cout << "  oppervlakte: " << ...
//    << "  omtrek: " << ...
    return 0;
}