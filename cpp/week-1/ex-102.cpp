#include <iostream>
#include <iomanip>

const int CEIL = 64;

int main() {
    for (int i = 0; i <= CEIL; i++) {
        std::cout
            << std::setw(4) << std::oct << i
            << std::setw(4) << std::dec << i
            << std::setw(4) << std::hex << i
            << std::endl;
    }
    return 0;
}