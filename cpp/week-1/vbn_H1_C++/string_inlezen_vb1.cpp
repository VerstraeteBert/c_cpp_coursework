#include <iostream>

int main() {
    std::string s,t;
    std::cout << "Geef je naam in: ";
    std::cin >> s;
    std::cout << "Dag " << s << std::endl;
    int getal;
    std::cout << "Geef nu een getal in: ";
    std::cin >> getal;
    std::cout << getal << " + 1 = " 
              << (getal+1) << std::endl;
    //indien vorige input mislukt zou zijn, staat de failbit
	//van std::cin op true (en zal je niets meer kunnen inlezen)
    std::cin.clear();
    //nu staat de failbit terug op false en zal hij opnieuw
    //proberen in te lezen
    std::cout << "Geef nog eens je naam in: ";
    std::cin >> t;
    std::cout << "Dag " << t << std::endl;          
    return 0;
}
