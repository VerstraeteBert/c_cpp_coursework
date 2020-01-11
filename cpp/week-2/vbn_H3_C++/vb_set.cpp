#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    set<string> s;
    //unordered_set<string> s;
    s.insert("kiwi");
    s.insert("peer");  
    s.insert("appel");
    s.insert("banaan"); 
    
    pair<set<string>::iterator, bool> ret; 
    //pair<unordered_set<string>::iterator, bool> ret;
	ret = s.insert("banaan");
    if (ret.second) cout << "banaan toegevoegd\n";
    else cout << "banaan niet toegevoegd\n";
    cout << *ret.first << endl;
	cout << s.size() << endl;
    
    set<string>::iterator it;
	//unordered_set<string>::iterator it;
	it = s.begin();
    while (it != s.end()) {
       cout << *it++ << endl;
    }
    
    string zoekwoord; 
    cout << "Wat moet ik zoeken? ";
    cin >> zoekwoord;
    cout << zoekwoord 
         << (s.count(zoekwoord) == 1 ? "" : " niet") 
         << " gevonden" << endl;
    
    s.erase("banaan");
    cout << s.size() << endl; 
    for (string woord : s)
       cout << woord << endl;

    it = s.find("kiwi");
    if (it != s.end())
       s.erase(it);
    cout << s.size() << endl;   
    for (string woord : s)
       cout << woord << endl;
     
    return 0;
}
