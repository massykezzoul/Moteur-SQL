#ifndef _REQUETE__H_
#define _REQUETE__H_

class Requete {
private:
    std::string* select;
    unsigned int sizeSelect;
    std::string* from;
    unsigned int sizeFrom;
    std::string where;

    void parseSelect(std::string);
    void parseFrom(std::string);
    void parseWhere(std::string);

    static std::string cleanLine(std::string);

public:
    Requete();
    Requete(std::string);
    Requete(const Requete&);
    ~Requete();
    Requete& operator=(const Requete&);

    std::string getSelect(unsigned int)const;
    unsigned int getSizeSelect()const;
    std::string getFrom(unsigned int)const;
    unsigned int getSizeFrom()const;
    std::string getWhere() const;
};

#endif