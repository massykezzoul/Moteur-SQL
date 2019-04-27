#include <iostream>
#include <cstdlib> // for atoi()
#include <string>
#include <sstream> // for istringstream
#include "condition.h"
#include "tabstring.h" // for strsplit()
#include "requete.h" // for cleanLine();
#include "date.h" // for Date
using namespace std;

Operateur strToOperateur(string s) {
    if (s == "=")
        return EQUAL;
    if (s == "!=")
        return NOTEQUAL;
    if (s == "<>")
        return NOTEQUAL;
    if (s == ">")
        return GTHAN;
    if (s == "<")
        return LTHAN;
    if (s == ">=")
        return GOREQUAL;
    if (s == "<=")
        return LOREQUAL;
    return NOTHING;
}

string operateurToStr(Operateur s) {
    if (s == EQUAL)
        return "=";
    if (s == NOTEQUAL)
        return "!=";
    if (s == GTHAN)
        return ">";
    if (s == LTHAN)
        return "<";
    if (s == GOREQUAL)
        return ">=";
    if (s == LOREQUAL)
        return "<=";
    return "NOTHING";
}
template <typename T>
bool operation(T op1,Operateur op,T op2) {
    switch (op)
    {
        case EQUAL:
            return op1 == op2;
            break;
        case NOTEQUAL:
            return op1 != op2;
            break;
        case GTHAN:
            return op1 > op2;
        case LTHAN:
            return op1 < op2;
            break;
        case GOREQUAL:
            return op1 >= op2;
            break;
        case LOREQUAL:
            return op1 <= op2;
            break;
        default:
            return false;
            break;
    }
}

Condition::Condition():operande1(""),operateur(NOTHING),operande2(""){}

Condition::Condition(string str) {
    str = Requete::cleanLine(str);
    size_t space1 = str.find_first_of("<>=! ");
    size_t space2 = str.find_last_of("=<>!")+1;
    operateur = strToOperateur(Requete::cleanLine(str.substr(space1,space2-space1)));
    if (space1 > str.size() || space2 > str.size() || operateur == NOTHING) {
        cerr << "Syntaxe error on : \"" << str << "\"" << endl;
        cerr << "space1 > str.size() : " << (space1 > str.size()) << endl;
        cerr << "space2 > str.size() : " <<( space2 > str.size() )<< endl;
        cerr << "operateur == NOTHING : " << (operateur == NOTHING) << endl;
        exit(1);
    }
    operande1 = Requete::cleanLine(str.substr(0,space1));
    operande2 = Requete::cleanLine(str.substr(space2));

    type = (Condition::isVal(operande2)?VAL:ATTRIBUT);

}

string Condition::getOp1() const {
  return operande1;
}

string Condition::getOp2() const {
  return operande2;
}

string Condition::getOperateur() const {
    return operateurToStr(operateur);
}


TypeCondition Condition::getType()const {
    return type;
}

string Condition::toString()const {
    return operande1 + " " + operateurToStr(operateur) + " " + operande2;
}

bool Condition::verifier(const TabString &line,unsigned long int iAtt,unsigned long int iVal) const {
    if (type == VAL || iVal > line.getSize() || iVal < 0) {
        /* Le 2éme operande est une valeur */
        if (isFloat(line[iAtt]) && isFloat(operande2) )
            return operation<float>(atof(line[iAtt].c_str()),operateur,atof(operande2.c_str()));
        else if (Date::isDate(line[iAtt]) && Date::isDate(operande2))
            return operation<Date>(Date(line[iAtt]),operateur,Date(operande2));
        else 
            return operation<string>(line[iAtt],operateur,operande2.substr(1,operande2.size()-2));        
    }
    else {
        if (isFloat(line[iAtt]) && isFloat(line[iVal]) )
            return operation<float>(atof(line[iAtt].c_str()),operateur,atof(line[iVal].c_str()));
        else if (Date::isDate(line[iAtt]) && Date::isDate(line[iVal]))
            return operation<Date>(Date(line[iAtt]),operateur,Date(line[iVal]));
        else 
            return operation<string>(line[iAtt],operateur,line[iVal]);        
    }
}


bool Condition::isVal(string operande) {
    return atof(operande.c_str()) ||    // type float
        Date::isDate(operande) ||       // type date
        (operande[0]=='\'' && operande[operande.size()-1]=='\'') ||  // type string 'xxxxx'
        (operande[0]=='\"' && operande[operande.size()-1]=='\"');    // type string "xxxxx"
}

/* thanks Stackoverflow */
bool Condition::isFloat(string myString ) {
    istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}
