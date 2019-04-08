#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> // std::transform
#include <cstdlib>
#include "table.h"
#include "tabtable.h"
#include "tabCondition.h" // pour la selection

using namespace std;

Table::Table()
{}
Table::Table(string fileName) {
    ifstream stream(fileName.c_str());
    if (stream) {   
        nomTable=Table::getFileName(fileName);
        /* Mise en miniscule */
        transform(nomTable.begin(), nomTable.end(), nomTable.begin(), ::tolower);
        
        /* Lire la premier ligne du fichier pour construire le tableau des noms des attributs */
        string line;
        getline(stream,line);
        nomAttributs = TabAttribut(nomTable,line);
        
        valeurAttributs = MatriceString(stream);
    } else {
        cerr << "Lecture du fichier '" << fileName << "' Impossible" << endl;
    }
}

Table::Table(const Table& tab1,const Table& tab2)
    :nomTable(tab1.nomTable+"JOIN"+tab2.nomTable),nomAttributs(tab1.nomAttributs,tab2.nomAttributs),valeurAttributs(tab1.valeurAttributs,tab2.valeurAttributs){

}

void Table::print() {
    size_t *tabMax= new size_t[nomAttributs.getSize()];
    size_t max,somme=0;
    string sep,space;
    for(size_t i= 0 ; i < nomAttributs.getSize(); ++i) {
        max = nomAttributs[i].size();
        for(size_t j=0 ; j < valeurAttributs.getSize();++j)
        {
            max = (valeurAttributs[j][i].size() < max ? max : valeurAttributs[j][i].size());
        }
        tabMax[i]=max;
        somme+=tabMax[i];
    }

    cout << endl;

    /* Affichages des noms des attributs*/
    cout << "| ";
    for(size_t i = 0; i < nomAttributs.getSize(); i++){
        cout << nomAttributs[i] ;
        space = string(tabMax[i]-nomAttributs[i].size() + 1,' ');
        cout << space <<" | " ;
    }
    cout << endl;
    /* affichage du séparateur */
    sep = string(somme+(nomAttributs.getSize()*4)+1,'-');
    cout << sep<< endl;
    /* Affichages des valeurs des attributs */
    for(size_t i = 0; i < valeurAttributs.getSize(); i++) {
        cout << "| ";
        for(size_t j = 0; j < valeurAttributs[i].getSize() ; j++){
            cout << valeurAttributs[i][j];
            space = string(tabMax[j]-valeurAttributs[i][j].size()+1,' ');
            cout << space << " | ";
        }
        cout << endl;
    }
    cout << sep << endl;
    delete[] tabMax;

}

string Table::getNomTable() const{
    return nomTable;
}

const TabAttribut& Table::getNomAttributs() const{
    return nomAttributs;
}
const MatriceString& Table::getValeurAttributs() const{
    return valeurAttributs;
}

Table Table::projection(TabAttribut attributs) const{
    
    if (attributs.get(0) == "*") // select * from ... where ...;
        return *this;
    else {
        /* Vérification des ambiguïté */
        for(unsigned long int i = 0; i < attributs.getSize(); i++) {
            int n_trouve = 0;
            for(unsigned long int j = 0; j < this->getNomAttributs().getSize(); j++) {
                if (attributs[i] == this->getNomAttributs()[j]) 
                    n_trouve++;
            }
            if (n_trouve > 1) {
                cerr << "Erreur dans la Requete SQL" << endl;
                cerr << "Il éxiste plusieurs '" << attributs[i] << "' dans les tables (ambiguïté)" << endl;
                cerr << "Veuillez préciser le nom de la table" << endl;
                exit(1);
            }
            if (n_trouve == 0) {
                cerr << "Erreur dans la Requete SQL" << endl;
                cerr << "Il n'éxiste pas '" << attributs[i] << "' dans les tables" << endl;
                exit(1);
            }
        }
        
        /* Si pas d'ambiguïté */
        Table tab;
        tab.nomTable=nomTable;
        tab.nomAttributs=attributs; // à modifier
        tab.valeurAttributs=MatriceString(valeurAttributs.getSize());
        for(unsigned long int i = 0; i < attributs.getSize(); i++) {
            if (nomAttributs.get(attributs[i]) == (unsigned long int)-1 ) { // attribut non trouvé
                cerr << "Attribut '" << attributs[i] << "' non trouver." << endl;
                exit(1);
            }
            else 
                tab.valeurAttributs.addColonne(valeurAttributs,nomAttributs.get(attributs[i]));
        }
        return tab;
    }
}
Table Table::selection(TabCondition condition) const{
    Table res; // la Table resultat
    res.nomTable = "Resultat Final";
    res.nomAttributs = this->nomAttributs; // Le même nom d'attribut
    /* Allocation de l'espace mémoire (plus que suffisant) */
    res.valeurAttributs = MatriceString(this->valeurAttributs.getSize());
    /* Parcours des valeurs */
    for(unsigned long int i = 0; i < this->valeurAttributs.getSize(); i++) {
        if (condition.verifier(this->valeurAttributs[i],res.nomAttributs)) {
            res.valeurAttributs.add(this->valeurAttributs[i]);
        }
    }
    /* Pensez à supprimer l'espace supplementaire alloué (if alloc >> size ) */
    return res;
}
Table Table::jointure(const Table& tab1,const Table& tab2) const{
    return Table(tab1,tab2);
}

/******
 * Get File Name from a Path with or without extension
 ******/
string Table::getFileName(string filePath, bool withExtension, char seperator) {
	/* Le dernier point trouvé */
	size_t point = filePath.rfind(".");
    size_t sepPos = filePath.rfind(seperator);
    // Séparateur trouver
	if(sepPos != string::npos)
        return filePath.substr(sepPos + 1,(withExtension || point == string::npos ? 1 : point) - sepPos -1);
    // Séparateur non trouver
    return filePath.substr(0,(withExtension || point == string::npos ? filePath.size() : point));
}

/*
 *  Affichage de la table sur un flux de sortie
*/
ostream& operator<<(ostream& stream,const Table& tab) {
    size_t *tabMax= new size_t[tab.getNomAttributs().getSize()];
    size_t max,somme=0;
    string sep,space;
    for(size_t i= 0 ; i < tab.getNomAttributs().getSize(); ++i) {
        max = tab.getNomAttributs()[i].size();
        for(size_t j=0 ; j < tab.getValeurAttributs().getSize();++j)
        {
            max = (tab.getValeurAttributs()[j][i].size() < max ? max : tab.getValeurAttributs()[j][i].size());
        }
        tabMax[i]=max;
        somme+=tabMax[i];
    }
    /* Affichages des noms des attributs*/
    stream << "| ";
    for(size_t i = 0; i < tab.getNomAttributs().getSize(); i++){
        stream << tab.getNomAttributs()[i] ;
        space = string(tabMax[i]-tab.getNomAttributs()[i].size() + 1,' ');
        stream << space <<" | " ;
    }
    stream << endl;
    /* affichage du séparateur */
    sep = string(somme+(tab.getNomAttributs().getSize()*4)+1,'-');
    stream << sep<< endl;
    /* Affichages des valeurs des attributs */
    for(size_t i = 0; i < tab.getValeurAttributs().getSize(); i++) {
        stream << "| ";
        for(size_t j = 0; j < tab.getValeurAttributs()[i].getSize() ; j++){
            stream << tab.getValeurAttributs()[i][j];
            space = string(tabMax[j]-tab.getValeurAttributs()[i][j].size()+1,' ');
            stream << space << " | ";
        }
        stream << endl;
    }
    stream << sep;
    delete[] tabMax;

    return stream;
}
