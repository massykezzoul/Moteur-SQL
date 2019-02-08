#include<iostream>
#include "../table.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        Table matable(argv[1]);
        matable.print();
        cout << "La Table '" << matable.getNomTable() <<  "' : " << endl;
    } else {
        cerr << "Please give a file"<< endl;
    }

    return 0;
}