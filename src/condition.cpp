#include <iostream>
#include <cstdlib> // for atoi()
#include <string>
#include <sstream> // for istringstream
#include "condition.h"
#include "tabstring.h" // for strsplit()

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

bool operation(string op1,Operateur op,string op2) {
    /*
        Faudrait traiter les types de données
    */
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

bool Condition::isVal(string operande)const {
    return atof(operande.c_str()) || operande[0] == '\"' || Condition::isDate(operande);
}

/* thanks Stackoverflow */
bool Condition::isFloat( string myString ) {
    istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}
bool Condition::isDate(string date) {
    string* split;
    if (TabString::strsplit(date,split,'/') == 3) {
        return atoi(split[0].c_str()) > 0 && atoi(split[1].c_str()) > 0 && atoi(split[2].c_str()) > 0;
    }
    return false;
}

Condition::Condition():operande1(),operateur(NOTHING),operande2(){}

Condition::Condition(string str) {
    size_t space1 = str.find_first_of(' ');
    size_t space2 = str.find_first_of(' ',space1+1);
    operateur = strToOperateur(str.substr(space1+1,space2-space1-1));
    if (space1 > str.size() || space2 > str.size() || operateur == NOTHING) {
        cerr << "Syntaxe error on : \"" << str << "\"" << endl;
        exit(1);
    }
    operande1 = str.substr(0,space1);
    operande2 = str.substr(space2+1);

    type = (isVal(operande2)?VAL:ATTRIBUT);
}

string Condition::getOp1() const {
  return operande1;
}

string Condition::getOp2() const {
  return operande2;
}

bool Condition::verifier(const TabString &line,unsigned long int iAtt,unsigned long int iVal) const {
    if (type == VAL || iVal > line.getSize())
        return operation(line[iAtt],operateur,operande2);
    else
        return operation(line[iAtt],operateur,line[iVal]);
}
