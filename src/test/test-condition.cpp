#include <iostream>
#include <string>
#include "../condition.h"
#include "../tabstring.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string c("age = 19"); // La condition à tester
    Condition cond(c);    // Appel au constructeur de la classe Condition
    /* Inistialisation de deux TabString (deux ligne d'un fichier CSV) */
    TabString tab;
    TabString tab1;
    tab.add("Kezzoul");
    tab.add("19");
    tab1.add("El Houiti");
    tab1.add("25");

    cout << "La Condition : " << c << " : " << endl;
    cout << "Operande 1 : " << "'" <<cond.getOp1() << "'" << endl;
    cout << "Operande 2 : " << "'" << cond.getOp2() << "'" << endl;
    cout << "Operateur  : " << "'" << cond.getOperateur() << "'" << endl;
    cout << "Type de la condition : " << (cond.getType()==VAL?"ATTRIBUT/VAL":(cond.getType()==ATTRIBUT?"ATTRIBUT/ATTRIBUT":"ERREUR")) << endl;

    cout << (cond.verifier(tab,1)?"vrai":"faux") << endl;
    cout << (cond.verifier(tab1,1)?"vrai":"faux") << endl;
    return 0;
}
