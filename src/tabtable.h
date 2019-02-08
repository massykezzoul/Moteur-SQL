#ifndef TABTABLE_H_
#define TABTABLE_H_

#include"table.h"

class TabTable {
private:
	Table* tables;
	unsigned long int size;
public:
	TabTable();

	void add(std::string fileName);
	void add(const char*);
	Table* get(std::string nom) const;
	Table* get(unsigned long int) const;
	unsigned long int getSize() const;
};

#endif