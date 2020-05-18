#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ReplaceString(const string& subject, const string& searchString, const string& replacementString)
{
	size_t pos = 0;
	string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos != string::npos)
		{
			result.append(replacementString);
			pos = foundPos + searchString.length();
		}
		else
		{
			break;
		}
	}
	return result;
}

int CopyTextWithReplace(char* input, char* output, char* searchString, char* replaceString)
{
	ifstream fileIn;
	ofstream fileOut;
	fileIn.open(input);
	fileOut.open(output);

	if (!fileIn.is_open()){
		cout << "Can't find input file. Please, enter correct file name\n";
		return 1;
	}

	if (!fileOut.is_open()){
		cout << "Can't find output file. Please, enter correct file name\n";
		return 1;
	}

	string line;
	while (getline(fileIn, line))
	{
		fileOut << ReplaceString(line, searchString, replaceString) << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid argument count\n"
        << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}
	CopyTextWithReplace(argv[1], argv[2], argv[3], argv[4]);
	return 0;
}
