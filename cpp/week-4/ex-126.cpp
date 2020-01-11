#include <vector>
#include <iostream>

using namespace std;

template<class T>
class mijn_vector : public vector<T> {
    using vector<T>::vector;

    public:
        void verdubbel(bool = false);
};

template<class T>
void mijn_vector<T>::verdubbel(bool dupl) {
    if (dupl) {
        size_t orig_size = this->size();
        this->resize(this->size() * 2);

        for (int i = orig_size - 1; i >= 0; i--) {
            (*this)[i * 2] = (*this)[i];
        }

        for(size_t i = 0; i < orig_size; i++) {
            size_t curr_ptr = i * 2;
            for (size_t j = 1; j < 2; j++) {
                (*this)[j + curr_ptr] = (*this)[curr_ptr];
            }
        }
    } else {
        for (size_t i = 0; i < this->size(); i++) {
            (*this)[i] = 2 * (*this)[i];
        }
    }
}

template<class T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (const T& el : vec) {
        out << el << " ";
    }
    out << endl;
    return out;
}

int main() {
    mijn_vector<int> v{10,20,30};
    cout << v;

    v.verdubbel();
    cout<<endl<<"na verdubbelen zonder parameter: " << v;
    v.verdubbel(true);
    cout<<endl<<"na verdubbelen met param true:   " << v;

    mijn_vector<int> w(v);
    cout<<endl<<"een kopie van v: " << w;

    mijn_vector<double> u(7);
    cout<<endl<<"een vector met 7 default-elt: " << u;
    for(size_t i=0; i<u.size(); i++){
        u[i] = i*1.1;
    }
    cout<<endl<<"na opvullen met getallen: " << u;

    u.verdubbel();
    cout<<endl<<"na verdubbelen zonder parameter: " << u;

    return 0;
}
