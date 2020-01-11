#include <vector>
#include <stack>
#include <map>
#include <set>
#include <iostream>

using namespace std;

void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(
        vector<map<string, stack<set<string>>>>& v,
        size_t idx,
        const string& woord,
        const string& eerste,
        const string& tweede,
        const string& derde) {
    if (idx > (v.size() - 1)) {
        v.resize(idx + 1);
    }
    set<string> new_set = {
            eerste,
            tweede,
            derde
    };
    v[idx][woord].push(move(new_set));
}

bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(
        const vector<map<string, stack<set<string>>>>& vec,
        size_t idx,
        const string& woord,
        const string& el) {
    if (vec.size() - 1 <= idx) return false;

    // of
    // map<string, stack<set<string>>>::const_iterator it = ... ;
    const auto& it = vec[idx].find(woord);
    if (it == vec[idx].end()) return false;

    if (it->second.empty()) return false;

    return it->second.top().count(el) == 1;
}

int main() {
    vector<map<string, stack<set<string>>>> v(5);
    vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v, 1, "noot", "do", "re", "mi");
    vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v, 20, "noot", "do", "re", "mi");
    cout << i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(v, 1, "noot", "mi");
    return 0;
}
