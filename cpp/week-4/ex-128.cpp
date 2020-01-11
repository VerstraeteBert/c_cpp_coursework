#include <iostream>

using namespace std;

class Rechthoek {
public:
    Rechthoek();
    Rechthoek(int, int);

    virtual ~Rechthoek() {};

    int oppervlakte() const;
    int omtrek() const;
    virtual void print(ostream&) const;
private:
    int basis;
protected:
    int hoogte;
};

class GekleurdeRechthoek : public Rechthoek {
public:
    GekleurdeRechthoek();
    GekleurdeRechthoek(int, int, const string& kleur = "onbekend");
    virtual void print(ostream&) const;
protected:
    string kleur;
};

class Vierkant : public Rechthoek {
public:
    Vierkant(int = 1);
    virtual void print(ostream &out) const;
};

Rechthoek::Rechthoek() : basis(1), hoogte(1) {}

Rechthoek::Rechthoek(int b, int h) : basis(b), hoogte(h) {}

void Rechthoek::print(ostream& out) const {
    out << "Rechthoek: " << basis << " op " << hoogte << endl;
}

int Rechthoek::oppervlakte() const {
    return basis * hoogte;
}

int Rechthoek::omtrek() const {
    return (basis + hoogte) * 2;
}

GekleurdeRechthoek::GekleurdeRechthoek() : kleur("onbekend") {}

GekleurdeRechthoek::GekleurdeRechthoek(int basis, int hoogte, const string &kleur) : Rechthoek(basis, hoogte), kleur(kleur) {};

void GekleurdeRechthoek::print(ostream& out) const {
    Rechthoek::print(out);
    out << "  kleur:" << kleur << endl;
}

Vierkant::Vierkant(int zijde) : Rechthoek(zijde, zijde) {};

void Vierkant::print(ostream& out) const {
    out << "Vierkant: zijde " << hoogte << endl;
}

ostream& operator<<(ostream& out, const Rechthoek& rh) {
    rh.print(out);
    return out;
}

class GekleurdVierkant : public Vierkant, GekleurdeRechthoek {
public:
    GekleurdVierkant(int = 1, const string& = "onbekend");
    void print(ostream& out) const;
};

GekleurdVierkant::GekleurdVierkant(int zijde, const string & kleur)
        : Vierkant(zijde), GekleurdeRechthoek(zijde, zijde, kleur) {}

void GekleurdVierkant::print(ostream &out) const {
    Vierkant::print(out);
    out << "  Kleur: " << kleur << endl;
}

ostream& operator<<(ostream& out, const GekleurdVierkant &v) {
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
