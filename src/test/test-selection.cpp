#include <fstream>
#include <iostream>
#include <cstdlib>
#include "../table.h"
#include "../requete.h"
using namespace std;

int main(int argc, char const *argv[]) {
    if (argc == 3) {
        Table t(argv[1]);
        Requete sql(argv[2]);
        Table res = t.selection(sql.getWhere());

        ofstream file("selection.txt");
        if (file) {
            file << res << endl;
            cout << "Le resultat est dans le fichier selection.txt" << endl;
        }
        else
            cout << res << endl;        
    } else {
        cerr << "use this programme like this : sql [table.csv] [SQL request]"<< endl;
        exit(1);
    }
    return 0;
}

