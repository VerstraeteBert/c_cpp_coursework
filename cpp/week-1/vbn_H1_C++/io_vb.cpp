#include <iostream>

int main() {
	int i=0;
	std::cout << "Geef twee getallen in :\n";
	int getal1, getal2;
	std::string s;
	std::cin >> getal1 >> getal2;
	std::cout << "getal1 dec = " << getal1 << std::endl
	          << "getal1 hex = " << std::hex << getal1;
    std::cout << "\ngetal2 = " << getal2 << std::endl;  
	std::cin >> s >> getal2;    
	return 0;
	//ga na wat er gebeurt als je dit ingeeft:
	//123 abc
	//kan je nu opnieuw proberen 2 getallen inlezen?
	//uitleg: zie string_inlezen_vb1.cpp
}

