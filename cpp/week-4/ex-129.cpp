#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Persoon{
public:
    string voornaam;
    string naam;
    int leeftijd;
    Persoon(const string & v, const string & n, int l):voornaam(v),naam(n),leeftijd(l){}
};

ostream& operator<<(ostream & out, const Persoon & p){
    out<<p.naam <<" "<<p.voornaam<<" ("<<p.leeftijd<<")";
    return out;
}

class Groep : public vector<Persoon>{
public:
    // Hier komt de declaratie van de lidfunctie 'geef_extremum',
    // die een Persoon teruggeeft.
    // Deze lidfunctie krijgt als parameter een functie mee die twee
    // objecten van de klasse Persoon vergelijkt.
    Persoon geef_extremum(function <bool (const Persoon&, const Persoon&)> cmp) const;
};

Persoon Groep::geef_extremum(function<bool(const Persoon &, const Persoon &)> comparator) const {
    size_t extr  = 0;
    for (size_t i = 1; i < this->size(); i++) {
        if (!comparator(*this(ext), (*this)[i])) extr = (*this)[i];
    }
    return (*this)[extr];
}

int main(){
    Groep gr;
    gr.push_back(Persoon("Ann","Nelissen",12));
    gr.push_back(Persoon("Bert","Mertens",22));
    gr.push_back(Persoon("Celle","Lauwers",55));

    cout<<"Eerste qua naam:     " << gr.geef_extremum([](const Persoon& p1, const Persoon& p2) {
        return p1.naam < p2.naam;
    }) << endl;
    cout<<"Eerste qua voornaam: " << gr.geef_extremum([](const Persoon& p1, const Persoon& p2) {
        return p1.voornaam < p2.voornaam;
    }) << endl;
    cout<<"Jongste:             " << gr.geef_extremum([](const Persoon& p1, const Persoon& p2) {
        return p1.leeftijd < p2.leeftijd;
    }) << endl;
    cout<<"Oudste:              " << gr.geef_extremum([](const Persoon& p1, const Persoon& p2) {
        return p1.leeftijd > p2.leeftijd;
    }) << endl;
    return 0;
}
