#include <set>

using namespace std;

template<class T>
ostream& operator<<(ostream& out, const set<T>& s) {
    //typename set<T>::const_iterator it = s.cbegin();
    auto it = s.cbegin();
    out << " { ";
    if (it != s.cend()) {
        out << *it++;
        while (it != s.cend()) {
            out << " , " << *it++;
        }
    }
    out << " } ";
    return out;
}
