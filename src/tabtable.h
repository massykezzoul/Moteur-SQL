#ifndef TABTABLE_H_
#define TABTABLE_H_

class Table;
class Requete;

class TabTable {
private:
	Table* tables;
	unsigned long int size;
public:
	TabTable();
	Table& operator[](unsigned long int);
	const Table& operator[](unsigned long int) const;

	Table& operator[](std::string);
	const Table& operator[](std::string) const;

	void add(std::string fileName);
	void add(const char*);
	Table& get(std::string nom) const;
	Table& get(unsigned long int) const;
	/* renvoie vrai si la table (donnée avec son nom) existe dans le tableau */
	bool existe(std::string) const;
	unsigned long int getSize() const;
	/* Execute la requete SQL donnée en paramétre et retourne le resultat final */
	Table executer(const Requete&) const;
};

#endif