#ifndef TABATTRIBUT_H_
#define TABATTRIBUT_H_

#include "nomAttribut.h"
#include <string>

class TabAttribut {
private:
    NomAttribut *table; 
    unsigned long int size; 
    unsigned long int alloc;
public:
    TabAttribut();
    TabAttribut(std::string,std::string); 
    TabAttribut(unsigned long int);// allouer 
    TabAttribut(std::string*& str,unsigned long int i);
    TabAttribut(const TabAttribut &tab);
    TabAttribut(const TabAttribut&,const TabAttribut&); // projection 
    ~TabAttribut();

    TabAttribut &operator=(const TabAttribut &tab);
    TabAttribut &operator+=(const TabAttribut &tab);
    NomAttribut &operator[](unsigned long int);
    const NomAttribut &operator[](unsigned long int) const;


    void add(const NomAttribut& str);

    unsigned long int get(NomAttribut str) const ;
    NomAttribut get(unsigned long int i) const;
    unsigned long int getSize() const;

};

#endif