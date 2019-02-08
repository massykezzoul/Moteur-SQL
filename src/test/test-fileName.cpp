#include <iostream>
#include <string>

using namespace std;
 
/*
 * Get File Name from a Path with or without extension
 */
string getFileName(string filePath, bool withExtension = true, char seperator = '/')
{
	// Le dernièr point trouvé
	size_t point = filePath.rfind(".");
	size_t sepPos = filePath.rfind(seperator);
    cout << point << endl;
    // Séparateur trouver
	if(sepPos != string::npos)
		return filePath.substr(sepPos + 1,(withExtension || point == string::npos ? 1 : point) - sepPos -1);
    // Séparateur non trouver
    return filePath.substr(0,(withExtension || point == string::npos ? filePath.size() : point));
}
 
int main()
{
	string filePath = "path/to/the/file/data.csv";
 
	// Get File name with extension from file path
	string name = getFileName(filePath);
 
	cout<<name<<endl;
 
	// Get File name without extension from file path
	name = getFileName(filePath, false);
 
	cout<<name<<endl;
 
	return 0;
}