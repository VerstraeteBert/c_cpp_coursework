#include <string>

int main() {
   std::string s("test");
   for (int i = 0 ; i < s.size() ; i++)
      printf("%c",s[i]);
   s[s.length()-1] = 'm';
   s.at(2) = 'a';
   
   //vergeet -std=c++14 niet bij compiler-opties!!
   for (char c : s)
      printf("%c",c);   
}


