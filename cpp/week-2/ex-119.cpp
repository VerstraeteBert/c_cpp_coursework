#include <stdlib.h>
#include <time.h>
#include <set>
#include <iostream>
#include "containers.h"

using namespace std;

const int UPPER = 30;
const int LOWER = 20;

template<class T>
void verwijder(set<T>& s) {
    // of auto it = nums.begin();
    typename set<T>::iterator it = s.begin();
    int n = 0;
    while (it != s.end()) {
        if (n % 3 == 0) {
            it = s.erase(it);
        } else {
            it++;
        }
        n++;
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % (LOWER + 1) + (UPPER - LOWER);
    set<int> sorted_ints;
    for(int i = 0; i < n; i++) {
        sorted_ints.insert(rand() % (2 * n));
    }
    cout << sorted_ints;
    verwijder(sorted_ints);
    cout << sorted_ints;
}
