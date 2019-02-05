#ifndef TABTABLE_H_
#def TABTABLE_H_

#include"table.h"

class TabTable {
private:
  Table tables[];
  unsigned long int size;
public:
  TabTable();

void add (std::string fileName);
Table& get (std::string nom);
unsigned long int getSize ();
};
#endif
