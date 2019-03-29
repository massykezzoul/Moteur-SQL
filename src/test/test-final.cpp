#include <iostream>
#include <fstream>  // pour écrire le resultat dans un fichier

#include "../tabtable.h"
#include "../table.h"
#include "../requete.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc > 2) {
        /* Déclaration du Tableau de Table */
        TabTable baseDeDonnee;
        /* lecture des fichiers csv */
        for(int i = 1; i < argc - 1; i++)
            baseDeDonnee.add(argv[i]);
        /* Chargement de la requete sql */
        Requete sql(argv[argc-1]);
        /* Table resultat */
        Table res;
        /* execution de la requete sql sur les tables en mémoire */
        res = baseDeDonnee.executer(sql);
        /* fichier ou sera écrit le resultat */
        cout << "Execution terminer" << endl;
        ofstream file("resultat.txt");
        if (file) {
            file << res;
            cout << "le resultat a bien été écrit dans le fichier \"resultat.txt\"" << endl;
        } else {
            cout << res << endl;
            cerr << "Ecriture dans le fichier impossible" << endl;
        }
        return 0;

    } else {
        cerr << "Use it like : \n\t" << argv[0] <<" [one or more CSV file] [SQL request]" << endl;
        return 1;
    }
}
