#include "tabCondition.h"
#include <iostream>
using namespace std;





TabCondition::TabCondition():tab(NULL),oplogique(NULL),size(0){
}
TabCondition::TabCondition(string str):tab(NULL),oplogique(NULL),size(0)
{
    size_t debut=0,fin=str.size();
    unsigned int nband=0,nbor=0,nbop=0;
    while(debut < fin)
    {
        debut=str.find("and",debut+1);
        if(debut != string::npos) nband++;
    }
    debut = 0;
    while(debut < fin )
    {
        debut=str.find("or",debut+1);
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
        posAnd=str.find("and",posAnd);
        posOr=str.find("or",posOr);
        if(posAnd != string::npos || posOr != string::npos)
        {
            if (posAnd < posOr )
            {
                tab[i]=Condition(str.substr(debut,posAnd - debut - 1));
                oplogique[j]=AND;
                j++;
                i++;
                debut=posAnd+4;
                posAnd=debut;
            }
            else 
            {
                tab[i]=Condition(str.substr(debut,posOr - debut - 1));
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


bool TabCondition::verifier(const TabString &line,const TabString &attr) const
{
    bool booleen = tab[0].verifier(line,attr.get(tab[0].getOp1()),attr.get(tab[0].getOp2()));
    unsigned int i=0;
    while(i < getSizeOp())
    {
        if(oplogique[i]==AND)
        {
            booleen = (booleen && tab[i+1].verifier(line,attr.get(tab[i+1].getOp1()),attr.get(tab[i+1].getOp2())));
        }
        else booleen = (booleen || tab[i+1].verifier(line,attr.get(tab[i+1].getOp1()),attr.get(tab[i+1].getOp2())));
        i++;
    }
    return booleen;
}