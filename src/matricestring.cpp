#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matricestring.h"

using namespace std;

MatriceString::MatriceString():tab(NULL),size(0),alloc(0){}

MatriceString::MatriceString(unsigned long int i):tab(new TabString[i]),size(0),alloc(i) {}

MatriceString::MatriceString(unsigned long int i,unsigned long int j):tab(new TabString[i]),size(0),alloc(i) {
    for(unsigned long int k = 0; k < i; k++) {
        tab[k] = TabString(j);
    }
}


MatriceString::MatriceString(ifstream &file):tab(NULL),size(0),alloc(0){
    if (file){
        string line;
        /* Compter le  nombre de ligne */
        unsigned long int nombre_ligne = 0;
        while ( !file.eof()) {
            getline(file,line);
            if (line != "") ++nombre_ligne;
        }
        alloc = nombre_ligne;
        file.seekg(0, file.beg);
        getline(file,line);
        tab = new TabString[alloc];
        while( !file.eof() ) {
            add(TabString(file));
        }
    }
    else {
        cerr << "Erreur d'ouverture du fichier" << endl;
        exit(1);
    }
}

MatriceString::MatriceString(const MatriceString& copie){
    alloc = copie.alloc;
    size = copie.size;
    tab = new TabString[alloc];
    for (unsigned long int i = 0; i < size; i++)
        tab[i] = copie.tab[i];
}

MatriceString::MatriceString(const MatriceString& mat1,const MatriceString& mat2)
    :tab(new TabString[mat1.size*mat2.size]),size(0),alloc(mat1.size*mat2.size){
    unsigned long int k = 0;
    for (unsigned long int i = 0; i < mat1.size; i++)
        for(unsigned long int j = 0; j < mat2.size; j++)
            tab[k++] = TabString(mat1[i],mat2[j]);
    size = k;
}

MatriceString::~MatriceString(){
    if (tab != NULL) delete[] tab;
}

MatriceString &MatriceString::operator=(const MatriceString &t) {
    if (this!=&t) {
        /* Suppression de l'ancien Tableau */
        alloc = t.alloc;
        if (tab != NULL) delete[] tab;
        tab = new TabString[alloc];
        size = t.size;

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
         for(unsigned long int i = 0; i < size - 1; i++) {
            //cout << "alloc : "<< alloc << " size : "<< size << " : " <<i << endl;
            copie[i] = tab[i];
        }
        delete[] tab;
        tab = copie;
    }
    // cout << "OK" << endl;
    tab[size++] = jdide;
}

void MatriceString::addColonne(const MatriceString& mat,unsigned long int indice) {
    if (size == 0) {
        for(unsigned long int i = 0; i < mat.size; i++) {
            tab[i].add(mat[i][indice]);
            size++;
        }
    } else if (size == mat.size) {
        for(unsigned long int i = 0; i < size; i++)
            this->tab[i].add(mat[i][indice]);
    }else {
        cerr << "Erreur à l'ajout de la collonne" << endl;
        cerr << size << " != " << mat.size << endl;
        exit(1);
    }
}

unsigned long int MatriceString::getSize() const{
    return size;
}
