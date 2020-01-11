#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<string> qu;
    qu.push("een"); 
    qu.push("twee");  
    qu.push("drie"); 
    cout << qu.size() << endl;
    while (!qu.empty()) {
       cout << qu.top()<< endl; //geen front() gebruiken!!
       qu.pop();
    }
    cout << qu.size() << endl;
    return 0;
}
