#include <iostream>
#include <sys/stat.h> // stat buffer
#include "../table.h"
#include "../tabtable.h"
#include "unistd.h"

#include <ctime>

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc > 2) {
        clock_t t1,t2;
        TabTable mesTables;
        for(int i = 1; i < argc; i++){
            /* Test si c'est un fichier qui existe */ 
            struct stat buffer;   
            if (stat(argv[i], &buffer) == 0){
                t1 = clock();
                mesTables.add(argv[i]);
                t2 = clock();
                cout << mesTables[i-1].getNomTable() << " ajouté en " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC << "Sec" << endl;   
            }
            else
                cerr << "'" << argv[i] << "' n'existe pas" << endl;
        }
        
        if (mesTables.getSize() < 2) {
            cerr << "QLile args" << endl;
            return 1;                
        } else {
            t1 = clock();
            Table tab = Table(mesTables[0],mesTables[1]);
            for(unsigned long int i = 2; i < mesTables.getSize(); i++)
                tab = Table(tab,mesTables[i]);
            
            //tab = tab.jointure(mesTables[0],mesTables[1]);
            t2 = clock();
            cout << tab.getNomTable()<< endl;
            cout << "Temps d'execution : " << (double) (t2-t1)/  (double) CLOCKS_PER_SEC
                 << "Sec pour : " << tab.getValeurAttributs().getSize() << " Lignes"
                 << " Et " << tab.getNomAttributs().getSize() << " Colonnes" << endl;
            //cout << tab << endl;
        }
    }else {
        cerr << "Qlile args" << endl;
        return 1;
    }
    return 0;
}
