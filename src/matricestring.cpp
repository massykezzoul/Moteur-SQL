#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matricestring.h"

using namespace std;

MatriceString::MatriceString():tab(NULL),size(0),alloc(0),tailleFichier(0){}

MatriceString::MatriceString(unsigned long int i):tab(new TabString[i]),size(0),alloc(i),tailleFichier(0) {}

MatriceString::MatriceString(unsigned long int i,unsigned long int j):tab(new TabString[i]),size(0),alloc(i),tailleFichier(0) {
    for(unsigned long int k = 0; k < i; k++) {
        tab[k] = TabString(j);
    }
}


MatriceString::MatriceString(ifstream &file):tab(NULL),size(0),alloc(0),tailleFichier(0){
    if (file){
        string line;
        /* Compter le nombre de ligne et le nombre de caractère */
        unsigned long int nombre_ligne = 0;
        while ( !file.eof()) {
            getline(file,line,'\n');
            if (line != "" && line != " " && line != "\n" && line.size()>0) {
                ++nombre_ligne;
                tailleFichier += line.size()+1;
            }
        }

        if (!file) {
            file.clear();
        }
        
        alloc = nombre_ligne;
        file.seekg(0, file.beg);
        /* ignorer les lignes vide au debut de fichier */
        while (getline(file,line) && line == "");
        tab = new TabString[alloc];
        while(getline(file,line)) {
            /* ignorer les lignes vides au milier et à la fin du fichier */
            if (line != "" && line != " " && line != "\n" )
                add(TabString(line));
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
    tailleFichier = copie.tailleFichier;
    tab = new TabString[alloc];
    for (unsigned long int i = 0; i < size; i++)
        tab[i] = copie.tab[i];
}

/* Produit cartésient */
MatriceString::MatriceString(const MatriceString& mat1,const MatriceString& mat2)
    :tab(new TabString[mat1.size*mat2.size]),size(0),alloc(mat1.size*mat2.size),tailleFichier(0){
    unsigned long int k = 0;
    for (unsigned long int i = 0; i < mat1.size; i++)
        for(unsigned long int j = 0; j < mat2.size; j++) {
            tab[k] = TabString(mat1[i],mat2[j]);
            tailleFichier += tab[k].getTailleFichier();
            if (tailleFichier > 5000000000) {
                cerr << "Erreur Mémoire insufisante" << endl;
                cerr << "\ttaille en mémoire de la joiture : " << tailleFichier << " octets" <<endl;
                exit(1);
            }
            k++;
        }
    size = k;
}

MatriceString::~MatriceString(){
    if (tab != NULL) delete[] tab;
}

MatriceString &MatriceString::operator=(const MatriceString &t) {
    if (this!=&t) {
        /* Suppression de l'ancien Tableau */
        alloc = t.alloc;
        tailleFichier = t.tailleFichier;
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
unsigned long int MatriceString::getTailleFichier() const{
    return tailleFichier;
}
