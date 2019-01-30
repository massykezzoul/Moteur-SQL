#include <iostream>
#include "tabstring.h"

using namespace std;

TabString::TabString():table(NULL),size(0)
{

}
TabString::TabString(ifstream &file):table(NULL),size(0)
{

}
TabString::TabString(const TabString &tab)
{
    size = tab.size;
    /*on copie les elements*/
    for (unsigned long int i = 0 ; i<size ; ++i)
    {
        table[i]=tab.table[i];
    }
}
TabString::~TabString()
{
    if(table != NULL) delete[] table;
}
TabString &TabString::operator=(const TabString &tab)
{
    if(this!=&tab)
    {
        size=tab.size;
        /*on supprime l'ancien tableau*/
        delete[] table;
        /*on copie les elements*/
        for(unsigned long int i = 0 ; i < size ; ++i)
        {
            table[i]=tab.table[i]; 
        }
    }
    
    return *this;
}
void TabString::add(string str)
{
    size++;
    /*on cree un nouvel espace mémoire*/
    string *copie= new string[size];
    /*on copie les elements*/
        for(unsigned long int i = 0 ; i < size-1 ; ++i)
        {
            copie[i]=table[i]; 
        }
    /*on ajoute l'element à la dernière case*/
    copie[size-1]=str;
    /*suppression de l'ancien espace*/
    delete[] table;
    table=copie;

}
unsigned long int TabString::get(string str) const
{
    unsigned long int i=0;
    while(i<size)
    {
        if(table[i]==str) return i;
        i++;
    }
    return -1;
} 
string TabString::get(unsigned long int i) const
{
    return table[i];
}
unsigned long int TabString::getSize()const
{
    return size;
}
