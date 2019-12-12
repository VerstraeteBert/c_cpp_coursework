#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class bestand_niet_lang_genoeg : public runtime_error {
    public:
        bestand_niet_lang_genoeg(const string& filename, int len) : runtime_error(filename + " heeft geen " + to_string(len) + "regels") {};
        bestand_niet_lang_genoeg(const string &what) : runtime_error(what) {};
};

string regel_uit_bestand(const string& filename, size_t volgnr) {
    ifstream in(filename);
    if (!in.is_open()) {
        throw string(filename + " kon niet geopend worden\n");
    }

    string line;
    getline(in, line);

    if (line.find("VERHAAL") != 0) {
        throw line.c_str();
    }

    size_t curr = 1;
    while (curr <= volgnr && !in.fail()) {
        getline(in, line);
        curr++;
        if (in.fail()) {
            throw bestand_niet_lang_genoeg(filename, volgnr);
        }
    }
    return line;
}

int main(){
    vector<string> bestandsnamen{"niks","een","twee","drie","vier",
                                 "vijf","zes","zeven","acht","negen","tien","elf","twaalf"};
    vector<int> nrs{8,5,2,10,7,3,8,4,1,1,6,2,4};

    string bestanden_niet_gevonden = "";
    string bestanden_niet_lang_genoeg = "";
    string eerste_woorden = "";

    for(size_t i=0; i<bestandsnamen.size(); i++){
        try {
            cout << regel_uit_bestand("../../fixtures/"+ bestandsnamen[i] +".txt",nrs[i]) << endl;
        } catch(const bestand_niet_lang_genoeg& err) {
            bestanden_niet_lang_genoeg += err.what();
        } catch (const char * err) {
            eerste_woorden += err;
        } catch (const string& err) {
            bestanden_niet_gevonden += err;
        }
    }

    cout<<endl<<endl<<"BESTANDEN NIET GEVONDEN:"<<endl;
    cout<<bestanden_niet_gevonden;

    cout<<endl<<"BESTANDEN NIET LANG GENOEG:"<<endl;
    cout<<bestanden_niet_lang_genoeg<<endl;

    cout<<endl<<"BESTANDEN ZONDER STARTWOORD 'VERHAAL':"<<endl;
    cout<<"dit waren de woorden die er wel als eerste stonden:"<<endl<<endl;

    cout<< eerste_woorden <<endl <<endl;

    return 0;
}
