#include <iostream>
#include <set>
#include "./containers.h"

using namespace std;

template <class T>
class Container {
private:
    set<T> elementen;
    string naam;

public:
    Container() { };
    Container(const T[], size_t, const string&);

    Container<T> operator*(const Container<T>&) const;
    Container<T>& operator+=(T);

    template <typename U>
    friend ostream& operator<<(ostream&, const Container<U>&);
};

template<class T>
Container<T>::Container(const T arr [], size_t n, const string& naam) : naam(naam) {
    for (size_t i = 0; i < n; i++) {
        elementen.insert(arr[i]);
    }
}

template<class T>
Container<T> Container<T>::operator*(const Container<T>& c) const {
    Container<T> res;
    res.naam = "doorsnede " + naam + " en " + c.naam;
    auto it = elementen.cbegin();
    while (it != elementen.cend()) {
        if (c.elementen.count(*it) != 0) {
            res.elementen.insert(*it);
        }
        it++;
    }
    return res;
}

template<class T>
Container<T>& Container<T>::operator+=(T el) {
    elementen.insert(el);
    return *this;
}

template<class T>
ostream& operator<<(ostream& out, const Container<T>& c) {
    out << "*** " << c.naam << " ***" << endl;
    out << c.elementen << endl;
    return out;
}

int main(){
    char v[]={'a','b','c','d', 'e', 'e'};
    Container<char> verz1(v,6,"groot");
    Container<char> verz2(v,2,"klein");
    verz2 += 'e';
    verz2 += 'z';
    Container<char> doorsnede = verz1*verz2;//Maak de doorsnede
    cout<<verz1;
    cout<<verz2;
    cout<<doorsnede;
    return 0;
}
