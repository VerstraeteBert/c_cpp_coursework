#include <memory>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Doos {
public:
    Doos();
    Doos(const Doos<T>&);
    Doos(Doos<T>&&);
    ~Doos();
    Doos<T>& operator=(Doos<T>&);
    Doos<T>& operator=(Doos<T>&&);

private:
    vector<T> b;
    Doos<T> * c;
    unique_ptr<string> * d;
    size_t n;
};

// primitieve waardes zeker initialiseren (pointers, int enz) ; anders bevatten die garbage
// b = vector<T>();
template <class T>
Doos<T>::Doos() : n(0), c(nullptr), d(nullptr) {};

template <class T>
Doos<T>::Doos(Doos<T>&& d2) : b(move(d2.b)), c(d2.c), d(d2.d), n(d2.n) {
    d2.c = nullptr;
    d2.d = nullptr;
    d2.n = 0;
};

template <class T>
Doos<T>& Doos<T>::operator=(Doos<T> && d2) {
    if (this == d2) return *this;
    delete c;
    delete[] d;

    b = move(d2.b);
    c = d2.c;
    d = d2.d;
    n = d2.n;

    d2.d = nullptr;
    d2.c = nullptr;
    d2.n = 0;
}

template <class T>
Doos<T>::Doos(const Doos& doos) : Doos() {
    cout << "creatie kopie" << endl;
    b = doos.b;
    if (doos.c != nullptr) {
        c = new Doos(*doos.c);
    }

    n = doos.n;
    if (doos.n != 0 && doos.d != nullptr) {
        d = new unique_ptr<string>[doos.n];

        for (size_t i = 0; i < doos.n; i++) {
            d[i] = make_unique<string>(*(doos.d[i]));
        }
    }
}

template <class T>
Doos<T>::~Doos() {
    // vector moet niet deleted worden / elementen ook niet (geen pointers)
    cout << "verwijdert" << endl;
    delete c;
    // bij new met [] -> delete met [] gebruiken !
    delete[] d;
}

template <class T>
Doos<T>& Doos<T>::operator=(Doos<T>& other) {
    cout << "toekenning" << endl;

    if (&other == this) {
        return *this;
    }

    // eerst bestaande waarden verwijderen
    delete c;
    delete[] d;

    // diepe kopie van other waarden
    b = other.b;
    if (other.c != nullptr) {
        c = new Doos(*other.c);
    }

    n = other.n;
    if (other.n != 0 && other.d != nullptr) {
        d = new unique_ptr<string>[other.n];

        for (size_t i = 0; i < other.n; i++) {
            d[i] = make_unique<string>(*(other.d[i]));
        }
    }

    return *this;
}

template <class T>
class Schijf {
public:
    Schijf();
    Schijf<T>& operator=(const Schijf<T> &);
    ~Schijf();
    Schijf<T>& operator=(Schijf<T>&& s);
    Schijf(Schijf<T>&& s);
private:
    Doos<T> * a;
};

template <class T>
Schijf<T>::Schijf() : a(nullptr) {};

template <class T>
Schijf<T>::Schijf(Schijf<T>&& s) {
    a = s.a;
    s.a = nullptr;
};

template <class T>
Schijf<T>::~Schijf() {
    delete a;
}

template <class T>
Schijf<T>& Schijf<T>::operator=(Schijf<T>&& s) {
    if (this == &s) return *this;
    a = s.a;
    s.a = nullptr;
}

int main() {
    Doos<int> test;
    Doos<int> test2 = Doos<int>(test);

    cout << "declaratie test3" << endl;
    Doos<int> test3;
    cout << "test3 = test2" << endl;
    test3 = test2;
    return 0;
}
