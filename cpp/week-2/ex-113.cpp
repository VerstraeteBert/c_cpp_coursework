#include <stack>
#include <vector>
#include <iostream>
#include "containers.h"

using namespace std;

const int AANTAL = 5;

int main() {
    stack<string> st;
    st.push("een");
    st.push("twee");
    st.push("drie");
    cout << st;
    cout << st;

    vector<string> v_arr [AANTAL];
    v_arr[2].push_back("aap");
    v_arr[2].push_back("noot");
    v_arr[2].push_back("mies");
    for (int i = 0; i < AANTAL; i++) {
        cout << v_arr[i];
    }
    cout << endl;

    vector<vector<int>> arr_v_2(AANTAL);
    for (int i = 0; i < AANTAL; i++) {
        arr_v_2[i].reserve(i);
        for (int j = 0; j < i; j++) {
            arr_v_2[i].push_back(10 + 10 * j);
        }
    }

    for (int i = arr_v_2.size() - 1; i >= 0; i--) {
        for (int j = arr_v_2[i].size() - 1; j >= 0; j--) {
            cout << arr_v_2[i][j] << " ";
        }
        cout << endl;
    }
}
