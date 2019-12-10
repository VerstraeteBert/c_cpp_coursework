#include <set>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

template <class T>
ostream& operator<<(ostream& out, const set<T> & s){
    typename set<T>::const_iterator it = s.cbegin();
    while (it != s.cend()) {
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
ostream& operator<<(ostream& out, map<T, G> m){
    typename map<T,G>::const_iterator it = m.cbegin();
    while (it != m.cend()) {
        out << p.first << "->" << p.second << " ";
        it++;
    }
    out << endl;
    return out;
}

int main () {
    set<int> set_test;
    set_test.insert(1);
    set_test.insert(2);
    cout << set_test;

    stack<int> stack_test;
    stack_test.push(2);
    stack_test.push(1);
    cout << stack_test;

    map<int, string> map_test;
    map_test[0] = "hanlo";
    map_test[56789] = "bert";
    cout << map_test;
}
