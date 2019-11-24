#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <unordered_map>
#include "containers.h"

using namespace std;

int main() {
    ifstream line_num_file("../../fixtures/regelnummers.txt");
    if (!line_num_file.is_open()) {
        cout << "Failed to open line nums file";
        return 1;
    }

    set<int> sorted_line_nums;
    vector<int> print_order_vect;
    unordered_map<int, string> line_num_content_map;

    int k;
    line_num_file >> k;
    while (!line_num_file.fail()) {
        sorted_line_nums.insert(k);
        print_order_vect.push_back(k);
        line_num_file >> k;
    }
    line_num_file.close();

    ifstream bible("../../fixtures/nbible.txt");
    if (!bible.is_open()) {
        cout << "Failed to open bible file";
        return 1;
    }

    set<int>::iterator line_nums_it = sorted_line_nums.begin();
    string line_content;
    int curr_pos = 0;

    while (line_nums_it != sorted_line_nums.end()) {
        int next_line_idx = *line_nums_it;
        int next_line_diff = next_line_idx - curr_pos;

        while (next_line_diff != 0) {
            curr_pos++;
            getline(bible, line_content);
            next_line_diff--;
        }

        line_num_content_map.insert({next_line_idx, line_content});
        line_nums_it++;
    }
    bible.close();

    for (int line_idx : print_order_vect) {
        cout << line_num_content_map[line_idx] << endl;
    }

    return 0;
}
