#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class bestand_niet_lang_genoeg : public invalid_argument {
    public:
        bestand_niet_lang_genoeg(const string& message) : invalid_argument(message) {};
};


string regel_uit_bestand(const string& bestandsnaam, int volg_nr) {
    ifstream inv(bestandsnaam);
    if (!inv.is_open()) {
        throw bestandsnaam + " kon niet geopend worden.\n";
    }

    string line; string magweg;
    inv >> line;
    getline(inv, magweg);
    if (line.find("VERHAAL") != 0) {
        throw line.c_str();
    }

    int curr_line_nr = 0;
    while (!inv.fail() && curr_line_nr < volg_nr) {
        getline(inv, line);
        curr_line_nr++;
    }
    if (inv.fail()) {
        throw bestand_niet_lang_genoeg(bestandsnaam + " heeft geen " + to_string(volg_nr) + " regels.");
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

    for(size_t i = 0; i<bestandsnamen.size(); i++){
        try {
            cout << regel_uit_bestand("../../fixtures/" + bestandsnamen[i] + ".txt", nrs[i]) << endl;
        } catch (const bestand_niet_lang_genoeg& err) {
            bestanden_niet_lang_genoeg += err.what();
        } catch (const char * err) {
            eerste_woorden += err;
            eerste_woorden += " ";
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

    cout<<eerste_woorden<<endl<<endl;

    return 0;
}