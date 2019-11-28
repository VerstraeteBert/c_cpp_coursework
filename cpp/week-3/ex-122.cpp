#include <iostream>
#include <set>
#include "containers.h"

using namespace std;

template <class T>
class Container {
private:
    set<T> _elementen;
    string _naam;

public:
    // constructors
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
Container<T>::Container(const T arr [], size_t size, const string & naam) {
    _naam = naam;
    _elementen = set<T>();
    for (size_t i = 0; i < size; i++) {
        _elementen.insert(arr[i]);
    }
}

template <class T>
Container<T>::Container(const set<T>& new_set, const string& new_naam) {
    _elementen = new_set;
    _naam = new_naam;
};

template<class T>
Container<T>& Container<T>::operator+=(const T& val) {
    _elementen.insert(val);
    return *this;
}

template <class T>
Container<T> Container<T>::operator*(const Container<T> & comp) const {
    set<T> new_set = set<T>();

    for (const T& elem : comp._elementen) {
        if (_elementen.find(elem) != _elementen.end()) {
            new_set.insert(elem);
        }
    }

    return Container<T>(new_set, "doorsnede " + _naam + " en " + comp._naam);
}

template<class T>
ostream& operator<<(ostream& out, const Container<T>& container) {
    out << "*** set " << container._naam << " ***" << endl;
    out <<  " { " << container._elementen << " } " << endl;
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
