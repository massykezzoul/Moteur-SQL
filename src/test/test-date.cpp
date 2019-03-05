#include <iostream>
#include <string>

#include "../date.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc == 1) {
        /* Pas d'arguments */
        string d[5];
        d[0] = string("20/08/1998");
        d[1] = string("15/08/1998");
        d[2] = string("25/08/1998");
        d[3] = string("05/03/2019");
        d[4] = string("Par défaut");
        
        Date date[5];
        date[0] = Date(d[0]);
        date[1] = Date(d[1]);
        date[2] = Date(d[2]);
        date[3] = Date(d[3]);
        date[4] = Date();

        int nb = 5;

        for(int i = 0; i < nb; i++) {
            cout << "La date '" << d[i] << "' se traduit par : '"<< date[i].toString()<<"'" << endl;
        }
        cout << endl;        
        cout << "Les operateurs de comparaison" << endl;
        cout << "Egalité :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' == '" << date[i].toString() << "' : " << (date[0] == date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Difference :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' != '" << date[i].toString() << "' : " << (date[0] != date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Inferieur :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' < '" << date[i].toString() << "' : " << (date[0] < date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Superieur :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' > '" << date[i].toString() << "' : " << (date[0] > date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Inferieur :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' < '" << date[i].toString() << "' : " << (date[0] < date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Superieur :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' > '" << date[i].toString() << "' : " << (date[0] > date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Inferieur ou égal :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' <= '" << date[i].toString() << "' : " << (date[0] <= date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
        cout << "Superieur ou égal :" << endl;
        for(int i = 0; i < nb; i++) {
            cout << "'" << date[0].toString() << "' >= '" << date[i].toString() << "' : " << (date[0] >= date[i]?"Vrai":"FAUX") << endl;
        }
        cout << endl;
    }
    return 0;
}
