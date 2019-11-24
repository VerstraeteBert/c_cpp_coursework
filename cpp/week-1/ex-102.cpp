#include <iostream>
#include <iomanip> // voor de std::setw, std::hex etc

using namespace std;

const int CEIL = 64;

int main() {
    for (int i = 0; i <= CEIL; i++) {
        cout
            << setw(4) << oct << i
            << setw(4) << dec << i
            << setw(4) << hex << i
            << endl;
    }
    return 0;
}