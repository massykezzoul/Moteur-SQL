#include"tabstring.h"
#include<iostream>
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
        for (int i = 0 ; i<size ; ++i)
        {
            table[i]=tab[i];
        }
    }
    ~TabString::TabString()
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
            for(int i = 0 ; i < size ; ++i)
            {
                table[i]=tab[i]; 
            }
        }
    }
    void add(string str)
    {
        size++;
        /*on cree un nouvel espace mémoire*/
        string *copie= new string[size];
        /*on copie les elements*/
            for(int i = 0 ; i < size-1 ; ++i)
            {
                copie[i]=table[i]; 
            }
        /*on ajoute l'element à la dernière case*/
        copie[size-1]=str;
        /*suppression de l'ancien espace*/
        delete[] table;
        table=copie;

    }
    unsigned int TabString::get(string str) const
    {
        unsigned int i=0;
        while(i<size())
        {
            if(table[i]==str) return i;
            i++;
        }
    } 
    string TabString::get(unsigned int i) const
    {
        return table[i];
    }
    unsigned int TabString::size()const
    {
        return size;
    }
