#ifndef TABLE_H_
#define TABLE_H_

#include "tabAttribut.h"
#include "matricestring.h"

class TabTable;
class TabCondition;

class Table
{
private:
    std::string nomTable;
    TabAttribut nomAttributs;
    MatriceString valeurAttributs;

    static std::string getFileName(std::string, bool = false, char = '/');

public:
    Table();
    Table(std::string fileName);
    Table(const Table& tab1,const Table& tab2);
    std::string getNomTable() const;
    const TabAttribut& getNomAttributs() const;
    const MatriceString& getValeurAttributs() const;

    void print(); 
    Table projection(TabAttribut attributs) const;
    Table selection(TabCondition condition) const;
    Table jointure(const Table& tab1,const Table& tab2) const;


};

std::ostream& operator<<(std::ostream&,const Table&);

#endif