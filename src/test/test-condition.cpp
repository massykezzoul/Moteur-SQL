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
    tab.add("El Houiti");
    tab.add("26");
    cout << "La Condition : " << c << endl;
    cout << cond.verifier(tab,1) << endl;
    cout << cond.verifier(tab1,1) << endl;
    return 0;
}
