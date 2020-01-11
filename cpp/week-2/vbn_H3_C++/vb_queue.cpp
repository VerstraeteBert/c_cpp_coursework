#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<char> qu;
    cout << qu.size() << endl;
    qu.push('a'); 
    qu.push('b');  
    qu.push('c'); 
    cout << qu.size() << endl;
    while (!qu.empty()) {
       cout << qu.front()<< endl;
       qu.pop();
    }
    cout << qu.size() << endl;
    return 0;
}
