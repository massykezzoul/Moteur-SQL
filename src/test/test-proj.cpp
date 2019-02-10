#include<iostream>
#include "../table.h"
#include "../tabstring.h"
#include "../matricestring.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        Table tab;
        Table matable(argv[1]);
        TabString attr;
        attr.add("NOM");
        attr.add("PRENOM");
        cout<<"ok"<<endl;
       tab=matable.projection(attr);
       
        tab.print();
        cout << "La Table '" << matable.getNomTable() <<  "' ; " << endl;
    } else {
        cerr << "Please give a file"<< endl;
    }

    return 0;
}