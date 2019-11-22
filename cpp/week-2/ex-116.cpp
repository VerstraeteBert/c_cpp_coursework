#include <vector>
#include <memory>
#include <iostream>
#include "./containers.h"

using namespace std;

template <class T>
void duplicate(vector<unique_ptr<T>> &, size_t);

int main() {
    unique_ptr<string> namen[] = {make_unique<string>("Pol"),
                                  make_unique<string>("Regis"), make_unique<string>("Kenny"),
                                  make_unique<string>("Potter"), make_unique<string>("Harry")};
    vector<unique_ptr<string>> namenvector;
    for (int i = 0; i < 5; i++) {
        namenvector.push_back(move(namen[i]));
    }
    duplicate(namenvector,3);
//     print de inhoud van namenvector
    for (size_t i = 0; i < namenvector.size(); i++) {
        cout << *(namenvector[i]) << " ";
    }
//    output moet zijn: Rein Rein Rein Ada Ada Ada Eppo Eppo Eppo Pascal Pascal Pascal Ilse Ilse Ilse
}

template <class T>
void duplicate(vector<unique_ptr<T>> & v, size_t n) {
    size_t orig_size = v.size();
    v.resize(orig_size * n);
    for (int i = orig_size - 1; i >= 0; i--) {
        v[i * n] = move(v[i]);
    }

    for(size_t i = 0; i < orig_size; i++) {
        size_t curr_ptr = i * n;
        for (size_t j = 1; j < n; j++) {
            v[j + curr_ptr] = make_unique<T>(*(v[curr_ptr]));
        }
    }
}
