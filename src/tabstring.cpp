#include <iostream>
#include <cstdlib>
#include "tabstring.h"

using namespace std;

TabString::TabString():table(NULL),size(0)
{

}
TabString::TabString(ifstream &file):table(NULL),size(0)
{
    if (file){
        string line;
        getline(file,line);
        size = strsplit(line,table,',');
        if (size == 0)
            exit(1);
    } else 
        exit(1);
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
        if (table != NULL) delete[] table;
        table = new string[tab.size];
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

unsigned long int TabString::strsplit(const string& line,string* &tab,char delim) {
    unsigned long int i = 1, j = 0 , deb = 0;
    /* Nombre de délim */
    unsigned long int nbc = 0;
    while (i < line.size()) {
        if (line[i] == delim && line[i-1] != '\\') 
            nbc++;
        i++;
    }
    i = 1;
    tab = new string[nbc+1];
    while (i < line.size()){
        if (line[i] != delim) ++i;
        else {
            if (line[i-1] == '\\') {
                tab[j] += line.substr(deb,i-1-deb);
                tab[j] += line[i];
                ++i;
                deb = i;
            } else {
                tab[j] += line.substr(deb,i-deb);
                ++i;
                deb = i;
                ++j;
            }
        }
    }
    tab[j] += line.substr(deb);

    return j+1;

}