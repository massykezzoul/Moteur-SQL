#include <iostream>
#include <sys/stat.h> // stat buffer
#include <unistd.h>
#include "../tabtable.h"

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        TabTable mesTables;
        for(int i = 1; i <= argc; i++){
            /* Test si c'est un fichier qui existe */ 
            struct stat buffer;   
            if (stat(argv[i], &buffer) == 0){
                mesTables.add(argv[i]);
                cout << mesTables[i-1].getNomTable() << " ajouté" << endl;   
            }
            else
                cerr << "'"<<argv[i]<<"' n'existe pas"<< endl;
        }
        
        string line;
        Table tab;
        
        cout << "Tapez exit pour quitter"<<endl;
        cout << "Donnez la table à afficher : "<< endl;
        while (line != "exit") {
            cout << "> ";
            cin >> line;
            
            tab = mesTables.get(line);
            if (line != "exit") {
                tab.print();
            }
        }
    } else {
        cerr << "No args"<< endl;
    }
    return 0;
}
