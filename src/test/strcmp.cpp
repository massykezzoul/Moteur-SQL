#include <iostream>
#include <string>

/**
 * Fichier test pour comparer entre deux string 
*/

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc == 3) {
        cout << "Comparer entre des string : "<< endl;
        string s1(argv[1]);
        string s2(argv[2]);
        
        if (s1 < s2)
            cout << s1 << " < " << s2 << endl;
        else if (s1 == s2)
            cout << s1 << " = " << s2 << endl;
        else 
            cout << s1 << " > " << s2 << endl;

    } else {
        string s1("12");
        string s2("13");
        cout << s1 << " " << (s1==s2?'=':(s1>s2)?'>':'<') << " " << s2 << endl;
    }
    return 0;
}
