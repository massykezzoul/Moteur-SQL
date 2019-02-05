#include<iostream>
#include "table.h"
#include<fstream>
#include<cstdlib>
using namespace std; 



    Table::Table()
    {}

    Table::Table(string fileName)
    {

        ifstream stream(fileName.c_str());
        if (stream)
        {
            nomTable=fileName;
            nomAttributs = TabString(stream);
            valeurAttributs = MatriceString(stream);

        }
        else 
        exit(1);
    }
    void Table::print()
    {
        /* Affichages des nom des attributs*/            
        for(size_t i = 0; i < nomAttributs.getSize(); i++)
            cout << nomAttributs.get(i) << " | ";
        cout << endl << endl;
        /* Affichages des valeurs des attributs */
        for(size_t i = 0; i < valeurAttributs.getSize(); i++) {
            for(size_t j = 0; j < valeurAttributs.get(i).getSize() ; j++)
                cout << valeurAttributs.get(i).get(j) << " | ";
            cout << endl;
        } 
    }
    string Table::getNomTable(){return nomTable;}

    Table &Table::projection(TabString attributs)
    {

    }
    Table &Table::selection(string condition)
    {

    }
    Table &Table::jointure(const Table& tab1,const Table& tab2)
    {

    }
