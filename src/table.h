#ifndef TABLE_H_
#define TABLE_H_
#include "tabstring.h"
#include "matricestring.h"


class Table
{
private:
    std::string nomTable;
    TabString nomAttributs;
    MatriceString valeurAttributs;

public:
    Table();
    Table(std::string fileName);
    std::string getNomTable();
    void print(); 
    Table &projection(TabString attributs);
    Table &selection(std::string condition);
    Table &jointure(const Table& tab1,const Table& tab2);


    static std::string getFileName(std::string, bool = false, char = '/');


};





#endif
