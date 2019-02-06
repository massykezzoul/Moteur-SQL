#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matricestring.h"

using namespace std;

MatriceString::MatriceString():tab(NULL),size(0),alloc(0){}

MatriceString::MatriceString(ifstream &file):tab(NULL),size(0),alloc(0){
    if (file){
        file.seekg(0, file.end);
        alloc = file.tellg();
        file.seekg(0, file.beg);
        tab = new TabString[alloc];

        unsigned long int i = 0;
        while( !file.eof() ) {
            add(TabString(file));
            cout << "Ligne " << i++ << "Ok" << endl;
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
