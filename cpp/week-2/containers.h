#include <set>
#include <unordered_set>
#include <stack>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
ostream& operator<<(ostream&, const set<T> &);
template <class T>
ostream& operator<<(ostream&, stack<T>);
template <class T, class G>
ostream& operator<<(ostream&, const map<T, G>&);
template <class T>
ostream& operator<<(ostream&, const vector<T> &);

template <class T>
ostream& operator<<(ostream& out, const unordered_set<T> & s){
    typename set<T>::iterator it = s.begin();
    while (it != s.end()) {
        out << *it++ << " ";
    }
    out << endl;
    return out;
}

template <class T>
ostream& operator<<(ostream& out, const set<T> & s){
    typename set<T>::iterator it = s.begin();
    while (it != s.end()) {
        out << *it++ << " ";
    }
    out << endl;
    return out;
}

template <class T>
ostream& operator<<(ostream& out, stack<T> s){
    while (!s.empty()) {
        out << s.top() << " ";
        s.pop();
    }
    out << endl;
    return out;
}

template <class T, class G>
ostream& operator<<(ostream& out, const map<T, G> & m){
    for (pair<T,G> p : m) {
        out << p.first << "->" <<  p.second << " ";
    }
    out << endl;
    return out;
}

template <class T>
ostream& operator<<(ostream& out, const vector<T> & vectors) {
    cout << endl;
    for (T x : vectors) {
        cout << x << " ";
    }
    return out;
}
