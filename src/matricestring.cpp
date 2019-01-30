#include <fstream>
#include <cstdlib>
#include "matricestring.h"


using namespace std;

MatriceString::MatriceString():tab(NULL),size(0){}

MatriceString::MatriceString(ifstream &file):tab(NULL),size(0){
    if (file != NULL)
        while(! file.eof())
            add(TabString(file));
    else 
        exit(1);
}

MatriceString::MatriceString(const MatriceString& copie){
    size = copie.size;
    tab = new TabString[size];
    for (unsigned long int i = 0; i < size; i++)
        tab[i] = copie.tab[i];
}

MatriceString::~MatriceString(){
    if (tab != NULL) delete[] tab;
}

void MatriceString::add(const TabString& jdide){
    ++size;
    /* Création d'un nouvelle espace mémoire */
    TabString* copie = new TabString[size];
    /* Copie des elements */
    for(unsigned long int i = 0; i < size - 1; i++)
        copie[i] = tab[i];
    copie[size-1] = jdide;
    /* Suppression de l'ancien espace mémoire */
    delete[] tab;
    tab = copie;
}

TabString& MatriceString::get(unsigned long int i) const {
    if (i < 0 || i > size)
        exit(1);
    return tab[i];        
}

unsigned long int MatriceString::getSize() const{
    return size;
}
