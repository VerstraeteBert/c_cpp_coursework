#include <stack>
#include <vector>
#include <iostream>
#include "containers.h"

using namespace std;

const int AANTAL = 5;

int main() {
    stack<string> st_str;
    st_str.push("een");
    st_str.push("twee");
    st_str.push("drie");
    cout << st_str;
    cout << st_str;

    vector<string> arr_v [AANTAL];
    arr_v[1] = { "aap", "noot", "mies" };
    for (int i = 0; i < AANTAL; i++) {
        cout <<  arr_v[i];
    }

    vector<vector<int>> arr_v_2;
    arr_v_2.reserve(AANTAL);
    for (int i = 1; i <= AANTAL; i++) {
        vector<int> v_new;
        v_new.reserve(i);
        for (int j = 0; j < i; j++) {
            v_new.push_back((j + 1) * 10);
        }
        arr_v_2.push_back(v_new);
    }
    cout << arr_v_2 << endl;

    for (int i = arr_v_2.size() - 1; i >= 0; i--) {
        for (int j = arr_v_2[i].size() - 1; j >= 0; j--) {
            cout << arr_v_2[i][j] << " ";
        }
        cout << endl;
    }
}
