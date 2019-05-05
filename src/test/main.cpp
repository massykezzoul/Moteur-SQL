#include <iostream>
#include <fstream>

#include "../tabtable.h"
#include "../table.h"
#include "../requete.h"

void sortie(Table res);
void interactif(TabTable baseDeDonnee);

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 1) {
        cerr << "Veuillez donnée au moin un fichier CSV" << endl;
        return 1;
    } else {
        /* Déclaration du Tableau de Table */
        TabTable baseDeDonnee;
        
        /* lecture des fichiers csv */
        for(int i = 1; i < argc - 1; i++)
            baseDeDonnee.add(argv[i]);

        if (Requete::isRequete(argv[argc-1])) {
            /* Mode argument */
            /* Table resultat */
            Table res;
            /* Requete sql */
            Requete sql;
            if (argc == 2) {
                cerr << "Veuillez donnée au moin un fichier CSV avec la requête" << endl;
                return 1;
            }
            sql = Requete(argv[argc-1]);
            res = baseDeDonnee.executer(sql);
            sortie(res);
        } else {
            /* Mode interactif */
            /* Chargement du dernier argument */
            baseDeDonnee.add(argv[argc - 1]);
            interactif(baseDeDonnee);
        }
        return 0;
    }
}

/* Ecriture de la table dans les deux fichier */
void sortie(Table res) {
    // fichiers ou sera écrit le resultat
    cout << "Execution terminer" << endl;
    ofstream file("resultat.txt");
    ofstream file_csv("resultat.csv");
    
    if (file && file_csv) {
        file << res;
        res.to_csv(file_csv);
        cout << "le resultat a bien été écrit dans le fichier \"resultat.txt\" et \"resultat.csv\"" << endl;
    } else {
        cout << res << endl;
        cerr << "Ecriture dans le fichier impossible" << endl;
    }
    return;
}
// Mode interactif
void interactif(TabTable baseDeDonnee) {
    Table res;
    Requete sql;
    TabString ls;

    string str = "";
    cout << "Bienvenu dans le mode interactif" << endl;
    cout << "Donnez la requete" << endl << "> ";
    getline(cin,str);   
    str = Requete::cleanLine(str);
    while (str != "exit") {
        if (Requete::isRequete(str)) {
            sql = Requete(str);
            res = baseDeDonnee.executer(sql);
            sortie(res);
        } else if (str == "csv") {
            res.to_csv(cout);
            cout << endl;
        } else if (str == "txt")
            cout << res << endl;
        else if (str == "ls") {
            ls = baseDeDonnee.list();
            cout << "Les tables chargé en mémoire sont : " << endl;
            for (unsigned long int i=0; i < ls.getSize(); i++)
                cout << "\t"<< ls[i] << endl;
        } else
            cerr << "Commande '" << str << "' non reconnu" << endl;
        cout << "> ";
        getline(cin,str);
        str = Requete::cleanLine(str);
    }
    return;
}