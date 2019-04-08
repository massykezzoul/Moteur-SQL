#ifndef _REQUETE__H_
#define _REQUETE__H_

#include "tabstring.h"
#include "tabCondition.h"
#include "tabAttribut.h"

class Requete {
private:
    TabAttribut select;
    TabString from;
    TabCondition where;

    void parseSelect(std::string);
    void parseFrom(std::string);
    void parseWhere(std::string);

public:
    Requete();
    Requete(std::string);

    const TabAttribut &getSelect() const;
    const TabString &getFrom() const;
    const TabCondition &getWhere() const;

    static std::string cleanLine(std::string);

};

#endif