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
    unsigned long int tailleFichier;

    static std::string getFileName(std::string, bool = false, char = '/');

public:
    Table();
    Table(std::string fileName);
    /* Produit cartésien */
    Table(const Table& tab1,const Table& tab2);

    /* Getteurs */
    std::string getNomTable() const;
    const TabAttribut& getNomAttributs() const;
    const MatriceString& getValeurAttributs() const;
    /* 
        Le nombre de caractère du fichier d'origine
        pour avoir une approximation sur la capacité de RAM utilisé lors de l'éxecution
    */
    unsigned long int getTailleFichier() const;

    void print();
    Table projection(TabAttribut attributs) const;
    Table selection(TabCondition condition) const;
    Table jointure(const Table& tab1,const Table& tab2) const;

    

};

std::ostream& operator<<(std::ostream&,const Table&);

#endif