#ifndef CONDITION_H
#define CONDITION_H

enum Operateur {
    EQUAL,      // Égalité '='
    NOTEQUAL    // Difference '!=' || '<>'
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

enum TypeCondition {
    VAL,        // Entre un attribut et une valeur
    ATTRIBUT,   // Entre deux attribut
    NOTHING
};

class Condition;

#endif