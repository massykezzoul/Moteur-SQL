#include <string>
#include <cstdlib>   // exit()
#include <algorithm> // std::transform
#include "requete.h"
#include "tabstring.h"

#include <iostream>

using namespace std;

void Requete::parseSelect(string sql) {
    string cle = "select";
    string *res;
    size_t debut = 0,fin = sql.size();

    debut = sql.find(cle);
    fin = sql.find("from");
    if (debut != string::npos && fin != string::npos) {
        debut += cle.size()+1;
        sql = sql.substr(debut,fin - debut);
        unsigned long int sizeSelect = TabString::strsplit(sql,res,',');
        select = TabString(res,sizeSelect);
    }
}
void Requete::parseFrom(string sql) {
    string cle = "from";
    string* res;
    size_t debut = 0,fin = sql.size();

    debut = sql.find(cle);
    fin = sql.find("where");
    if (debut != string::npos) {
        debut += cle.size()+1;
        sql = sql.substr(debut,fin-debut);
        unsigned long int sizeFrom = TabString::strsplit(sql,res,',');
        from = TabString(res,sizeFrom);
    }
}
void Requete::parseWhere(string sql) {
    string cle = "where";
    size_t debut = 0,fin = sql.size();
    debut = sql.find(cle);
    fin = sql.find(";");
    if (debut != string::npos) {
        debut += cle.size()+1;
        where = TabCondition(sql.substr(debut,fin - debut));
    } else {
        /* Pas de selection dans la requete SQL */
        where = TabCondition();
    }
}

string Requete::cleanLine(string ligne){
	string clean = ligne;

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

Requete::Requete():select(),from(),where(){}

Requete::Requete(string sql):select(),from(),where(){
    sql = cleanLine(sql);
    parseSelect(sql);
    parseFrom(sql);
    parseWhere(sql);
}

TabString &Requete::getSelect(){
    return select;
}

TabString &Requete::getFrom(){
    return from;
}

TabCondition &Requete::getWhere() {
    return where;
}