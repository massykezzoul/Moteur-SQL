#include "../tabCondition.h"
#include <iostream>
using namespace std; 



int main()
{
string str = "age < 20 and age < 30 and age > 18 and age = 15"; 
TabCondition objet(str);
cout << endl; 
for (unsigned long int i = 0 ; i< objet.getSizeOp() ; i++)
{
    if(objet.getOpL(i)==0) cout << "and\t";
    else cout << "or\t";
}
}