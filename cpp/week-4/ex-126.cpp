#include <vector>
#include <iostream>

using namespace std;

template <class T>
class mijn_vector : public vector<T> {
    public:
        // inherit constructors
        using vector<T>::vector;

        void verdubbel(bool = false);

        friend ostream& operator<<(ostream& out, const mijn_vector<T>& vect){
            out << "[";
            if (vect.size() != 0) {
                out << " " << vect[0];
            }
            for (size_t i = 1; i < vect.size(); i++) {
                out << " - " << vect[i];
            }
            out << " ]";
            return out;
        }
};

template <class T>
void mijn_vector<T>::verdubbel(bool kopie) {
    if (kopie) {
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
            (*this)[i] = (*this)[i] * 2;
        }
    }
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
