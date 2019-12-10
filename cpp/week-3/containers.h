#include <set>
#include <iostream>

using namespace std;

template <class T>
ostream& operator<<(ostream&, const set<T> &);

template <class T>
ostream& operator<<(ostream& out, const set<T> & s){
    typename set<T>::const_iterator it = s.cbegin();
    if (it != s.end()) {
        out << *it++;
    }
    while (it != s.cend()) {
        out << " , ";
        out << *it++;
    }
    return out;
}
