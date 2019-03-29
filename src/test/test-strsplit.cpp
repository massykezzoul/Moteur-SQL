#include "../tabstring.h"
#include <iostream>

using namespace std ;

int main(int argc , const char **argv){
    string* tab ; 
    unsigned long int res = TabString::strsplit2(argv[1],tab,',');
    for (int i = 0 ; i < res ; i++) {
        cout << tab[i]<<endl;
    }
    return 0;
}
