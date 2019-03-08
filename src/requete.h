#ifndef _REQUETE__H_
#define _REQUETE__H_

#include "tabstring.h"
#include "tabCondition.h"

class Requete {
private:
    TabString select;
    TabString from;
    TabCondition where;

    void parseSelect(std::string);
    void parseFrom(std::string);
    void parseWhere(std::string);

public:
    Requete();
    Requete(std::string);

    const TabString &getSelect() const;
    const TabString &getFrom() const;
    const TabCondition &getWhere() const;

    static std::string cleanLine(std::string);

};

#endif