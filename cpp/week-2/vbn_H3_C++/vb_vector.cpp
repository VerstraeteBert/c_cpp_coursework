#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v1;
    cout << "v1:" << endl;
    cout << "size: " << v1.size() << endl
         << "capaciteit: " << v1.capacity() << endl;
    //v1[0] = 4;  //Niet doen!! => crash
    //v1.at(0) = 6; //Niet doen!! => exception
    v1.push_back(7);
    cout << "size: " << v1.size() << endl
         << "capaciteit: " << v1.capacity() << endl;
    v1[0] = 5;
    v1.push_back(6);
    v1.back() *= 2;
	cout << "size: " << v1.size() << endl
         << "capaciteit: " << v1.capacity() << endl;
    for (int i = 0 ; i < v1.size() ; i++)
       cout << v1[i] << "  ";
    cout << endl;
           
    vector<double> v2(4, 99.99);
    cout << "\nv2:" << endl;
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    for (int i : v2)
       cout << i << "  "; 
    cout << endl;
    v2.push_back(3.5);
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl; 
    v2.push_back(6.2);
    cout << v2.at(v2.size()-1)++ << endl;
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    for (int i = 0 ; i < v2.size() ; i++)
       cout << v2.at(i) << "  "; 
    cout << endl;  
    v2.clear();
    cout << "na clear:\nsize: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    for (int i = 0 ; i < v2.capacity() ; i++)
       cout << v2[i] << "  ";  //exception bij v2.at(i)
    cout << endl;
    v2.reserve(16);
    cout << "size: " << v2.size() << endl
         << "capaciteit: " << v2.capacity() << endl;
    
    vector<char> v3;
    v3.reserve(5);
    cout << "\nv3:" << endl;
    cout << "size: " << v3.size() << endl
         << "capaciteit: " << v3.capacity() << endl;
    v3[0] = 'a';
    cout << "size: " << v3.size() << endl
         << "capaciteit: " << v3.capacity() << endl;
    v3.push_back('b');
    cout << "size: " << v3.size() << endl
         << "capaciteit: " << v3.capacity() << endl;
    for (char i : v3)
       cout << i << endl; 

    vector<string> tv[3];
    tv[0].push_back("een");
    tv[2].push_back("twee");
    tv[0].push_back("drie");
    for (int i = 0 ; i < 3 ; i++) {
        cout << endl << "vector " << i << ": ";
        for (int j = 0 ;  j < tv[i].size() ; j++)
           cout << tv[i][j] << " ";
    }
    return 0;
}
