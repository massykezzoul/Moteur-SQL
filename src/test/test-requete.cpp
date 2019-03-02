#include <iostream>
#include "../requete.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string line;
    Requete sql;
    
    if (argc == 1 ) {
        /* Si aucun arguments n'a été donné */
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
                //verification de la condition where
                 /* Initialisation de la ligne des attributs */
    TabString nomAtt;
    nomAtt.add("id1");
    nomAtt.add("age");
    nomAtt.add("id2");
    /* Initialisation de la ligne des valeurs */
    TabString val1;
    val1.add("1");
    val1.add("19");
    val1.add("1");

    TabString val2;
    val2.add("1");
    val2.add("29");
    val2.add("2");
    for(unsigned long int i = 0; i < sql.getWhere().getSize(); i++) {
        cout << sql.getWhere().getCond(i).toString() << endl;
    }
    
    for (unsigned long int i = 0 ; i< sql.getWhere().getSizeOp() ; i++) {
        if(sql.getWhere().getOpL(i)==0) cout << "and\t";
        else cout << "or\t";
    }
    /* Affichage du resultat de verifier() */
    cout << endl;
    cout << (sql.getWhere().verifier(val1,nomAtt)?"VRAI":"FAUX") << endl; 
    cout << (sql.getWhere().verifier(val2,nomAtt)?"VRAI":"FAUX") << endl;
               // cout << (sql.getWhere().getCond(0).toString()!=""?sql.getWhere():"No Where") << endl;
            }
        }
    } else {
        /* En utilisant les arguments */
            line = argv[1];
            sql = Requete(line);
            cout << "Requete : " << "\"" <<line << "\"" <<endl;
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
              //  cout << (sql.getWhere()!=""?sql.getWhere():"No Where") << endl;
                cout << endl;
        
    }
    
    return 0;
}
