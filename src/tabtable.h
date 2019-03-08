#ifndef TABTABLE_H_
#define TABTABLE_H_

class Table;

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
	bool existe(std::string) const; // renvoie vrai si la table (donnée avec son nom) existe dans le tableau
	unsigned long int getSize() const;
};

#endif