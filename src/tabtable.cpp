#include <iostream>
#include <cstdlib>
#include "tabtable.h"

using namespace std;

TabTable::TabTable():tables(NULL),size(0){}

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

Table* TabTable::get(string nom) const{
	for (unsigned long int i=0; i<getSize(); i++){
		if (tables[i].getNomTable()==nom)
			return tables + i;
	}
	cerr << "Table non trouvé" << endl;
	return NULL;
}

unsigned long int TabTable::getSize ()const {
	return size;
}
