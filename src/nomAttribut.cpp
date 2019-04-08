#include <string>
#include "nomAttribut.h"

using namespace std;

NomAttribut::NomAttribut(string nomTable,string nomAttribut):nomTable(nomTable),nomAttribut(nomAttribut){}
NomAttribut::NomAttribut():nomTable(""),nomAttribut(""){}

string NomAttribut::getTable() const{
    return nomTable;
}
string NomAttribut::getAttribut() const{
    return nomAttribut;
}

bool NomAttribut::operator==(NomAttribut att) const{
    if (att.getTable() == "")
        return att.getAttribut() == nomAttribut;
    else
        return att.getAttribut() == nomAttribut && att.getTable() == nomTable;
}

void NomAttribut::operator=(NomAttribut att){
    nomTable = att.getTable();
    nomAttribut = att.getAttribut();
}
    
