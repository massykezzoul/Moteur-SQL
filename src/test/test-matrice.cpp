#include <iostream>
#include <fstream>
#include "../tabstring.h"
#include "../matricestring.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 2) {
        ifstream file(argv[1]);
        if (file) {
            TabString tab(file);
            MatriceString mat(file);

            /* Affichages des nom des attributs*/            
            for(size_t i = 0; i < tab.getSize(); i++)
                cout << tab[i] << " | ";
            cout << endl << endl;
            /* Affichages des valeurs des attributs */
            for(size_t i = 0; i < mat.getSize(); i++) {
                for(size_t j = 0; j < mat[i].getSize() ; j++)
                    cout << mat[i][j] << " | ";
                cout << endl;
            }

        } else {
            cout << "'" << argv[1] <<"' is not file" << endl;
        }
    } else {
        cerr << "Please give a file"<< endl;
    }

    return 0;
}

