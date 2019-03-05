#include <iostream>
#include <string>
#include <cstdlib> // atoi()
#include <sstream> // for convertion in toString()
#include "date.h"
#include "tabstring.h"

using namespace std;

Date::Date():day(1),month(1),year(1900) {}

Date::Date(unsigned int d,unsigned int m,unsigned int y):day(d),month(m),year(y) {}

Date::Date(string date){
    string* split;
    if (TabString::strsplit(date,split,'/') == 3 && atoi(split[0].c_str()) > 0 && atoi(split[0].c_str()) < 32 && atoi(split[1].c_str()) > 0 && atoi(split[1].c_str()) < 13 && atoi(split[2].c_str()) > 0) {
        day = atoi(split[0].c_str());
        month = atoi(split[1].c_str());
        year = atoi(split[2].c_str());
    } else {
        cerr << "Erreur de date : '" << date <<"' n'est pas une date valide" << endl;
        exit(1);
    }
}

bool Date::operator==(Date d) const {
    return day == d.day && month == d.month && year == d.year;
}
bool Date::operator!=(Date d) const {
    return !(*this == d);
}
bool Date::operator<(Date d) const {
    return (year!=d.year?year<d.year:(month!=d.month?month<d.month:(day<d.day)));
}
bool Date::operator>(Date d) const {
    return (year!=d.year?year>d.year:(month!=d.month?month>d.month:(day>d.day)));
}
bool Date::operator<=(Date d) const {
    return (*this < d) || (*this == d);
}
bool Date::operator>=(Date d) const {
    return (*this > d) || (*this == d);
}

string Date::toString() const {
    string monthName[] = { "Janvier", "Février", "Mars",
		"Avril", "Mai", "Juin", "Juillet",
		"Aout", "Septembre", "Octobre",
		"Novembre", "Decembre" };
    stringstream ss;
    ss << day << " " << monthName[month-1] << " " << year;
    return ss.str();
}

bool Date::isDate(string date) {
    string* split;
    if (TabString::strsplit(date,split,'/') == 3) {
        return atoi(split[0].c_str()) > 0 && atoi(split[0].c_str()) < 32 && atoi(split[1].c_str()) > 0 && atoi(split[1].c_str()) < 13 && atoi(split[2].c_str()) > 0;
    }
    return false;
}
