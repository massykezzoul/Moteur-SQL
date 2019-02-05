#ifndef MATRICE_STRING_H
#define MATRICE_STRING_H

#include "tabstring.h"

class MatriceString {
private:
    TabString* tab;
    unsigned long int size;
    
public:
    MatriceString();
    MatriceString(std::ifstream& file);
    MatriceString(const MatriceString&);
    ~MatriceString();

    void add(const TabString&);
    TabString &get(unsigned long int) const;
    unsigned long int getSize() const;

};

#endif