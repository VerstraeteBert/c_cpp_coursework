#include <fstream>
#include <iostream>
using namespace std;

int aantalpositief_v1(const string &s) {
    ifstream inv(s);
    if (!inv.is_open())
        return -1;
    else {
        int aantal = 0;
        int getal;
        inv >> getal;
        //fail niet vervangen door eof!!
        //ook niet als je weet dat het bestand
        //geen fouten bevat!!
        while (!inv.fail()) { 
            if (getal > 0) 
               aantal++;
            inv >> getal;
        }
        if (!inv.eof()) 
            aantal =  -1;
        return aantal;   
    }
}

int aantalpositief_v2(const string &s) {
    ifstream inv(s);
    if (!inv.is_open())
        return -1;
    else {
        int aantal = 0;
        int getal;
        while (inv >> getal) {
            if (getal > 0) 
               aantal++;
        }
        if (!inv.eof()) 
            aantal =  -1;
        return aantal;   
    }
}
      
int main(int argc, char **argv) {
    if (argc == 1)
       cout << "geen extra strings op commandolijn";
    for (int i = 1 ; i < argc ; i++) {
       int aantal = aantalpositief_v1(argv[i]);
       if (aantal != -1)
          cout << "bestand " << argv[i] 
               << " bevat " << aantal   
               << " positieve getallen" << endl;
       else
          cout << "bestand " << argv[i] 
               << " kan niet geopend worden of bevat fouten"  
               << endl;
    }
    for (int i = 1 ; i < argc ; i++) {
       int aantal = aantalpositief_v2(argv[i]);
       if (aantal != -1)
          cout << "bestand " << argv[i] 
               << " bevat " << aantal  
               << " positieve getallen" << endl;
       else
          cout << "bestand " << argv[i] 
               << " kan niet geopend worden of bevat fouten"  
               << endl;
    }
    return 0;
}
