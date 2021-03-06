#include <iostream>
#include "../requete.h"
#include "../tabAttribut.h"
#include "../nomAttribut.h"

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
                        cout << sql.getSelect()[i] << " ";
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
                TabAttribut nomAtt;
                nomAtt.add(NomAttribut("","id1"));
                nomAtt.add(NomAttribut("","age"));
                nomAtt.add(NomAttribut("","id2"));
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
            cout << endl << "Requete : " << "\"" <<line << "\"" <<endl;
            /* Affichage de la projection */
            cout << "projection : " << endl;
            if (sql.getSelect().getSize() > 0) 
                for(unsigned int i = 0; i < sql.getSelect().getSize(); i++)
                    cout << "\t" << sql.getSelect()[i] << endl;
            else 
                cout << "Pas de projection";
            cout << endl;
            
            /* Affichage de la jointure */
            cout << "jointure : " << endl;
            if (sql.getFrom().getSize() > 0) 
                for(unsigned int i = 0; i < sql.getFrom().getSize(); i++)
                    cout << "\t" << sql.getFrom().get(i) << endl;
            else 
                cout << "Pas de jointure";
            cout << endl;

            /* Affichage de la selection */
            cout << "selection : " << endl;
            TabCondition objet = sql.getWhere();
            if (objet.getSize() > 0) {
                for(unsigned long int i = 0; i < objet.getSize(); i++) {
                    cout << objet.getCond(i).toString() << endl;
                }
                
                for (unsigned long int i = 0 ; i< objet.getSizeOp() ; i++) {
                    if(objet.getOpL(i)==0) cout << "and\t";
                    else cout << "or\t";
                }
            } else {
                cout << "Pas de Selection" << endl;
            }
            cout << endl << endl;
        
    }
    
    return 0;
}
