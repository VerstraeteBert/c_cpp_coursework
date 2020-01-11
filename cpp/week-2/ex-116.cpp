#include <vector>
#include <memory>
#include <iostream>
#include "./containers.h"

using namespace std;

template<class T>
void dupliceer(vector<unique_ptr<T>>& v, int aant) {
    int orig_size = v.size();
    v.resize(aant * orig_size);
    for (int i = orig_size - 1; i >= 0; i--) {
        v[i * aant] = move(v[i]);
    }

    for(int i = 0; i < orig_size; i++) {
        int curr_ptr = i * aant;
        for (int j = 1; j < aant; j++) {
            v[j + curr_ptr] = make_unique<T>(*(v[curr_ptr]));
        }
    }
}

int main() {
    unique_ptr<string> namen[] = {make_unique<string>("Rein"),
                                  make_unique<string>("Ada"), make_unique<string>("Eppo"),
                                  make_unique<string>("Pascal"), make_unique<string>("Ilse")};
    vector<unique_ptr<string>> namenvector;
    namenvector.reserve(5);
    for (int i = 0; i < 5; i++) {
        namenvector.push_back(move(namen[i]));
    }

    dupliceer(namenvector, 2);
    //print de inhoud van namenvector
    for (auto& ptr : namenvector) {
        cout << *ptr << " ";
    }
    cout << endl;
    //output moet zijn: Rein Rein Rein Ada Ada Ada Eppo Eppo Eppo Pascal Pascal Pascal Ilse Ilse Ilse
}
