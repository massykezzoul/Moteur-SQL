#include "tabAttribut.h"
#include "tabstring.h"



    TabAttribut::TabAttribut():table(NULL),size(0),alloc(0){

    }
    TabAttribut::TabAttribut(string nomTable,string line):table(NULL),size(0),alloc(0)
    {
        strng *tab = NULL;
        
        size = TabString::strsplit2(line,tab,',');
        if (size == 0) {
            cerr << "Erreur dans Strsplit (size == 0)" << endl;
            exit(1);
        }
        alloc = size;
        table = new NomAttribut[alloc]; 
        for(unsigned long int  i = 0; i < size; i++)
        {
            table[i]=nomAtrribut(nomTable,tab[i]);
        }
        
    } 
    TabAttribut::TabAttribut(unsigned long int):table(new NomAttribut[i]),size(0),alloc(0){
    }// allouer 
    TabAttribut::TabAttribut(NomAttribut*& str,unsigned long int taille):table(new NomAttribut[taille]),size(taille),alloc(taille){
       unsigned long int j=0;
        for(unsigned long int i = 0; i < taille; i++)
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
    size = tab.size;
    alloc = tab.alloc;
    table = new NomAttribut[alloc];
    /*on copie les elements*/
    for (unsigned long int i = 0 ; i<size ; ++i)
    {
        table[i]=tab.table[i];
    }
    }
    TabAttribut::TabAttribut(const TabAttribut&,const TabAttribut&):table(new string[tab1.size+tab2.size]),size(0),alloc(tab1.size+tab2.size){
        /*on copie les elements*/
    unsigned long int i = 0;
    for (i = 0 ; i<tab1.size ; ++i)
        add(tab1[i]);

    for(unsigned long int j = 0; j < tab2.size; j++)
        add(tab2[j]);
    } // projection 
    TabAttribut::~TabAttribut(){
        if(table!=NULL) delete[] table;
    }

    TabAttribut &TabAttribut::operator=(const TabAttribut &tab){

    if(this!=&tab)
    {
        /* Réallocation si espace insufisant */
        alloc = tab.alloc;
        /*on supprime l'ancien tableau*/
        if (table != NULL) delete[] table;
        table = new NomAttribut[alloc];
        
        size = tab.size;
        
        /*on copie les elements*/
        for(unsigned long int i = 0 ; i < size ; ++i)
        {
            table[i]=tab[i];
        }
    }
    
    return *this;
    }
    TabAttribut &TabAttribut::operator+=(const TabAttribut &tab){
         for(unsigned long int i = 0; i < tab.size; i++)
        add(tab[i]);
    return *this;
    }
    string &TabAttribut::operator[](unsigned long int){
         if (i < 0 || i >= size) {
        cerr << "Out of Range in TabString: "<<i<< endl;
        exit(1);
    }
    return table[i].getAttribut();
    }
    const NomAttribut &TabAttribut::operator[](unsigned long int) const{
         if (i < 0 || i >= size) {
        cerr << "Out of Range in TabString: "<<i<< endl;
        exit(1);
    }
    return table[i].getAttribut();
    }


    void TabAttribut::add(const NomAttribut& str){
        if (size >= alloc) {
        /* Création d'un nouvelle espace mémoire */
        if (alloc > 0) alloc *= 2; else alloc = 2;
        NomAttribut* copie = new NomAttribut[alloc];
        /* Copie des elements */
        for(unsigned long int i = 0; i < size; i++)
            copie[i] = table[i];
        if (table != NULL) delete[] table;
        table = copie;
    }
    table[size++] = str;
    

    }

    unsigned long int TabAttribut::get(NomAttribut attr) const {
         unsigned long int i=0;
    while(i<size)
    {
        if(table[i]==attr) return i;
        i++;
    }
    return -1;
    }
    
    NomAttribut TabAttribut::get(unsigned long int i)const{
        return table[i];
    
    
    unsigned long int TabAttribut::getSize() const{
        return size;
    }
    