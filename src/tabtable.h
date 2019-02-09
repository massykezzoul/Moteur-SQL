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
	Table operator[](unsigned long int) const;

	void add(std::string fileName);
	void add(const char*);
	Table& get(std::string nom) const;
	Table& get(unsigned long int) const;
	unsigned long int getSize() const;
};

#endif