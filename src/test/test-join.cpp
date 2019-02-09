#include <iostream>
#include <sys/stat.h> // stat buffer
#include "../tabtable.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc > 2) {
        TabTable mesTables;
        for(int i = 1; i < argc; i++){
            /* Test si c'est un fichier qui existe */ 
            struct stat buffer;   
            if (stat(argv[i], &buffer) == 0){
                mesTables.add(argv[i]);
                cout << mesTables[i-1].getNomTable() << " ajouté" << endl;   
            }
            else
                cerr << "'" << argv[i] << "' n'existe pas" << endl;
        }
        
        if (mesTables.getSize() < 2) {
            cerr << "QLile args" << endl;
            return 1;                
        } else {
            Table tab;
            tab = tab.jointure(mesTables[0],mesTables[1]);
            cout << '\t' << tab.getNomTable() << " : " << endl;
            cout << tab << endl;
        }
    }else {
        cerr << "Qlile args" << endl;
        return 1;
    }
    return 0;
}
