#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "tabstring.h"
#include "matricestring.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /*
    string* tab = NULL;
    string line = "idxcode,alpha2,alp\\,ha3\\,nom fr,nom gb,lkdslk";
    unsigned long int n = TabString::strsplit(line,tab,',');
    cout << n << endl;
    if (tab != NULL)
    for(size_t i = 0; i < n; i++) {
        cout << tab[i] << endl;
    } else cout << "NULL" << endl;
    */

    ifstream file("../tables/pays.csv");
    if (file) {
        TabString tab(file);
        MatriceString mat(file);

        for(size_t i = 0; i < tab.getSize(); i++) {
            cout << tab.get(i) << " ";
        }
        cout << endl;
        for(size_t i = 0; i < mat.getSize(); i++) {
            for(size_t j = 0; j < mat.get(i).getSize() ; j++)
                cout << mat.get(i).get(j) << " ";
            cout << endl;
        }

    } else {
        cout << "no file" << endl;
    }

    return 0;
}

