#include <map>  
#include <iostream>
using namespace std;

int main() {
    map<string, int> lft;
    lft["jan"] = 10;
    lft["an"] = 12;
    lft["jan"] = 15;   
    lft.insert(pair<string,int>("piet",11));
    lft.insert(pair<string,int>("piet",18));   
    cout << lft.size() << endl;
    cout << lft["an"] << endl;
    cout << lft["ann"] << endl;
    cout << lft.size() << endl;

    map<string, int>::iterator it = lft.begin();
    while (it != lft.end()) {
       cout << it->first << "->"
            << it->second << endl;
       it++;
    }
    
    it = lft.find("ann");
    if (it != lft.end())
       lft.erase(it);
    cout << lft.size() << endl;  
	for (pair<string,int> p : lft) 
       cout << p.first << "->"
            << p.second << endl;
    
    lft.erase("piet");
    cout << lft.size() << endl;  
    it = lft.begin();
    while (it != lft.end()) {
       cout << (*it).first << "->"
            << (*it).second << endl;
       it++;
    }
    
    return 0;
}
