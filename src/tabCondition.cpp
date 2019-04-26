#include "tabCondition.h"
#include <iostream>
#include "tabAttribut.h"
#include "nomAttribut.h"
#include <cstdlib>
using namespace std;


TabCondition::TabCondition():tab(NULL),oplogique(NULL),size(0){
}
TabCondition::TabCondition(string str):tab(NULL),oplogique(NULL),size(0)
{
    size_t debut=0,fin=str.size();
    unsigned int nband=0,nbor=0,nbop=0;

    /* Calcul du nombre de AND et de OR */
    while(debut < fin)
    {
        debut=str.find(" and ",debut+1);
        if(debut != string::npos) nband++;
    }
    debut = 0;
    while(debut < fin )
    {
        debut=str.find(" or ",debut+1);
        if(debut !=string::npos) nbor++;
    }

    nbop=nband+nbor;
    tab = new Condition[nbop+1];
    oplogique = new OpLogique[nbop]; 
    debut = 0;
    size_t posOr=0;
    size_t posAnd=0;
    int i=0,j=0;
    while (debut < fin )
    {
        posAnd=str.find(" and ",posAnd);
        posOr=str.find(" or ",posOr);
        if(posAnd != string::npos || posOr != string::npos)
        {
            if (posAnd < posOr )
            {
                tab[i]=Condition(str.substr(debut,posAnd - debut));
                oplogique[j]=AND;
                j++;
                i++;
                debut=posAnd+4;
                posAnd=debut;
            }
            else 
            {
                tab[i]=Condition(str.substr(debut,posOr - debut));
                oplogique[j]=OR;
                j++;
                i++;
                debut=posOr+3;
                posOr=debut;
            }
        }
        else 
        {
            tab[i]=Condition(str.substr(debut,fin - debut));
            i++;
            debut = fin ;
        }

    }
    size=i;

}
unsigned int TabCondition::getSizeOp()const
{
return size-1;
}
unsigned int TabCondition::getSize() const
{
return size;
}
Condition TabCondition::getCond(unsigned int i)const
{
    return tab[i];
}
OpLogique TabCondition::getOpL(unsigned int i)const 
{
    return oplogique[i];
}


bool TabCondition::verifier(const TabString &line,const TabAttribut &attr) const
{
    // ERROR
    if (attr.get(tab[0].getOp1()) > attr.getSize()) { // A verifier
        cerr << "Erreur : '" << tab[0].getOp1() << "' introuvable" << endl;
        exit(1);
    }
    bool booleen = tab[0].verifier(line,attr.get(tab[0].getOp1()),attr.get(tab[0].getOp2()));
    unsigned int i=1;
    while(i <= getSizeOp())
    {
        if (attr.get(tab[i].getOp1()) > attr.getSize()) {
            cerr << "Erreur : '" << tab[i].getOp1() << "' introuvable" << endl;
            exit(1);
        }
        if(oplogique[i]==AND)
            booleen = (booleen && tab[i].verifier(line,attr.get(NomAttribut("",tab[i].getOp1())),attr.get(NomAttribut("",tab[i].getOp2()))));
        else 
            booleen = (booleen || tab[i].verifier(line,attr.get(NomAttribut("",tab[i].getOp1())),attr.get(NomAttribut("",tab[i].getOp2()))));
        i++;
    }
    return booleen;
}