#ifndef TABSTRING_H_
#define TABSTRING_H_

#include <string>
#include <fstream>

class TabString {
private:
    std::string *table; 
    unsigned int size; 

public:
    TabString();
    TabString(std::ifstream &file); 
    TabString(const TabString &tab);
    ~TabString();

    TabString &operator=(const TabString &tab);

    void add(std::string str);
    unsigned int get(std::string str) const ;
    std::string get(unsigned int i) const;
    unsigned int size() const;
};

#endif