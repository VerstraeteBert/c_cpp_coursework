#include <iostream>

int main() {
  	int getal;
    std::cout << "Geef een getal in: ";
    std::cin >> getal;
    std::cout << getal << " + 1 = " 
              << getal+1;
    fflush(stdin);
    std::string s;
    std::cout << "\nGeef nu je naam in: ";
    getline(std::cin,s);
    std::cout << "Dag " << s << std::endl;   
	    
    return 0;
}
