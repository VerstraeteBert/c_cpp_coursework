#include <iostream>
#include <list>
using namespace std;

struct punt {
   int x, y;
};

int main() {
   punt p1 = {1,10}, p2 = {2,20},
        p3 = {3,30}, p4 = {4,40};
   
   list<punt> l;
   l.push_back(p1);
   l.push_front(p2);
   
   list<punt>::iterator it = l.begin();
   while (it != l.end()) {
         cout << it->x << " " 
              << (*it).y << endl;
         it++;
   }
   
   it = l.begin();
   it++;
   it = l.insert(it,p3);
   //is bovenstaande gelijk aan: l.insert(it,p3);
   l.insert(it,p4);
   
   cout << "\nVolledige lijst:\n";
   for (punt p : l )
      cout << p.x << " " << p.y << endl;
   
   cout << "\nLijst van achter naar voor:\n";
   it = l.end(); 
   while (it != l.begin()) {
      it--;
	  cout << it->x << " " << (*it).y << endl;
   }

   return 0;
}
