#include<iostream>
#include "../table.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        Table matable(argv[1]);
        // Affichage de la table
        // cout << matable << endl;

        cout << "La Table '" << matable.getNomTable() <<  "' : " << endl;
        // Nombre de ligne 
        cout << "\tNombre de lignes  : " << matable.getValeurAttributs().getSize()+1 << endl;
        cout << "\ttaille du fichier : " << matable.getTailleFichier() << " o." << endl;
    } else {
        cerr << "Please give a file"<< endl;
    }

    return 0;
}