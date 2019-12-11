#include <iostream>
#include <set>
#include "containers.h"

using namespace std;

template <class T>
class Container {
private:
    set<T> elementen;
    string naam;

public:
    // constructors
    Container(){};
    Container(const T [], size_t, const string&);
    Container(const set<T>&, const string&);

    // operators
    Container<T>& operator+=(const T&);
    Container<T> operator*(const Container<T>&) const;

    // extraverte klasse
    template <class U>
    friend ostream& operator<<(ostream&, const Container<U>&);
};

template <class T>
Container<T>::Container(const T arr [], size_t size, const string & _naam) : naam(_naam) {
    for (size_t i = 0; i < size; i++) {
        elementen.insert(arr[i]);
    }
}

template <class T>
Container<T>::Container(const set<T>& new_set, const string& new_naam) {
    elementen = new_set;
    naam = new_naam;
};

template<class T>
Container<T>& Container<T>::operator+=(const T& val) {
    elementen.insert(val);
    return *this;
}

template <class T>
Container<T> Container<T>::operator*(const Container<T> & comp) const {
    Container<T> vv;
    vv.naam = "doorsnede " + naam + " en " + comp.naam;
    for (const T& elem : comp.elementen) {
        if (elementen.find(elem) != elementen.end()) {
            vv.insert(elem);
        }
    }
    return vv;
}

template<class T>
ostream& operator<<(ostream& out, const Container<T>& container) {
    out << "*** set " << container.naam << " ***" << endl;
    out <<  " { " << container.elementen << " } " << endl;
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
