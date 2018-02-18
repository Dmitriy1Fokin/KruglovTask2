#include "stdafx.h"

using namespace std;
string ReadFromTextToString(string pathToTextFile);
string TextFormatting(string originText);
string BigWordChangeToVau(const string originText);
vector<string> SplitString(const string originString, const int lenOfNewString);

void main()
{
	string mainString, stringAfterFormat;
	vector<string> vectorOfString;
	
	mainString = ReadFromTextToString("Text.txt");
	cout << mainString;
	
	cout << "\n\nFormat Text:\n\n";
	stringAfterFormat = TextFormatting(mainString);
	cout << stringAfterFormat;

	cout << "\n\nText without long word:\n\n";
	stringAfterFormat = BigWordChangeToVau(stringAfterFormat);
	cout << stringAfterFormat;

	cout << "\n\nText separate to string with length 40.\n\n";
	vectorOfString = SplitString(stringAfterFormat, 40);
	for (int i = 0; i < vectorOfString.size(); i++)
		cout << i << ":\t" << vectorOfString[i] << endl;

	
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
			formatString[i] == ':' || formatString[i] == ';' || 
			formatString[i] == '"')
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

		if (formatString[i] == ' ')
		{
			if (formatString[i + 1] == ' ')
				while (formatString[i + 1] == ' ')
					formatString.erase(i + 1, 1);
			
			sizeOfString = formatString.length();
		}
	}
		
	return formatString;
}

string BigWordChangeToVau(const string originText)
{
	stringstream stringfBuff(originText);
	string temp, outputString;

	while (stringfBuff >> temp)
	{
		if (temp.length() > 10)
		{
			temp = "Vau!!!";
		}
		outputString += " ";
		outputString += temp;
		outputString += " ";
	}

	return outputString;
}

vector<string> SplitString(const string originString, const int lenOfNewString)
{
	stringstream stringBuff(originString);
	string temp, newString;
	vector<string> finalVectorOfSplitString;

	while (stringBuff >> temp)
	{
		if (newString.length() < lenOfNewString)
		{
			newString += " ";
			newString += temp;
			newString += " ";
		}

		if (newString.length() > lenOfNewString)
		{
			newString.erase(newString.length() - temp.length() - 1);
			finalVectorOfSplitString.push_back(newString);
			newString.clear();
			newString += temp;
		}	

		if (newString.length() == lenOfNewString)
		{
			finalVectorOfSplitString.push_back(newString);
			newString.clear();
			newString += temp;
		}
	}

	finalVectorOfSplitString.push_back(newString);

	return finalVectorOfSplitString;
}