#include <iostream>
/**
 * eerste lijn werkt niet, constante c-strings kan je niet met de + operator op appenden (strcat)
 * 4e lijn werkt wel, w is reeds geïnitialiseerd als std string, toevoegen met + operator lukt erna WEL
**/
int main () {
    char c = 'x'; std::string s = "" + c;
    std::cout << "karakter "<< c <<" omgezet: "<< s << "." << std::endl;
    char k = 'y'; std::string w = "";w += k; std::cout << "karakter "<< k <<" omgezet: "<< w << "." << std::endl;
}
