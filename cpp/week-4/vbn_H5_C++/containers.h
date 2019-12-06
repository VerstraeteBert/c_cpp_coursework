#include <vector>
#include <iostream>

using namespace std;

template <class T>
ostream& operator<<(ostream& out, const vector<T> & vect){
    out << "["
    if (vect.size() != 0) {
        out << vect[0];
    }
    for (size_t i = 1; i < vect.size(); i++) {
        out << " - " << vect[i];
    }
    out << " ]" << endl;
    return out;
}
