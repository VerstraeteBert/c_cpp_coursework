#include <vector>
#include <memory>
#include <iostream>

using namespace std;

template<class T>
class Doos {
private:
    vector<T> b;
    Doos * c;
    unique_ptr<string>* d;
    int n;
    void move(Doos<T>&&);
    void copy(const Doos<T>&);

public:
    Doos();
    Doos(const Doos<T>&);
    Doos(Doos<T>&&);
    virtual ~Doos();

    Doos<T>& operator=(const Doos<T>&);
    Doos<T>& operator=(Doos<T>&&);
};

template<class T>
Doos<T>::Doos() : c(nullptr), d(nullptr), n(0) {}

template<class T>
void Doos<T>::move(Doos<T>&& doos) {
    b = move(doos.b);
    c = doos.c;
    n = doos.n;
    d = doos.d;

    doos.n = 0;
    doos.c = nullptr;
    doos.d = nullptr;
}

template<class T>
Doos<T>& Doos<T>::operator=(Doos<T>&& doos) {
    if (this != &doos) {
        delete c;
        delete [] d;
        move(doos);
    }
    return *this;
}

template<class T>
Doos<T>::Doos(Doos<T>&& doos) {
    move(doos);
}

template <class T>
Doos<T>::~Doos() {
    delete c;
    delete [] d;
}

template<class T>
void Doos<T>::copy(const Doos<T>& doos) {
    b = doos.b;

    if (doos.c) {
        c = new Doos<T>(doos.c);
    } else {
        c = nullptr;
    }

    n = doos.n;
    if (n > 0) {
        d = new unique_ptr<string>[n];
        for (int i = 0; i < n; i++) {
            if (doos.d[i]) {
                d[i] = unique_ptr<string>(*doos.d[i]);
            } else {
                doos.d[i] = nullptr;
            }
        }
    } else {
        d = nullptr;
    }
}

template<class T>
Doos<T>::Doos(const Doos<T>& doos) {
    copy(doos);
}

template<class T>
Doos<T>& Doos<T>::operator=(const Doos<T>& doos) {
    if (this == &doos) return *this;
    delete c;
    delete [] d;
    copy(doos);
    return *this;
}

template<class T>
class Schijf {
private:
    Doos<T> * a;
public:
    Schijf();
    Schijf(const Schijf<T>&);
    Schijf(Schijf<T>&&);
    virtual ~Schijf();

    Schijf<T>& operator=(const Schijf<T>&);
    Schijf<T>& operator=(Schijf<T>&&);
};

template<class T>
Schijf<T>::Schijf() : a(nullptr) {}

template<class T>
Schijf<T>::~Schijf() {
    delete a;
}

template<class T>
Schijf<T>::Schijf(const Schijf<T>& schijf) {
    if (schijf.a) {
        a = new Doos<T>(*schijf.a);
    } else {
        a = nullptr;
    }
}

template<class T>
Schijf<T>::Schijf(Schijf<T>&& schijf) : a(schijf.a) {
    schijf.a = nullptr;
}

template<class T>
Schijf<T>& Schijf<T>::operator=(const Schijf<T>& schijf) {
    if (this == &schijf) {
        return *this;
    }
    delete a;
    a = nullptr;
    if (schijf.a != nullptr) {
        a = new Doos<T>(*schijf.a);
    }
    return *this;
}

template<class T>
Schijf<T>& Schijf<T>::operator=(Schijf<T>&& schijf) {
    if (this != &schijf) {
        delete a;
        a = move(schijf.a);
        schijf.a = nullptr;
    }
    return *this;
}

int main () {
    return 0;
}
