// VbDynamicBinding_bis.cpp

// <<-operator werkt nu prima, aangezien deze 
// de private/protected virtuele methode print oproept
// Merk op: enkel <<-operator kan nog gebruikt worden
// (want methode print is private/protected geworden)
// <<-operator hoeft enkel voorzien te worden in de klasse Persoon
// (methode print is voorzien in alle klassen)

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Persoon {
   private:
      string naam;
   protected:
      virtual void print(ostream &) const;   
   public:
      Persoon(const string &nm="");    
      friend ostream& operator<<(ostream&,const Persoon&);     
};  // Persoon

class Student : public Persoon {
   private:
      string klascode;
      void print(ostream &) const;
   public:
      Student(const string &nm="", const string &kl="");
};  // Student

class Leerkracht : public Persoon {
   private:
      string vakgroep;
      virtual void print(ostream &) const;
   public:
      Leerkracht(const string &nm="", const string &vg=""); 
};  // Leerkracht

Persoon::Persoon(const string &nm) : naam(nm) {}

void Persoon::print(ostream & os) const {
   os<<naam;
}

ostream& operator<<(ostream& os,const Persoon &p) {
	p.print(os);
	return os;
}

Student::Student(const string &nm, const string &kl) : 
            Persoon(nm),klascode(kl) {}

void Student::print(ostream &os) const {
   Persoon::print(os);
   os<<" zit in klas "<<klascode;
}

Leerkracht::Leerkracht(const string &nm, const string &vg) : 
                Persoon(nm),vakgroep(vg) {}

void Leerkracht::print(ostream &os) const {
   Persoon::print(os);
   os<<" uit vakgroep "<<vakgroep;
}

int main() {
   Persoon p("Leo");
   cout << p << endl;
      
   Student s("Jan","1Ba3");
   cout << s << endl;
   
   Leerkracht l("Marc","EA20");
   cout << l << endl;
  
   cout << "\np = l;" << endl; 
   p = l;
   cout << p << endl;
   
   cout << "\nPersoon *pps=&s, *ppl=&l;" << endl;
   Persoon *pps=&s, *ppl=&l;
   cout << *pps << endl;
   cout << *ppl << endl;
   
   cout << "\nPersoon *ppl2 = new Leerkracht(\"Els\",\"Talen\");" << endl;
   Persoon *ppl2 = new Leerkracht("Els","Talen");
   cout << *ppl2 << endl;
   delete ppl2;
   
   cout << "\nunique_ptr<Persoon> upp = make_unique<Student>(\"An\",\"Ma\");" << endl;
   unique_ptr<Persoon> upp = make_unique<Student>("An","Ma");
   cout << *upp << endl;
      
   cout <<"\nStudent *ps = &s;" << endl;
   Student *ps = &s;
   cout << *ps << endl;    
   
   cout <<"\nunique_ptr<Student> ups = make_unique<Student>(\"An\",\"Ma\");" << endl;
   unique_ptr<Student> ups = make_unique<Student>("An","Ma");
   cout << *ups << endl;
   
   return 0;
}
