#include<iostream>
#include<fstream>
#include <sstream>
#include<cstdlib>
#include "table.h"
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
        size_t *tabMax= new size_t[nomAttributs.getSize()];
        size_t max,somme=0;
        string sep,space;
        for(size_t i= 0 ; i < nomAttributs.getSize(); ++i)
        {
            max = nomAttributs.get(i).length();
            for(size_t j=0 ; j < valeurAttributs.getSize();++j)
            {
                max = (valeurAttributs.get(j).get(i).length() < max ? max : valeurAttributs.get(j).get(i).length()); 
            }
            tabMax[i]=max;
            somme+=tabMax[i];
        }

        cout << endl;
    
        /* Affichages des noms des attributs*/
        cout << "| ";        
        for(size_t i = 0; i < nomAttributs.getSize(); i++){
            cout << nomAttributs.get(i) ;
            space = string(tabMax[i]-nomAttributs.get(i).length() + 1,' ');
            cout << space <<" | " ;
        }
        cout << endl;
        /* affichage du séparateur */
        sep = string(somme+(nomAttributs.getSize()*4)+1,'-');
        cout << sep<< endl;

        /* Affichages des valeurs des attributs */
        for(size_t i = 0; i < valeurAttributs.getSize(); i++) {
            cout << "| ";
            for(size_t j = 0; j < valeurAttributs.get(i).getSize() ; j++){
                cout << valeurAttributs.get(i).get(j);
                space = string(tabMax[j]-valeurAttributs.get(i).get(j).length()+1,' ');
                cout << space << " | ";
            }
            cout << endl;
        }
        cout << sep << endl;

        delete[] tabMax;
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
