#ifndef NOMATTRIBUT_H
#define NOMATTRIBUT_H

#include <string>

class NomAttribut {
private:
    std::string nomTable;
    std::string nomAttribut;
public:
    NomAttribut(std::string,std::string);
    NomAttribut();

    std::string getTable() const;
    std::string getAttribut() const;

    bool operator==(NomAttribut) const;
    void operator=(NomAttribut);
    

};

#endif