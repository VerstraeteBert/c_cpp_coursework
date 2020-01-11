#include <iostream>
#include "./containers.h"
#include <unordered_set>
#include <map>

int main() {
    map<char, unordered_set<string>> word_map;
    string curr_word;
    cin >> curr_word;
    while (curr_word != "STOP") {
        // set ophalen en woord inserten
        word_map[curr_word[0]].insert(curr_word);
        cin >> curr_word;
    }
    char to_print;
    cin >> to_print;
    // count == 1 -> aanwezig in set
    if (word_map.count(to_print) == 1) {
        cout <<  word_map[to_print].size() << " Elementen die starten met het karakter " << to_print << endl;
    } else {
        cout << "niet gevonden" << endl;
    }
}
