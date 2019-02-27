#include "tabCondition.h"
#include <iostream>
using namespace std;





TabCondition::TabCondition():tab(NULL),oplogique(NULL),size(0){
}
TabCondition::TabCondition(string str):tab(NULL),oplogique(NULL),size(0)
{
    size_t debut=0,fin=str.size();
    unsigned int nband=0,nbor=0,nbop=0;
    cout << "ok";
    while(debut < fin)
    {
        cout << debut << endl;
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
                cout << str.substr(debut,posAnd) << endl;
                tab[i]=Condition(str.substr(debut,posAnd));
                oplogique[j]=AND;
                j++;
                i++;
                debut=posAnd+3;
                posAnd=debut;
            }
            else 
            {
                cout << str.substr(debut,posOr) << endl;
                tab[i]=Condition(str.substr(debut,posOr));
                oplogique[j]=OR;
                j++;
                i++;
                debut=posOr+2;
                posOr=debut;
            }
        }
        else 
        {
            cout << str.substr(debut,fin)<< endl;
            tab[i]=Condition(str.substr(debut,fin));
            i++;
            debut = fin ;
        }

    }
    size=i;

}
unsigned int TabCondition::getSizeOp()const
{
return size;
}
unsigned int TabCondition::getSize() const
{
return size-1;
}
Condition TabCondition::getCond(unsigned int i)const
{
    return tab[i];
}
OpLogique TabCondition::getOpL(unsigned int i)const 
{
    return oplogique[i];
}


bool TabCondition::verifier(TabString line,TabString attr)
{
return false;
}