#include <iostream>

int main() {
    char ch1, ch2;
    std::cout << "Geef een karakter in: ";
    std::cin >> ch1;
    std::cout << "Geef nog een karakter in: ";
    std::cin >> ch2;
    std::cout << "Dit zijn de karakters: " 
              << ch1 << ch2;
    return 0;
}
