#include "./figuren.h"
#include <memory>
#include<fstream>
#include<iostream>

class Blokkendoos : vector<unique_ptr<Figuur>>{
    private:
        unique_ptr<Figuur> max_opp;
        void schrijf(ostream&)const;
    public:
        Blokkendoos(const string &);
        unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
        void push_back(unique_ptr<Figuur> & );
    friend ostream& operator<<(ostream& out, const Blokkendoos& l){
        l.schrijf(out);
        return out;
    }
};

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte() {
    if (max_opp == nullptr) {
        return nullptr;
    }
    unique_ptr<Figuur> res = move(max_opp);

    double max_opp_val = (*this)[0]->oppervlakte();
    size_t idx_max = 0;
    for (int i = 1; i < this->size(); i++) {
        double curr_opp = (*this)[i]->oppervlakte();
        if (curr_opp > max_opp_val) {
            idx_max = i;
            max_opp_val = curr_opp;
        }
    }

    max_opp = move((*this)[idx_max]);
    erase(begin() + idx_max);
    return res;
}

void Blokkendoos::schrijf(ostream & out) const {
    for (auto& el : *this) {
        out << *el << endl;
    }
}

Blokkendoos::Blokkendoos(const string& file_path) {
    ifstream in(file_path);
    if (!in.is_open()) {
        throw new runtime_error("Failed to open file: " + file_path);
    }
    string fig_descr;
    in >> fig_descr;
    double x, y;
    while (!in.fail()) {
        unique_ptr<Figuur> temp;
        if (fig_descr == "rechthoek") {
            in >> x;
            in >> y;
            temp = make_unique<Rechthoek>(x, y);
        } else if (fig_descr == "vierkant") {
            in >> x;
            temp = make_unique<Vierkant>(x);
        } else if (fig_descr == "cirkel") {
            in >> x;
            temp = make_unique<Cirkel>(x);
        }
        push_back(temp);
        in >> fig_descr;
    }
}

void Blokkendoos::push_back(unique_ptr<Figuur>& fig) {
    if (max_opp == nullptr) {
        max_opp = move(fig);
        return;
    }

    if (max_opp->oppervlakte() < fig->oppervlakte()) {
        max_opp.swap(fig);
    }

    vector<unique_ptr<Figuur>>::push_back(move(fig));
}

int main(){
    Blokkendoos blokkendoos("../../fixtures/figuren.txt");

    cout<<endl<<"ALLE FIGUREN: ";
    cout<<blokkendoos<<endl;

    cout<<endl<<"DE 3 GROOTSTE, van groot naar klein: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"figuur met grootste opp:    "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
    }

    cout<<endl<<"DE NIEUWE BLOKKENDOOS BEVAT ALLEEN NOG DE KLEINERE FIGUREN: " << endl;
    cout<<blokkendoos<<endl;

    return 0;
}