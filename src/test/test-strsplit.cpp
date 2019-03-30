#include "../tabstring.h"
#include <iostream>
#include <fstream>

using namespace std ;

void affiche(string s) {
    for(size_t i = 0; i < s.size(); i++) {
       cout <<"'" <<s[i] << "' ";
    }
    
}

int main(int argc , const char **argv){
    
    string* tab ; 
    unsigned long int res = -1;
    if (argc == 1) {
        string donnee = "\"01500\",\"01004\",\"\",\"Ambérieu-en-Bugey\",\"\",\"AMBERIEU-EN-BUGEY\",\"AMBERIEU EN BUGEY\",\"82\",\"RHONE-ALPES\",\"01\",\"Ain\",\"45.979851\",\"5.33689\",\"A516\",\"AMPRNPJ\"";
        cout << "Traitement de : " << endl << donnee << endl;
        res = TabString::strsplit2(donnee,tab,',');
        cout << "Nombre d'attribut : "<< res << endl;
        for (unsigned long int i = 0 ; i < res ; i++) {
            cout << "Attribut " << i << " : " << tab[i]<< endl;
        }
    } else if (argc == 2){
        res = TabString::strsplit2(argv[1],tab,',');
        cout << "Nombre d'attribut : "<< res << endl;
        for (unsigned long int i = 0 ; i < res ; i++) {
            cout << "Attribut "<<i << " : " << tab[i]<< endl;
        }
    } else {
        /* 
            appelle :
                "./sql -f file.csv" 
        */
        ifstream file(argv[2]);
        string donnee;
        int i = 0;
        while (!file.eof()) {
            getline(file,donnee);
            cout << "line " << i++;
            res = TabString::strsplit2(donnee,tab,',');
            cout << " OK, nombre de colonnes = " << res<< endl;
            //getchar();
        }
    }
    return 0;
}
