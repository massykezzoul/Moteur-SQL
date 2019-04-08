#include <iostream>
#include <cstdlib>
#include "tabAttribut.h"
#include "tabstring.h"

using namespace std;

    TabAttribut::TabAttribut():table(NULL),size(0),alloc(0){

    }
    TabAttribut::TabAttribut(string nomTable,string line):table(NULL),size(0),alloc(0)
    {
        string *tab = NULL;
        
        size = TabString::strsplit2(line,tab,',');
        if (size == 0) {
            cerr << "Erreur dans Strsplit (size == 0)" << endl;
            exit(1);
        }
        alloc = size;
        table = new NomAttribut[alloc]; 
        for(size_t i = 0; i < size; i++)
        {
            table[i] = NomAttribut(nomTable,tab[i]);
        }
        
    } 
    TabAttribut::TabAttribut(unsigned long int i):table(new NomAttribut[i]),size(0),alloc(0){
    }// allouer 
    TabAttribut::TabAttribut(string*& str,unsigned long int taille):table(new NomAttribut[taille]),size(taille),alloc(taille){
       int j=0;
        for(size_t i = 0; i < taille; i++)
        {
          j=str[i].find_first_of(".");
            if (j>taille)
                table[i] = NomAttribut("",str[i]);
            else {
                table[i] = NomAttribut(str[i].substr(0,j),str[i].substr(j+1));
            }   
        }
        
    }
    TabAttribut::TabAttribut(const TabAttribut &tab){

    }
    TabAttribut::TabAttribut(const TabAttribut&,const TabAttribut&){

    } // projection 
    TabAttribut::~TabAttribut(){

    }

    TabAttribut &TabAttribut::operator=(const TabAttribut &tab){

    }
    TabAttribut &TabAttribut::operator+=(const TabAttribut &tab){

    }
    NomAttribut &TabAttribut::operator[](unsigned long int){

    }
    const NomAttribut &TabAttribut::operator[](unsigned long int) const{

    }


    void TabAttribut::add(const NomAttribut& str){

    }

    unsigned long int TabAttribut::get(NomAttribut str) const {

    }
    NomAttribut TabAttribut::get(unsigned long int i) const{

    }
    unsigned long int TabAttribut::getSize() const{

    }
    