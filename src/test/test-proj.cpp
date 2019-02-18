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
        TabString attr(2);
        attr.add("\"code postal\"");
        attr.add("\"ville\"");
        tab=matable.projection(attr);
        cout << endl << tab << endl;
        cout << "La Table '" << matable.getNomTable() <<  "'" << endl;
    } else {
        cerr << "Please give a file"<< endl;
    }

    return 0;
}