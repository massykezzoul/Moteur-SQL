#include <iostream>
#include "../requete.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string line;
    Requete sql;

    cout << "Tapez exit pour quitter"<<endl;
    cout << "Donnez Une Requete à afficher : "<< endl;
    while (line != "exit") {
        cout << "> ";
        getline(cin,line);
        if (line != "exit") {
            sql = Requete(line);
            cout << "projection : " << endl;
            if (sql.getSelect().getSize() > 0) 
                for(unsigned int i = 0; i < sql.getSelect().getSize(); i++)
                    cout << sql.getSelect().get(i) << " ";
            else 
                cout << "NO SELECT";
            cout << endl;
            
            cout << "jointure : " << endl;
            if (sql.getFrom().getSize() > 0) 
                for(unsigned int i = 0; i < sql.getFrom().getSize(); i++)
                    cout << sql.getFrom().get(i) << " ";
            else 
                cout << "NO From";
            cout << endl;

            cout << "selection : " << endl;
            cout << (sql.getWhere()!=""?sql.getWhere():"No Where") << endl;
        }
    }
    return 0;
}
