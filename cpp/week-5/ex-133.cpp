#include "figuren.h"
#include <memory>
#include <stdexcept>

class Blokkendoos : vector<unique_ptr<Figuur>>{
    private:
        unique_ptr<Figuur> max_opp;
        void schrijf(ostream&) const;

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
    if (max_opp == nullptr) return nullptr;

    unique_ptr<Figuur> res = move(max_opp);

    // nieuwe max opp zoeken
    if (this->size() != 0) {
        double max_opp_val = (*this)[0]->oppervlakte();
        size_t idx_max = 0;
        for (size_t i = 1; i < this->size(); i++) {
            if ((*this)[i]->oppervlakte() > max_opp_val) {
                max_opp_val = (*this)[i]->oppervlakte();
                idx_max = i;
            }
        }
        max_opp = move((*this)[idx_max]);
        erase(begin() + idx_max);
    }

    return res;
}

void Blokkendoos::schrijf(ostream & out) const {
    for (auto& el : *this) {
        out << *el << endl;
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

Blokkendoos::Blokkendoos(const string& file_path) {
    ifstream in(file_path);
    if (!in.is_open()) {
        throw new runtime_error("Failed to open file" + file_path);
    }
    string fig_desc;
    in >> fig_desc;
    double x, y;
    while (!in.fail()) {
        unique_ptr<Figuur> temp;
        if (fig_desc == "rechthoek") {
            in >> x;
            in >> y;
            temp = make_unique<Rechthoek>(x, y);
        } else if (fig_desc == "cirkel") {
            in >> x;
            temp = make_unique<Cirkel>(x);
        } else if (fig_desc == "vierkant") {
            in >> x;
            temp = make_unique<Vierkant>(x);
        }
        push_back(temp);
        in >> fig_desc;
    }
}

int main(){
    Blokkendoos blokkendoos("../../fixtures/figuren.txt");
    cout<<endl<<"ALLE FIGUREN: ";
    cout<<blokkendoos<<endl;

    cout<<endl<<"DE 3 GROOTSTE, van groot naar klein: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"figuur met grootste opp:    "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
    }

    cout<<endl<<"DE NIEUWE BLOKKENDOOS BEVAT ALLEEN NOG DE KLEINERE FIGUREN: ";
    cout<<blokkendoos<<endl;

    return 0;
}