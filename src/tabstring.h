#ifndef TABSTRING_H_
#define TABSTRING_H_

#include <string>
#include <fstream>

class TabString {
private:
    std::string *table; 
    unsigned long int size; 

public:
    TabString();
    TabString(std::ifstream &file); 
    TabString(const TabString &tab);
    ~TabString();

    TabString &operator=(const TabString &tab);

    void add(std::string str);

    unsigned long int get(std::string str) const ;
    std::string get(unsigned long int i) const;
    unsigned long int getSize() const;

    /* Split the string */
    static unsigned long int strsplit(const std::string& ,std::string*&,char);
};

#endif