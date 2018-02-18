#include "stdafx.h"

using namespace std;
string ReadFromTextToString(string pathToTextFile);

void main()
{
	string mainString;

	mainString = ReadFromTextToString("Text.txt");
	cout << mainString;

	_getch();
}

string ReadFromTextToString(string pathToTextFile)
{
	ifstream textFile;
	string stringBuffer,stringWithAllText;

	textFile.open(pathToTextFile);
	if (!textFile)
		cout << "ERROR! File not found" << endl;

	while (getline(textFile, stringBuffer))
		stringWithAllText += stringBuffer;
	
		//cout << stringWithAllText;

	textFile.close();

	return stringWithAllText;
}
