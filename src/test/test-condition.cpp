#include <iostream>
#include <string>
#include "../condition.h"
#include "../tabstring.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string c("age > 25");
    Condition cond(c);
    TabString tab;
    tab.add("Kezzoul");
    tab.add("19");
    TabString tab1;
    tab1.add("El Houiti");
    tab1.add("26");
    cout << "La Condition : " << c << endl;
    cout << (cond.verifier(tab,1)?"vrai":"faux") << endl;
    cout << (cond.verifier(tab1,1)?"vrai":"faux") << endl;
    return 0;
}
