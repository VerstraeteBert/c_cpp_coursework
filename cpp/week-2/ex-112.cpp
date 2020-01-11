#include <set>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

//template <class T>
//ostream& operator<<(ostream& out, const set<T>& set) {
//    for (auto& el : set) {
//        cout << el << endl;
//    }
//    return out;
//}
// of met iterator
template <class T>
ostream& operator<<(ostream& out, const set<T>& cont) {
    out << "printing set:" << endl;
    // of auto it = cont.cbegin();
    typename set<T>::const_iterator it = cont.cbegin();
    while (it != cont.cend()) {
        out << *it << " ";
        it++;
    }
    out << endl;
    return out;
}

// moet een kopie nemen v/d stack -> onmogelijk om te itereren zonder elementen weg te gooien
template <class T>
ostream& operator<<(ostream& out, stack<T> cont) {
    out << "printing stack:" << endl;
    while (!cont.empty()) {
        out << cont.top() << " ";
        cont.pop();
    }
    out << endl;
    return out;
}

//template <class T, class G>
//ostream& operator<<(ostream& out, const map<T,G>& cont) {
//    out << "printing map:" << endl;
//    // pair<T,G>& el : cont
//    for (auto& el : cont) {
//        out << el.first << " -> " << el.second << endl;
//    }
//    out << endl;
//    return out;
//}

// of met iterator
template <class T, class G>
ostream& operator<<(ostream& out, const map<T,G>& cont) {
    out << "printing map:" << endl;
    typename map<T,G>::const_iterator it = cont.cbegin();
    while (it != cont.cend()) {
        out << it->first << " -> " << it->second << endl;
        it++;
    }
    out << endl;
    return out;
}


int main () {
    set<string> test;
    test.insert("hallo");
    test.insert("tweede");
    cout << test;

    stack<int> test_2;
    test_2.push(1);
    test_2.push(2);
    cout << test_2;
    cout << test_2;

    map<string, int> test_3;
    test_3.insert({"key_1", 1});
    test_3.insert({"key_2", 2});
    test_3.insert(pair<string, int>("key_2", 2));
    cout << test_3;
}
