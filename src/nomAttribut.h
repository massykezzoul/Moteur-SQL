#ifndef NOMATTRIBUT_H
#define NOMATTRIBUT_H

#include <string>

class NomAttribut {
private:
    std::string nomTable;
    std::string nomAttribut;
public:
    NomAttribut(std::string,std::string);
    NomAttribut(std::string);
    NomAttribut();

    const std::string& getTable() const;
    const std::string& getAttribut() const;

    std::string& getTable();
    std::string& getAttribut();

    bool operator==(NomAttribut) const;
    void operator=(NomAttribut);
    

};

#endif