#include <iostream>
#include <string>
#include <cstdlib>   // exit()
#include <algorithm> // std::transform
#include "requete.h"
#include "tabstring.h"

using namespace std;

void Requete::parseSelect(string sql) {
    string cle = "select";
    unsigned int debut = 0,fin = sql.size();
    debut = sql.find(cle);
    fin = sql.find("from");
    if (debut != string::npos && fin != string::npos) {
        debut += cle.size()+1;
        sql = sql.substr(debut,fin - debut);
        sizeSelect = TabString::strsplit(sql,select,',');
    }
}
void Requete::parseFrom(string sql) {
    string cle = "from";
    unsigned int debut = 0,fin = sql.size();
    debut = sql.find(cle);
    fin = sql.find("where");
    if (debut != string::npos) {
        debut += cle.size()+1;
        sql = sql.substr(debut,fin-debut);
        sizeFrom = TabString::strsplit(sql,from,',');
    }
}
void Requete::parseWhere(string sql) {
    string cle = "where";
    unsigned int debut = 0,fin = sql.size();
    debut = sql.find(cle);
    fin = sql.find(";");
    if (debut != string::npos) {
        debut += cle.size()+1;
        if (fin != string::npos) fin--;
        where = sql.substr(debut,fin);
    }
}

string Requete::cleanLine(string ligne){
	string clean = ligne;
	// Suppression des commentairess
	//clean = clean.substr(0,clean.find_first_of("#"));
    
	//supprimer les espaces en plus et les tabulations
	//supprimer les espaces et les tabulations en debut de chaine
	while ((clean[0] == ' ') || (clean[0] == '\t'))
		clean.erase(0,1);
    

	//supprimer les espaces et les tabulations en mileux de chaine
	unsigned int i = 1;
	while (i < clean.size()) {
		if ((clean[i] == ' ') && (clean[i-1] == ' '))
	        clean.erase(i,1);
		else if (clean[i] == '\t') // remplace les tabulation au milieu par un espace
        	clean[i] = ' ';
		else
	        ++i;
	}
    

	//suprimer les espaces et les tabulations en fin de chaine 
	while ((clean[clean.size()-1] == ' ') || (clean[clean.size()-1] == '\t'))
		clean.erase(clean.size()-1,1);
    

	transform(clean.begin(), clean.end(), clean.begin(), ::tolower);
    
	return clean;
}

Requete::Requete():select(NULL),sizeSelect(0),from(NULL),sizeFrom(0),where(){}

Requete::Requete(string sql):select(NULL),sizeSelect(0),from(NULL),sizeFrom(0),where(){
    sql = cleanLine(sql);
    parseSelect(sql);
    parseFrom(sql);
    parseWhere(sql);
}

Requete::Requete(const Requete& req){
    /* Copie des attributs static */
    sizeSelect = req.sizeSelect;
    sizeFrom = req.sizeFrom;
    where = req.where;
    /* allocation de l'espace mémoire pour les attributs dynamique*/
    select = new string[sizeSelect];
    from = new string[sizeFrom];
    /* Copie des élement dynamique */
    for(unsigned int i = 0; i < sizeSelect; i++)
        select[i] = req.select[i];
    for(unsigned int i = 0; i < sizeFrom; i++)
        from[i] = req.from[i];
}

Requete::~Requete(){
    if (select != NULL) delete[] select;
    if (from != NULL) delete[] from;    
}
Requete& Requete::operator=(const Requete& req){
    if (this != &req) {
        /* Les attributs statique*/
        sizeSelect = req.sizeSelect;
        sizeFrom = req.sizeFrom;
        where = req.where;
        /* Suppression des ancien élement dynamique et réallocation */
        if (select != NULL) delete[] select;
        if (from != NULL) delete[] from;
        select = new string[sizeSelect];
        from = new string[sizeFrom];
        /* Copie des elements */
        for(unsigned int i = 0; i < sizeSelect; i++)
            select[i] = req.select[i];
        for(unsigned int i = 0; i < sizeFrom; i++)
            from[i] = req.from[i];
    }
    return *this;
}

string Requete::getSelect(unsigned int i)const{
    if (i < 0 || i >= sizeSelect)
        exit(1);
    return select[i];
}
unsigned int Requete::getSizeSelect()const{
    return sizeSelect;
}
string Requete::getFrom(unsigned int i)const{
    if (i < 0 || i >= sizeFrom)
        exit(1);
    return from[i];
}
unsigned int Requete::getSizeFrom()const{
    return sizeFrom;
}
string Requete::getWhere() const{
    return where;
}