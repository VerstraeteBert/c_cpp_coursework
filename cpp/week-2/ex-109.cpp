#include <memory>
#include <iostream>
using namespace std;

void schrijf(const unique_ptr<string> s [], int aantal){
    cout<<endl;
    for(int i=0; i < aantal - 1; i++){
        if (s[i] == NULL) {
            continue;
        }
        cout<<*(s[i])<<" - ";
    }
    if (s[aantal - 1] != NULL) {
        cout << *(s[aantal - 1]);
    }
}

void verwijder(unique_ptr<string> s [], int aantal, int volgnr){
    for(int i = volgnr; i < aantal - 1; i++){
        s[i].swap(s[i+1]);
    }
    s[aantal-1].reset();  //laatste element leeg maken
}

int main(){
    unique_ptr<string> pnamen []=
            {
                make_unique<string>(string("Rein")),
                make_unique<string>(string("Ada")),
                make_unique<string>(string("Eppo")),
                make_unique<string>(string("Pascal")),
                make_unique<string>(string("Ilse"))
             };
    schrijf(pnamen,5);
    verwijder(pnamen,5,1);
    schrijf(pnamen, 5); //alle namen tonen
    return 0;
}
