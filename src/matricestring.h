#ifndef MATRICE_STRING_H
#define MATRICE_STRING_H

#include "tabstring.h"

class MatriceString {
private:
    TabString* tab;
    unsigned long int size;
    unsigned long int alloc;
    unsigned long int tailleFichier;
public:
    MatriceString();
    MatriceString(std::ifstream& file);
    
    /* Allocation mémoire */
    MatriceString(unsigned long int);
    MatriceString(unsigned long int,unsigned long int);
    /* ------------------ */
    
    MatriceString(const MatriceString&);

    /* Produit cartésien */
    MatriceString(const MatriceString&,const MatriceString&);
    ~MatriceString();

    MatriceString &operator=(const MatriceString &tab);
    TabString &operator[](unsigned long int);
    const TabString &operator[](unsigned long int)const;

    void add(const TabString&);
    void addColonne(const MatriceString&,unsigned long int);
    unsigned long int getSize() const;
    unsigned long int getTailleFichier() const;


};

#endif
