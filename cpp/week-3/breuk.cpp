#include <math.h>
#include <stdexcept>
#include <iostream>
#include <string.h>

using namespace std;

int calc_ggd(int a, int b);

class Breuk {
private:
    int teller;
    int noemer;
    void normaliseer();
public:
    Breuk();
    Breuk(int, int);
    Breuk(int);
    Breuk(const Breuk&);

    // operators
    Breuk operator+(const Breuk&) const;
    Breuk& operator+=(const Breuk&);
    Breuk operator+(int) const;
    Breuk& operator++();
    Breuk operator++(int);

    bool operator<(const Breuk&) const;
    bool operator==(const Breuk&) const;
    bool operator!=(const Breuk&) const;

    Breuk operator-() const;
    Breuk operator-(const Breuk&) const;
    Breuk& operator-=(const Breuk&);

    friend bool is_stambreuk(const Breuk&);

    friend ostream& operator<<(ostream&, const Breuk&);
    friend istream& operator>>(istream&, Breuk&);
};

Breuk::Breuk(int teller, int noemer) : teller(teller), noemer(noemer) {
    if (this->noemer == 0) throw domain_error("noemer kan niet 0 zijn");
    normaliseer();
}

Breuk::Breuk() : Breuk(1, 1) {};

Breuk::Breuk(int teller) : Breuk(teller, 1) {};

Breuk::Breuk(const Breuk& br) : Breuk(br.teller, br.noemer) {};

Breuk Breuk::operator+(const Breuk &b) const {
    return Breuk(b.noemer * teller + noemer * b.teller, noemer * b.noemer);
}

Breuk& Breuk::operator+=(const Breuk& b) {
    teller = b.noemer * teller + noemer * b.teller;
    noemer = noemer * b.noemer;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator++() {
    teller += noemer;
    normaliseer();
    return *this;
}

Breuk Breuk::operator++(int) {
    Breuk temp(*this);
    teller += noemer;
    normaliseer();
    return temp;
}

Breuk Breuk::operator+(int x) const {
    Breuk c(*this);
    c.teller += x * noemer;
    return c;
}

Breuk operator+(int x, const Breuk& b) {
    return b + x;
}

Breuk Breuk::operator-() const {
    return Breuk(-teller, noemer);
}

Breuk Breuk::operator-(const Breuk& b) const {
    return Breuk(b.noemer * teller - noemer * b.teller, noemer * b.noemer);
}

Breuk& Breuk::operator-=(const Breuk& b) {
    teller = b.noemer * teller - noemer * b.teller;
    noemer = noemer * b.noemer;
    normaliseer();
    return *this;
}

bool Breuk::operator<(const Breuk& b) const {
    return teller * b.noemer < noemer * b.teller;
}

bool Breuk::operator==(const Breuk& b) const {
    return (teller == b.teller) && (noemer == b.noemer);
}
bool Breuk::operator!=(const Breuk& b) const {
    return !(b == *this);
}

ostream& operator<<(ostream & out, const Breuk& b) {
    out << b.teller;
    if (b.noemer != 1) out << "/" << b.noemer;
    return out;
}

istream& operator>>(istream& in, Breuk& b) {
    string lijn;
    getline(in, lijn);
    size_t p = lijn.find("/");
    if (p != string::npos) {
        int teller = atoi(lijn.substr(0,p).c_str());
        int noemer = atoi(lijn.substr(p + 1).c_str());
        b = Breuk(teller, noemer);
    } else {
        int getal = atoi(lijn.c_str());
        b = Breuk(getal);
    }
    return in;
}

void Breuk::normaliseer() {
    if (noemer < 0) {
        noemer = abs(noemer);
        teller = teller * -1;
    }

    int ggd = calc_ggd(teller, noemer);
    teller /= ggd;
    noemer /= ggd;
}

bool is_stambreuk(const Breuk& b)  {
    return b.noemer == 1;
}

int calc_ggd(int a, int b) {
    if(a < 0 || b < 0){
        return calc_ggd(abs(a),abs(b));
    }
    if(b == 0){
        return a;
    }
    return calc_ggd(b,a%b);
}
