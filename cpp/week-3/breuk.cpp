#include <stdexcept>
#include <iostream>

using namespace std;

int calc_ggd(int a, int b);
int calc_kgv(int a, int b);

class Breuk {
    private:
        // private members, why?
        // Don't want users to set to invalid values (needs to be normalized and noemer not 0)
        int teller, noemer;
        void normaliseer();

    public:
        // constructor
        Breuk(int t = 0, int n = 1) {
            this->teller = t;
            this->noemer = n;
            normaliseer();
        };

        // operators
        Breuk operator+(const Breuk &) const;
        Breuk operator+(int) const;
        Breuk& operator+=(const Breuk &);
        Breuk& operator++();
        Breuk operator++(int);
        Breuk& operator-=(const Breuk &);
        Breuk& operator--();
        Breuk operator-() const;
        Breuk operator-(const Breuk &) const;
        bool operator<(const Breuk &) const;
        bool operator==(const Breuk &) const;
        bool operator!=(const Breuk &) const;

        // goeie moaten
        friend Breuk operator+(int, const Breuk &);
        friend istream& operator>>(istream&, Breuk&);
        friend ostream& operator<<(ostream&, const Breuk&);
        friend bool is_stambreuk(const Breuk &);

        // getters
        int getTeller() const;
        int getNoemer() const;
};

bool is_stambreuk(const Breuk& breuk) {
    return breuk.teller == 1;
}

int Breuk::getTeller() const {
    return teller;
}

int Breuk::getNoemer() const {
    return noemer;
}

Breuk Breuk::operator+(const Breuk & b) const {
    return Breuk(b.noemer * teller + noemer * b.teller, noemer * b.noemer);
}

Breuk Breuk::operator+(int add) const {
    Breuk c(*this);
    add *= c.noemer;
    c.teller += add;
    return c;
}

Breuk operator+(int add, const Breuk & breuk) {
    return breuk + add;
}

Breuk& Breuk::operator+=(const Breuk & b) {
    teller = b.noemer * teller + noemer * (b.teller);
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

Breuk Breuk::operator-(const Breuk & b) const {
    return Breuk(b.noemer * teller - noemer * b.teller, noemer * b.noemer);
}

Breuk& Breuk::operator-=(const Breuk & b) {
    operator+=(-b);
    return *this;
}

Breuk& Breuk::operator--() {
    teller -= noemer;
    normaliseer();
    return *this;
}

Breuk Breuk::operator-() const {
    return Breuk(-teller, noemer);
}

// casten naar floats !!
bool Breuk::operator<(const Breuk & comp) const {
    return  (float) teller / (float) noemer < (float) comp.teller / (float) comp.noemer;
}

bool Breuk::operator==(const Breuk & comp) const {
    return teller == comp.teller && noemer == comp.noemer;
}

bool Breuk::operator!=(const Breuk & comp) const {
    return !operator==(comp);
}

istream& operator>>(istream& is, Breuk& breuk) {
    string lijn;
    getline(is, lijn);
    int teller, noemer;
    size_t p = lijn.find("/");
    if (p != string::npos) {
        teller = atoi(lijn.substr(0, p).c_str());
        noemer = atoi(lijn.substr(p+1).c_str());
        breuk = Breuk(teller, noemer);
    } else {
        int getal = atoi(lijn.c_str());
        breuk = Breuk(getal);
    }
    return is;
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

ostream& operator<<(ostream & out, const Breuk & breuk) {
    out << breuk.teller;
    if (breuk.noemer != 1) cout << "/" << breuk.noemer;
    return out;
};

int calc_kgv(int a, int b) {
    return (a * b) / calc_ggd(a, b);
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
