#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tabstring.h"
#include "requete.h"
using namespace std;

TabString::TabString():table(NULL),size(0),alloc(0)
{

}
TabString::TabString(ifstream &file):table(NULL),size(0),alloc(0)
{
    if (file){
        string line;
        getline(file,line);
        line = Requete::cleanLine(line);
        size = strsplit2(line,table,',');
        alloc = size;
        if (size == 0) {
            cerr << "Erreur dans Strsplit (size == 0)" << endl;
            exit(1);
        }
    } else {
        cerr << "Impossible d'ouvrire le fichier (cons TabString)" << file << endl;
        exit(1);
    }
}

TabString::TabString(string &line):table(NULL),size(0),alloc(0)
{
    line = Requete::cleanLine(line);
    size = strsplit2(line,table,',');
    alloc = size;
    if (size == 0) {
        cerr << "Erreur dans Strsplit (size == 0)" << endl;
        exit(1);
    }
}


TabString::TabString(unsigned long int i):table(new string[i]),size(0),alloc(i) {}

TabString::TabString(string*& str,unsigned long int i):table(new string[i]),size(0),alloc(i) {
    for (unsigned long int j = 0 ; j < i ; j++) {
        add(str[j]);
    }
}


TabString::TabString(const TabString &tab)
{
    size = tab.size;
    alloc = tab.alloc;
    table = new string[alloc];
    /*on copie les elements*/
    for (unsigned long int i = 0 ; i<size ; ++i)
    {
        table[i]=tab.table[i];
    }
}

TabString::TabString(const TabString &tab1,const TabString &tab2)
    :table(new string[tab1.size+tab2.size]),size(0),alloc(tab1.size+tab2.size) {
    /*on copie les elements*/
    unsigned long int i = 0;
    for (i = 0 ; i<tab1.size ; ++i)
        add(tab1[i]);

    for(unsigned long int j = 0; j < tab2.size; j++)
        add(tab2[j]);
}

TabString::~TabString()
{
    if(table != NULL) delete[] table;
}

TabString &TabString::operator+=(const TabString &tab) {
    for(unsigned long int i = 0; i < tab.size; i++)
        add(tab[i]);
    return *this;
}


TabString &TabString::operator=(const TabString &tab)
{
    if(this!=&tab)
    {
        /* Réallocation si espace insufisant */
        alloc = tab.alloc;
        /*on supprime l'ancien tableau*/
        if (table != NULL) delete[] table;
        table = new string[alloc];
        
        size = tab.size;
        
        /*on copie les elements*/
        for(unsigned long int i = 0 ; i < size ; ++i)
        {
            table[i]=tab[i];
        }
    }
    
    return *this;
}

string &TabString::operator[](unsigned long int i){
    if (i < 0 || i >= size) {
        cerr << "Out of Range in TabString: "<<i<< endl;
        exit(1);
    }
    return table[i];
}

const string &TabString::operator[](unsigned long int i) const{
    if (i < 0 || i >= size) {
        
        cerr << "Out of Range in TabString: "<<i<< endl;
        exit(1);
    }
    return table[i];
}

void TabString::add(const string& str)
{
    if (size >= alloc) {
        /* Création d'un nouvelle espace mémoire */
        if (alloc > 0) alloc *= 2; else alloc = 2;
        string* copie = new string[alloc];
        /* Copie des elements */
        for(unsigned long int i = 0; i < size; i++)
            copie[i] = table[i];
        if (table != NULL) delete[] table;
        table = copie;
    }
    table[size++] = str;
    
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

unsigned long int TabString::strsplit2(const string& line,string* &tab,char delim)
{
    bool go=false; unsigned int j = 0;
    unsigned int i = 0,nbc =0;
    // Compter le nombre d'attribut dans la line
    while (i < line.size()){
        if(line[i]=='\"'){
            go = true;
            while(go){
                i++;
                if(line[i]=='\"' && (i >= line.size()-1 || line[i+1]!='\"')){
                    go=false;
                } else if (line[i]=='\"' && line[i+1]=='\"') i++;
            }
        }
        if(line[i]==delim){
            nbc++;
        }
        i++;
    }
    i=0;unsigned int deb=0;
    // Allocaton mémoire
    tab = new string[nbc+1]; 

    // Debut de lecture des attributs
    while (i< line.size()){
         if(line[i]=='\"'){
            go = true;deb = i+1;
            while(go){
                i++;
                if(line[i]=='\"' && (i >= line.size()-1 || line[i+1]!='\"')){
                    go=false;
                } else if (line[i]=='\"' && line[i+1]=='\"') {
                    tab[j] += line.substr(deb,i-deb-1);
                    deb = i+2;
                    i++;
                }
                
            }
            tab[j]+=line.substr(deb,i-deb);
            tab[j] = Requete::cleanLine(tab[j]);
            j++;
            i++;
            deb = i + 1;
            
        }
        else if (line[i] == delim) {
            tab[j]+=line.substr(deb,i-deb);
            tab[j] = Requete::cleanLine(tab[j]);
            j++;
            deb = i+1 ;


        }
        i++;

    }
    if (j <= nbc) {
        tab[j] += line.substr(deb);
        tab[j] = Requete::cleanLine(tab[j]);
        j++;
    }

    return j;
} 