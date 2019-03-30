#include <iostream>
#include <cstdlib>
#include "tabtable.h"
#include "table.h"
#include "requete.h"
using namespace std;

TabTable::TabTable():tables(NULL),size(0){}

Table& TabTable::operator[](unsigned long int i) {
	if (i < 0 || i >= size) {
		cerr << "Out of range in TabTable" << endl;
		exit(1);
	}
	return tables[i];
}

const Table& TabTable::operator[](unsigned long int i) const{
	if (i < 0 || i >= size) {
		cerr << "Out of range in TabTable" << endl;
		exit(1);
	}
	return tables[i];
}

Table& TabTable::operator[](string nom) {
	for (unsigned long int i=0; i<getSize(); i++){
		if (tables[i].getNomTable()==nom)
			return tables[i];
	}
	cerr << "Table non trouvé" << endl;
	exit(1);
}

const Table& TabTable::operator[](string nom) const{
	for (unsigned long int i=0; i<getSize(); i++){
		if (tables[i].getNomTable()==nom)
			return tables[i];
	}
	cerr << "Table non trouvé" << endl;
	exit(1);
}

void TabTable::add (string fileName){
	size++;

	Table *copie= new Table[size];
	
	for (unsigned long int i=0; i<(size-1) ;i++)
	{
		copie[i]=tables[i];
	}
	
	copie[size-1]=Table(fileName);

	delete[] tables;
	tables=copie;
}

void TabTable::add(const char* fileName) {
	string file(fileName);
	add(file); 
}

Table& TabTable::get(string nom) const{
	for (unsigned long int i=0; i<getSize(); i++){
		if (tables[i].getNomTable()==nom)
			return tables[i];
	}
	cerr << "Table non trouvé" << endl;
	exit(1);
}

Table& TabTable::get(unsigned long int i) const{
	if (i < 0 || i >= size) {
		cerr << "Out of range in TabTable" << endl;
		//	return Table();
	}
	return tables[i];
}

bool TabTable::existe(string nom) const {
	for (unsigned long int i=0; i<getSize(); i++){
		if (tables[i].getNomTable()==nom)
			return true;
	}
	return false;
}

unsigned long int TabTable::getSize ()const {
	return size;
}

/* Executer la requete SQL */
Table TabTable::executer(const Requete &sql) const {
        /* La Table final */
        Table res;

        /* execution des jointures (à ameliorer !!) */
        TabString join = sql.getFrom();
        if (join.getSize() > 1) {
            /* Si jointure il y'a (au moin deux tables apres le FROM) */
            if (!this->existe(join[0])) {
                cerr << "La Table '"<<join[0] << "' n'existe pas" << endl;
                exit(1);
            }
            if (!this->existe(join[1])) {
                cerr << "La Table '"<<join[1] << "' n'existe pas" << endl;
                exit(1);
            }
            res = Table(get(join[0]),get(join[1]));
            for(unsigned long int i = 2; i < join.getSize(); i++) {
                if (this->existe(join[i]))
                    res = Table(res,get(join[i]));
                else {
                    cerr << "La Table '"<<join[i] << "' n'existe pas" << endl;
                    exit(1);
                }
            }
        } else {
            if (this->existe(join[0]))
                res = get(join[0]);
            else {
                cerr << "La Table '"<<join[0] << "' n'existe pas" << endl;
                exit(1);
            }
        }
        /* Execution de la selection */
        if (sql.getWhere().getSize() > 0)
            res = res.selection(sql.getWhere());

        /* Execution de la projection */
        res = res.projection(sql.getSelect());

        /* Retourner le resultat */
        return res;
}