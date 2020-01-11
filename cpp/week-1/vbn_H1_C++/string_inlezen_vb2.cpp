#include <iostream>

int main() {
    std::string s;
    std::cout << "Geef je naam in: ";
    getline(std::cin,s);
    std::cout << "Dag " << s << std::endl;
    
	int getal;
    std::cout << "Geef nu een getal in: ";
    std::cin >> getal;
    std::cout << getal << " + 1 = " 
              << getal+1;
         
    return 0;
}
