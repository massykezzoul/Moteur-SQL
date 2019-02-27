#ifndef TABCONDITION_H_
#define TABCONDITION_H_
#include<string>
#include "tabstring.h"

#include "condition.h"
enum OpLogique{
    AND,
    OR,
    NO
};
class TabCondition
{
private:
Condition *tab; 
OpLogique *oplogique; 
unsigned int size;


public:
TabCondition();
TabCondition(std::string);
bool verifier(TabString,TabString);
unsigned int getSize() const;
unsigned int getSizeOp()const;
Condition getCond(unsigned int i)const;
OpLogique getOpL(unsigned int i)const ;

};








#endif