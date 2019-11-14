#include <iostream>
/**
 * char toevoegen aan een string append niet; "" + c dus niet gebruiken
 * Echter lukt string + 'k' wel
**/
int main () {
    char c = 'x'; std::string s = "" + c;
    std::cout << "karakter "<< c <<" omgezet: "<< s << "." << std::endl;
    char k = 'y'; std::string w = "";w += k; std::cout << "karakter "<< k <<" omgezet: "<< w << "." << std::endl;
}
