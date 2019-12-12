#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "containers.h"

using namespace std;

void lees(const string &bestandsnaam, map<char,set<string> > &m){
    // hier geen auto -> wat is woord??
    string woord;
    ifstream inv(bestandsnaam);
    inv >> woord;
    while(!inv.fail()){
        cout<<woord<<endl;
        m[woord[0]].insert(woord);
        inv>>woord;
    }
}

string langstewoord(char letter, const map<char,set<string>> &m){
    string langste;
    auto it_find = m.find(letter);
    if(it_find != m.end()){
        auto it = it_find->second.cbegin();
        while (it != it_find->second.end()){
            if (it->size() > langste.size()){
                langste = *it;
            }
            it++;
        }
    }
    return langste;
}
int main(){
    string naam = "xp";
    map<char, set<string>> m;
    cout<<"Bestandsnaam: ";
    cin >> naam;
    lees(naam, m);
    char letter = 's';
    cout<<"Het langste woord met de letter "<<letter<<" is: ";
    cout<<langstewoord(letter,m);
    return 0;
}