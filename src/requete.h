#ifndef _REQUETE__H_
#define _REQUETE__H_

#include "tabstring.h"

class Requete {
private:
    TabString select;
    TabString from;
    std::string where;

    void parseSelect(std::string);
    void parseFrom(std::string);
    void parseWhere(std::string);

    static std::string cleanLine(std::string);

public:
    Requete();
    Requete(std::string);

    TabString &getSelect();
    TabString &getFrom();
    std::string &getWhere();
};

#endif