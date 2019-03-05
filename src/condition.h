#ifndef CONDITION_H
#define CONDITION_H

#include <string>
class TabString;

enum Operateur {
    EQUAL,      // Égalité '='
    NOTEQUAL,    // Difference '!=' || '<>'
    GTHAN,      // Supérieur strictement '>'
    LTHAN,      // Inférieur strictement '<'
    GOREQUAL,   // Supérieur ou égal '>='
    LOREQUAL,   // Inférieur ou égal '<='
    NOTHING
};

Operateur strToOperateur(std::string);
/*
    Convertir une chaine en un Operateur
*/
bool operation(std::string,Operateur,std::string);
/*
    Retourne le resultat de l'operation (Logique) entre deux operande
*/

std::string operateurToStr(Operateur);


enum TypeCondition {
    VAL,        // Entre un attribut et une valeur
    ATTRIBUT,   // Entre deux attribut
    NONE
};

class Condition {
private:
    std::string operande1;
    Operateur operateur;
    std::string operande2;
    TypeCondition type;

    bool isVal(std::string) const; // Retourne vrai si c'est une valeur (chaine ou int ...)

public:
    Condition();
    Condition(std::string);

    std::string getOp1() const;
    std::string getOp2() const;
    std::string getOperateur() const;
    TypeCondition getType() const;
    std::string toString() const;

    bool verifier(const TabString&,unsigned long int,unsigned long int = -1) const;

    /* thanks Stackoverflow */
    bool static isFloat(std::string);
    bool static isDate(std::string);

};

#endif
