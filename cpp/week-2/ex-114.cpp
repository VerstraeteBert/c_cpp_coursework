#include <iostream>
#include <map>
#include <unordered_set>
#include "containers.h"

int main() {
    map<char, int> char_occ;
    unordered_set<string> read;
    cout << "Geef woorden in ajb:" << endl;
    string word;
    while (cin >> word && word != "STOP") {
        // bij insertie geeft insert een paar terug;
        // als second = true -> nieuw element
        // second = false -> bestond al
        if (read.insert(word).second) {
            char_occ[word.front()]++;
        }
    }
    cout << char_occ;
}
