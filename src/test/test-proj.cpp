#include<iostream>
#include "../table.h"
#include "../tabstring.h"
#include "../matricestring.h"

#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        clock_t t1,t2;
        Table tab;
        Table matable(argv[1]);
        TabString attr(2);
        attr.add("NOM");
        attr.add("PRENOM");
        t1 = clock();
        tab=matable.projection(attr);
        t2 = clock();
        cout << endl << tab << endl;
        cout << "La Table '" << matable.getNomTable() <<  "'" << endl;
        cout << "Temps d'execution : " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC
             << "Sec pour : " << tab.getValeurAttributs().getSize() << " Lignes"
             << " Et " << tab.getNomAttributs().getSize() << " Colonnes" << endl;
    } else {
        cerr << "Please give a file"<< endl;
    }

    return 0;
}
