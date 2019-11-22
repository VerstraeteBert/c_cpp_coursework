#include "./containers.h"
#include <stdlib.h>
#include <time.h>
#include <set>
#include <iostream>

using namespace std;

void delet_3nth(set<int> &);

int main() {
    srand(time(NULL));
    int n = ((rand() % 10) + 20);
    int ceil = 2 * n;
    set<int> nums;
    for (int i = 0; i < n; i++) {
        nums.insert((rand() % ceil));
    }
    cout << nums;
    delet_3nth(nums);
    cout << nums;
    return 0;
}

void delet_3nth(set<int> & nums) {
    set<int>::iterator it = nums.begin();
    int n = 0;
    while (it != nums.end()) {
        if (n % 3 == 0) {
            it = nums.erase(it);
        } else {
            it++;
        }
        n++;
    }
}
