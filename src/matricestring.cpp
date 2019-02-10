#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matricestring.h"

using namespace std;

MatriceString::MatriceString():tab(NULL),size(0),alloc(0){}

MatriceString::MatriceString(ifstream &file):tab(NULL),size(0),alloc(0){
    if (file){
        string line;
        file.seekg(0, file.end);
        alloc = file.tellg();
        file.seekg(0, file.beg);
        getline(file,line);
        tab = new TabString[alloc];

        while( !file.eof() ) {
            add(TabString(file));
        }
    }
    else 
        exit(1);
}

MatriceString::MatriceString(const MatriceString& copie){
    alloc = copie.alloc;
    size = copie.size;
    tab = new TabString[alloc];
    for (unsigned long int i = 0; i < size; i++)
        tab[i] = copie.tab[i];
}
/*MatriceString::MatriceString(const MatriceString& copie,const TabString &attr)
{
    alloc = copie.alloc;
    size = copie.size;
    tab = new TabString[alloc];
    for (unsigned long int j=0;j<attr.getSize();++j)
    {
    for (unsigned long int i = 0; i < size; i++)
       {    if (tab[i].get(attr.get(j))==j)
           tab[i].get(j) = copie.tab[i].get(j); }
    }
}*/
 void MatriceString::setTab(unsigned long int alloc)
 {
     tab = new TabString[alloc];
 }


MatriceString::MatriceString(const MatriceString& mat1,const MatriceString& mat2)
    :tab(new TabString[mat1.size*mat2.size]),size(0),alloc(mat1.size*mat2.size){
    for (unsigned long int i = 0; i < mat1.size; i++)
        for(unsigned long int j = 0; j < mat2.size; j++)
            add(TabString(mat1[i],mat2[j]));
}

MatriceString::~MatriceString(){
    if (tab != NULL) delete[] tab;
}

MatriceString &MatriceString::operator=(const MatriceString &t) {
    if (this!=&t) {
        alloc = t.alloc;
        size = t.size;
        /* Suppression de l'ancien Tableau */
        if (tab != NULL) delete[] tab;
        tab = new TabString[t.size];
        /* copie des elements */
        for(unsigned long int i = 0; i < size; i++) {
            tab[i] = t.tab[i];
        }
        
    }
    return *this;
}

TabString& MatriceString::operator[](unsigned long int i) {
    if (i < 0 || i > size){
        cerr << "Out of range on MatriceString"<< endl;
        exit(1);
    }
    return tab[i];
}

const TabString& MatriceString::operator[](unsigned long int i)const {
    if (i < 0 || i > size){
        cerr << "Out of range on MatriceString"<< endl;
        exit(1);
    }
    return tab[i];
}

void MatriceString::add(const TabString& jdide){
    if (size >= alloc) {
        /* Création d'un nouvelle espace mémoire */
        if (alloc > 0) alloc *= 2; else alloc = 2;
        TabString* copie = new TabString[alloc];
        /* Copie des elements */
        for(unsigned long int i = 0; i < size - 1; i++)
            copie[i] = tab[i];
        delete[] tab;
        tab = copie;
    }
    tab[size++] = jdide;
}

TabString& MatriceString::get(unsigned long int i) const {
    if (i < 0 || i > size)
        exit(1);
    return tab[i];        
}

unsigned long int MatriceString::getSize() const{
    return size;
}
unsigned long int MatriceString::getAlloc() const {
    return alloc;
}
void MatriceString::setSize(unsigned long int size){
    this->size=size;
}
void MatriceString::setAlloc(unsigned long int alloc){
    this->alloc=alloc;
}


