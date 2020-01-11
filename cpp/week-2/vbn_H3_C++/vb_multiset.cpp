#include <set>  //niet <multiset>!!!
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    //multiset<string> ms;
    unordered_multiset<string> ms;
    ms.insert("kiwi");
    ms.insert("peer");
    ms.insert("appel");
    ms.insert("peer"); 
    ms.insert("banaan");   
    ms.insert("banaan");
    cout << ms.size() << endl;
    cout << ms.count("banaan") << endl;
    //multiset<string>::iterator it;
    unordered_multiset<string>::iterator it;
	it = ms.begin();
    while (it != ms.end()) {
       cout << *it++ << endl;
    }

    it = ms.find("banaan");
    if (it != ms.end()) 
       ms.erase(it); //slechts 1 keer banaan verwijderen
    cout << ms.size() << endl;   
    for (string s : ms) {
       cout << s << endl;
    }
    
    ms.erase("peer"); //alle peren verwijderen
    cout << ms.size() << endl;   
    for (string s : ms) {
       cout << s << endl;
    }
    
    return 0;
}
