#include "../tabCondition.h"
#include <iostream>
using namespace std; 

int main()
{
    string str = "age >= 19 and id1 = id2";
    TabCondition objet(str);
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
    for(unsigned long int i = 0; i < objet.getSize(); i++) {
        cout << objet.getCond(i).toString() << endl;
    }
    
    for (unsigned long int i = 0 ; i< objet.getSizeOp() ; i++) {
        if(objet.getOpL(i)==0) cout << "and\t";
        else cout << "or\t";
    }
    /* Affichage du resultat de verifier() */
    cout << endl;
    cout << (objet.verifier(val1,nomAtt)?"VRAI":"FAUX") << endl; 
    cout << (objet.verifier(val2,nomAtt)?"VRAI":"FAUX") << endl;
}