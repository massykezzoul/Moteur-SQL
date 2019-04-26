#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    unsigned int day,month,year;
public:
    /* Les constructeurs */
    Date();
    /* parametré jours,mois,années */
    Date(unsigned int,unsigned int,unsigned int);
    /* Prend en paramétre une chaine au format dd/mm/yyyy */
    Date(std::string);

    /* Les operateurs de comparaison */
    bool operator==(Date) const;
    bool operator!=(Date) const;
    bool operator<=(Date) const;
    bool operator>=(Date) const;
    bool operator>(Date) const;
    bool operator<(Date) const;

    std::string toString() const;

    bool static isDate(std::string);
};

std::ostream& operator<<(std::ostream&,const Date);

#endif