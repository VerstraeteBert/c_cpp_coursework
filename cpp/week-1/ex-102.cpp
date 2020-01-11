#include <iostream>
#include <iomanip> // voor de std::setw, std::hex etc

using namespace std;

const int MAX = 64;

int main() {
    for (int i = 0; i < MAX; i++) {
        cout << setw(3)
            << oct << i << " "
            << hex << i << " "
            << dec << i
            << endl;
    }
    return 0;
}