#include <iostream>

int main() {
    char ch1, ch2;
    std::cout << ch1;
    std::cout << "Geef een karakter in: ";
    ch1 = std::cin.get();
    std::cout << "Geef nog een karakter in: ";
    ch2 = getchar();
    std::cout << "Dit zijn de karakters: " 
         << ch1 << ch2;
    return 0;
}
