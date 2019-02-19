#ifndef TABSTRING_H_
#define TABSTRING_H_

class TabString {
private:
    std::string *table; 
    unsigned long int size; 
    unsigned long int alloc;
public:
    TabString();
    TabString(std::ifstream &file); 
    TabString(unsigned long int);// allouer 
    TabString(const TabString &tab);
    TabString(const TabString&,const TabString&); // projection 
    ~TabString();

    TabString &operator=(const TabString &tab);
    TabString &operator+=(const TabString &tab);
    std::string &operator[](unsigned long int);
    const std::string &operator[](unsigned long int) const;


    void add(const std::string& str);

    unsigned long int get(std::string str) const ;
    std::string get(unsigned long int i) const;
    unsigned long int getSize() const;

    /* Split the string */
    static unsigned long int strsplit(const std::string& ,std::string*&,char);
};

#endif