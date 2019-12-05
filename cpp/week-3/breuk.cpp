#include <stdexcept>
#include <iostream>

using namespace std;

int calc_ggd(int a, int b);
int calc_kgv(int a, int b);

class Breuk {
    private:
        // private members, why?
        // Don't want users to set to invalid values (needs to be normalized and noemer not 0)
        int _teller, _noemer;
        void normaliseer();

    public:
        // constructor
        Breuk(int teller, int noemer = 1) {
            if (noemer == 0) {
                throw std::invalid_argument("noemer kan niet 0 zijn");
            }
            _teller = teller;
            _noemer = noemer;
            normaliseer();
        };
        Breuk() {
            _teller = 0;
            _noemer = 0; // feeling invalid, might crash your program soon :)
        }

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
    return breuk._teller == 1;
}

int Breuk::getTeller() const {
    return _teller;
}

int Breuk::getNoemer() const {
    return _noemer;
}

Breuk Breuk::operator+(const Breuk & b) const {
    int kgv = calc_kgv(_noemer, b._noemer);
    return Breuk(_teller * (kgv / _noemer) + b._teller * (kgv / b._noemer), kgv);
}

Breuk Breuk::operator+(int add) const {
    return Breuk(_teller + (add * _noemer), _noemer);
}

Breuk operator+(int add, const Breuk & breuk) {
    return breuk + add;
}

Breuk& Breuk::operator+=(const Breuk & b) {
    int kgv = calc_kgv(_noemer, b._noemer);
    _teller = _teller * (kgv / _noemer) + b._teller * (kgv / b._noemer);
    _noemer = kgv;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator++() {
    _teller += _noemer;
    normaliseer();
    return *this;
}

Breuk Breuk::operator++(int) {
    Breuk temp(*this);
    ++(*this);
    return temp;
}

Breuk Breuk::operator-(const Breuk & b) const {
    int kgv = calc_kgv(_noemer, b._noemer);
    return Breuk(_teller * (kgv / _noemer) - b._teller * (kgv / b._noemer), kgv);
}

Breuk& Breuk::operator-=(const Breuk & b) {
    int kgv = calc_kgv(_noemer, b._noemer);
    _teller = _teller * (kgv / _noemer) - b._teller * (kgv / b._noemer);
    _noemer = kgv;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator--() {
    _teller -= _noemer;
    normaliseer();
    return *this;
}

Breuk Breuk::operator-() const {
    return Breuk(-_teller, _noemer);
}

// casten naar floats !!
bool Breuk::operator<(const Breuk & comp) const {
    return  (float) _teller / (float) _noemer < (float) comp._teller / (float) comp._noemer;
}

bool Breuk::operator==(const Breuk & comp) const {
    return _teller == comp._teller && _noemer == comp._noemer;
}

bool Breuk::operator!=(const Breuk & comp) const {
    return !(*this == comp);
}

istream& operator>>(istream& is, Breuk& breuk) {
    int read = scanf("%d/%d", &(breuk._teller), &(breuk._noemer));
    if (read == 1) {
        breuk._noemer = 1;
    }
    breuk.normaliseer();
    return is;
}

void Breuk::normaliseer() {
    if (_noemer < 0) {
        _noemer = abs(_noemer);
        _teller = _teller * -1;
    }

    int ggd = calc_ggd(_teller, _noemer);
    _teller /= ggd;
    _noemer /= ggd;
}

ostream& operator<<(ostream & out, const Breuk & breuk) {
    out << breuk._teller << "/" << breuk._noemer;
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
