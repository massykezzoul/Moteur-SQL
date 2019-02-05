#include<iostream>
#include "table.h"
#include<fstream>
#include<cstdlib>
#include <unistd.h>
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
        for(size_t i= 0 ; i < nomAttributs.getSize(); ++i)
        {
            max = nomAttributs.get(i).size();
            for(size_t j=0 ; j < valeurAttributs.getSize();++j)
            {
                max = (valeurAttributs.get(j).get(i).size() < max ? max : valeurAttributs.get(j).get(i).size()); 
            }
            tabMax[i]=max;
            somme+=tabMax[i];
        }
        cout << somme;

        for(size_t i = 0; i < nomAttributs.getSize(); i++){
            cout << tabMax[i] << " " ;
        }
        cout << endl;
        //usleep(500000);
        
    
        /* Affichages des nom des attributs*/
        cout << "| ";        
        for(size_t i = 0; i < nomAttributs.getSize(); i++){
            cout << nomAttributs.get(i) ;
            for (size_t k =0 ; k < tabMax[i]-nomAttributs.get(i).size() + 1;++k) {
                cout<< " ";
            }
            cout << " | " ;
        }
        cout << endl;
        /* affichage du séparateur */
        for(size_t i = 0; i < somme+nomAttributs.getSize()*4+1; i++) {
            cout << "-";
        }
        cout << endl;
        /* Affichages des valeurs des attributs */
        for(size_t i = 0; i < valeurAttributs.getSize(); i++) {
            cout << "| ";
            for(size_t j = 0; j < valeurAttributs.get(i).getSize() ; j++){
                cout << valeurAttributs.get(i).get(j);
                for (size_t k =0 ; k < tabMax[j]-valeurAttributs.get(i).get(j).size()+1;++k){
                    cout << " ";
                }
                cout << " | ";
            }
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
