#include <memory>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Langeslang : public vector<unique_ptr<T>>{
    private:
        void schrijf(ostream&)const;
    public:
        void vul(const vector<T>& v);
        Langeslang& concatenate(Langeslang & c);

        friend ostream& operator<<(ostream& out, const Langeslang& l){
             l.schrijf(out);
             return out;
        }
};

template <class T>
void Langeslang<T>::schrijf(ostream& out) const {
    for (size_t i = 0; i < this->size(); i++) {
        out << *(*this)[i] << " ";
    }
}

template <class T>
void Langeslang<T>::vul(const vector<T>& v) {
    this->reserve(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        this->push_back(make_unique<T>(v[i]));
    }
}

template <class T>
Langeslang<T>& Langeslang<T>::concatenate(Langeslang & c) {
    size_t orig_size = this->size();
    this->reserve(orig_size + c.size());

    if (&c == this) {
        for (size_t i = 0; i < orig_size; i++) {
            this->push_back(make_unique<T>(*(*this)[i]));
        }
    } else {
        size_t concat_size = c.size();
        for (size_t i = 0; i < concat_size; i++) {
            this->push_back(move(c[i]));
        }
        c.clear();
    }

    return *this;
}

int main(){
    Langeslang<string> a;
    Langeslang<string> b;
    Langeslang<string> c;
    a.vul({"hanlo","vrienden"});      // via a vind je de getallen 1 en 2
    b.vul({"het","is","wel", "vroeg", "donker", "he"});    // via b vind je de getallen 3, 4 en 5
    c.vul({",","en", "het", "is", "ook", "koud", "grt", "B"});      // via c vind je de getallen 6 en 7
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;

    a.concatenate(a);
    // via a vind je nu de 4 getallen 1, 2, 1 en 2

    cout<<"na a.concatenate(a)"<<endl;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;

    a.concatenate(b).concatenate(c);
//     via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
//     b is leeg
//     c is leeg

    cout<<"na a.concatenate(b).concatenate(c)"<<endl;
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
    return 0;
}

//
//int main(){
//    Langeslang<int> a;
//    Langeslang<int> b;
//    Langeslang<int> c;
//    a.vul({1,2});      // via a vind je de getallen 1 en 2
//    b.vul({3,4,5});    // via b vind je de getallen 3, 4 en 5
//    c.vul({6,7});      // via c vind je de getallen 6 en 7
//    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
//
//    a.concatenate(a);
//    // via a vind je nu de 4 getallen 1, 2, 1 en 2
//
//    cout<<"na a.concatenate(a)"<<endl;
//    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
//
//    a.concatenate(b).concatenate(c);
////     via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
////     b is leeg
////     c is leeg
//
//    cout<<"na a.concatenate(b).concatenate(c)"<<endl;
//    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
//    return 0;
//}
