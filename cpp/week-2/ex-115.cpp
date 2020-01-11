#include <iostream>
#include <map>
#include <unordered_set>
#include "./containers.h"

using namespace std;

void search(const string &, vector<map<int, unordered_set<string>>> &);

int main() {
    vector<map<int, unordered_set<string>>> length_string_map(10);

    string word;
    while (cin >> word && word != "STOP") {
        size_t word_length = word.length();

        if (length_string_map.size() < word_length) {
            length_string_map.resize(word_length);
        }

        length_string_map[word_length - 1][word_length].insert(word);
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    string needle = "sinterklaas";
    search(needle, length_string_map);

    return 0;
}

void search (const string & word,
             vector<map<int, unordered_set<string>>> & length_string_map) {
    char first_char = word.front();
    size_t length_word = word.length();

    if (length_string_map.size() < length_word) {
        cout << "Couldn't find words with length " << length_word << endl;
        return;
    }

    for (const string & el : length_string_map[length_word - 1][length_word]) {
        if (el.front() == first_char) {
            cout << el << " ";
        }
    }
    cout << endl;
}
