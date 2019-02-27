#include "../tabCondition.h"
#include <iostream>
using namespace std; 



int main()
{
string str = "age < 20 and age > 15"; 
TabCondition objet(str);
cout << endl<< endl; 
for (int i = 0 ; i< objet.getSizeOp() ; i++)
{
    cout << objet.getOpL(i) << "\t";
}
}