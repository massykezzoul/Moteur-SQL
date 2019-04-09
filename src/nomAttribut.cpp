#include <string>
#include "nomAttribut.h"

using namespace std;

NomAttribut::NomAttribut(string nomTable,string nomAttribut):nomTable(nomTable),nomAttribut(nomAttribut){}
NomAttribut::NomAttribut(string str){
    size_t j = str.find_first_of(".");
    if (j == string::npos) {
        nomTable = "";
        nomAttribut = str;
    }
    else {
        nomTable = str.substr(0, j);
        nomAttribut = str.substr(j + 1);
    }
}
NomAttribut::NomAttribut():nomTable(""),nomAttribut(""){}

const string& NomAttribut::getTable() const{
    return nomTable;
}
const string& NomAttribut::getAttribut() const{
    return nomAttribut;
}

string& NomAttribut::getTable(){
    return nomTable;
}
string& NomAttribut::getAttribut(){
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
    
