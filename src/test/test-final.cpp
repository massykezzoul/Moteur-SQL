#include <iostream>
#include <fstream>
#include "../table.h"
#include "../tabtable.h"
#include "../requete.h"
#include "unistd.h"
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc >= 3) {
        /* Temps d'éxecution */
        clock_t t0,t1,t2;
        t0 = clock();
        TabTable mesTables;
        /* ajout des tables CSV */
        t1 = clock();
        for(int i = 1; i < argc -1; i++) {
            // argc -1 psq le dernier argument est la requete sql
            mesTables.add(argv[i]);
        }
        t2 = clock();
        cout << "Lecture des Tables en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC << " Secondes" << endl;

        /* Chargement de la requete sql en mémoire */
        t1 = clock();
        Requete sql(argv[argc-1]);
        t2 = clock();
        cout << "Chargement de la requete en mémoire en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC << " Secondes" << endl;

        /* La Table final */
        Table res;

        /* execution des jointures (à ameliorer !!) */
        t1 = clock();
        TabString join = sql.getFrom();
        if (mesTables.getSize() > 1) {
            res = Table(mesTables[0],mesTables[1]);
            for(unsigned long int i = 2; i < mesTables.getSize(); i++)
                res = Table(res,mesTables[i]);
        } else {
            res = mesTables[0];
        }
        t2 = clock();
        cout << "Jointure en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC  << " Secondes" << endl;
        /* Execution de la selection */
        t1 = clock();
        if (sql.getWhere().getSize() > 0)
            res = res.selection(sql.getWhere());
        t2 = clock();
        cout << "Selection en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC  << " Secondes" << endl;

        /* Execution de la projection */
        t1 = clock();
        res = res.projection(sql.getSelect());
        t2 = clock();
        cout << "Projection en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC  << " Secondes" << endl;

        /* Affichage du resultat dans un fichier */
        ofstream file("request.txt");
        t1 = clock();
        if (file) {
            file << res;
            cout << "file request.txt created" << endl;
        } else {
            cout << res << endl;
        }
        t2 = clock();
        cout << "Écriture en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC  << " Secondes" << endl;

        cout << "Execution Total en " << (double) (t2-t0)/  (double) CLOCKS_PER_SEC  << " Secondes" << endl;
                
    }else {
        cerr << "use it like this : "<<argv[0] <<" [one ore more CSV files] [SQL request]" << endl;
    }
    return 0;
}