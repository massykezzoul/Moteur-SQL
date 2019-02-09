#ifndef TABLE_H_
#define TABLE_H_

#include "tabstring.h"
#include "matricestring.h"
class TabTable;

class Table
{
private:
    std::string nomTable;
    TabString nomAttributs;
    MatriceString valeurAttributs;

    static std::string getFileName(std::string, bool = false, char = '/');

public:
    Table();
    Table(std::string fileName);
    Table(const Table& tab1,const Table& tab2);
    std::string getNomTable() const;
    const TabString& getNomAttributs() const;
    const MatriceString& getValeurAttributs() const;

    void print(); 
    Table projection(TabString attributs) const;
    Table selection(std::string condition) const;
    Table jointure(const Table& tab1,const Table& tab2) const;
    void jointure(const TabTable& tab);


};

std::ostream& operator<<(std::ostream&,const Table&);

#endif