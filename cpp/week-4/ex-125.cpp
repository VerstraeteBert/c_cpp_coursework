#include <iostream>
#include <vector>

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
    void print(ostream&) const;
private:
    string kleur;
};

class Vierkant : public Rechthoek {
public:
    Vierkant(int = 1);
    void print(ostream &out) const;
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

int main () {
    Rechthoek r2(4,6);
    GekleurdeRechthoek gr1;
    GekleurdeRechthoek gr3(6,9,"rood");
    Vierkant v2(10);

    vector<unique_ptr<Rechthoek>> v;
    v.push_back(make_unique<Rechthoek>(4,6));
    v.push_back(make_unique<GekleurdeRechthoek>());
    v.push_back(make_unique<GekleurdeRechthoek>(6,9,"rood"));
    v.push_back(make_unique<Vierkant>(10));

    for(size_t i=0 ; i < v.size() ; i++) {
        cout << *v[i];
        cout << " oppervlakte: " << v[i]->oppervlakte() << endl
             << " omtrek: " << v[i]->omtrek() << endl;
    }
    return 0;
}
