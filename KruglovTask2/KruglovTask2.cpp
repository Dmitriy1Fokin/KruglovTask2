#include "stdafx.h"

using namespace std;
string ReadFromTextToString(string pathToTextFile);
string TextFormatting(string originText);

void main()
{
	string mainString, stringAfterFormat;;

	mainString = ReadFromTextToString("Text.txt");
	cout << mainString;
	
	cout << "\n\nFormat Text:\n\n";
	stringAfterFormat = TextFormatting(mainString);
	cout << stringAfterFormat;

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
	
	textFile.close();

	return stringWithAllText;
}

string TextFormatting(const string originText)
{
	string formatString = originText;
	int sizeOfString = formatString.length();

	for (int i(0); i < sizeOfString; i++)
	{
		if (formatString[i] == ',' || formatString[i] == '.' ||
			formatString[i] == '?' || formatString[i] == '!' ||
			formatString[i] == ':' || formatString[i] == ';')
		{
			if (formatString[i + 1] != ' ')
				formatString.insert(i + 1, " ");

			if (formatString[i + 2] == ' ')
				while (formatString[i + 2] == ' ')
					formatString.erase(i + 2, 1);
			
			int j = i - 1;
			while (formatString[j] == ' ')
			{
				formatString.erase(j, 1);
				j--;
				i = j;
			}

			sizeOfString = formatString.length();
		}
	}
		


	return formatString;
}