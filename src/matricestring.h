#ifndef MATRICE_STRING_H
#define MATRICE_STRING_H

#include "tabstring.h"

class MatriceString {
private:
    TabString* tab;
    unsigned long int size;
    unsigned long int alloc;

public:
    MatriceString();
    MatriceString(std::ifstream& file);
    MatriceString(unsigned long int);
    MatriceString(unsigned long int,unsigned long int);
    MatriceString(const MatriceString&);
    //MatriceString(const MatriceString&,const TabString&);

    MatriceString(const MatriceString&,const MatriceString&);
    ~MatriceString();

    MatriceString &operator=(const MatriceString &tab);
    TabString &operator[](unsigned long int);
    const TabString &operator[](unsigned long int)const;

    void add(const TabString&);
    void addColonne(const MatriceString&,unsigned long int);
    unsigned long int getSize() const;


};

#endif
