#include <iostream>
#include <fstream>

#include "tabtable.h"
#include "table.h"
#include "requete.h"

#define VERSION 1.0
#define DATE "Mai 2019"

void sortie(Table res);
void interactif(TabTable baseDeDonnee);
void help();

using namespace std;

int main(int argc, char const *argv[])
{
    /* Déclaration du Tableau de Table */
    TabTable baseDeDonnee;
    
    /* lecture des fichiers csv */
    for(int i = 1; i < argc - 1; i++)
        baseDeDonnee.add(argv[i]);

    if (argc != 1 && Requete::isRequete(argv[argc-1])) {
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
        if (argc != 1)
            baseDeDonnee.add(argv[argc - 1]);
        interactif(baseDeDonnee);
    }
    return 0;
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
    cout << "Pour afficher l'aide tappez 'help'." << endl;
    cout << "> ";
    getline(cin,str);   
    str = Requete::cleanLine(str);
    while (str != "exit") {
        if (Requete::isRequete(str)) {
            sql = Requete(str);
            res = baseDeDonnee.executer(sql);
            sortie(res);
        } else if (str == "csv") {
            res.to_csv(cout);
        } else if (str == "txt") {
            cout << res;
        } else if (str == "ls") {
            ls = baseDeDonnee.list();
            if (ls.getSize() == 0) 
                cout << "Aucune table en mémoire." << endl;
            else
                cout << "Les tables chargé en mémoire sont : " << endl;
            for (unsigned long int i=0; i < ls.getSize(); i++)
                cout << "\t"<< ls[i] << endl;
        } else if (str == "help") { 
            help();
        } else if (str.substr(0,3) == "add") {
            ifstream file(str.substr(4).c_str());
            if (file)
                baseDeDonnee.add(str.substr(4));
            else 
                cerr << str.substr(4) << " n'est pas un fichier." << endl;
            file.close();
        } else
            cerr << "Commande '" << str << "' non reconnue." << endl;
        cout << "> ";
        getline(cin,str);
        str = Requete::cleanLine(str);
    }
    return;
}

void help() {
    cout << "La liste des commandes disponibles : " << endl;
    cout << "\tselect ... : Execute la requete SQL" << endl;
    cout << "\tls : affiche la liste des tables charger en mémoire" << endl;
    cout << "\tadd [file.csv] : ajoute le fichier à la base de données (un seul fichier)" << endl;
    cout << "\tcsv : affiche le fichier resultat.csv" << endl;
    cout << "\ttxt : affiche le fichier resultat.txt" << endl;
    cout << "\thelp : Affiche cette aide" << endl;
    cout << endl;
    cout << "Version "<< VERSION << endl;
    cout << DATE << endl;
    cout << "Developper par :" << endl;
    cout << "\tKezzoul Massili" << endl;
    cout << "\tElhouiti Chakib" << endl;
    cout << "\tZeroual Ramzi" << endl;
    cout << "\tBouzidi Belkassim" << endl;
    cout << "\tFeï Yang" << endl;
    
    return;
}