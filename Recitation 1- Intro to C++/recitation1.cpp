#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Mohammed Touhid Chowdhury
//mtc405
// opening a file and reading the number of lines, letters, and characters 

int main()
{	
	ifstream document("jabberwocky.txt");

	if (!document) {
		cerr << "couldn't open file";
	}

	int numberOfLines = 0;
	string line;

	while (getline(document, line)) {
		cout << line << endl;
		numberOfLines++;
	}

	document.clear();
	document.seekg(0);

	cout << "\nNUMBER OF LINES ARE: " << numberOfLines << endl;

	string word;
	int numberOfWords = 0;
	while (document >> word) {
		numberOfWords++;
	}
	cout << "NUMBER OF WORDS ARE: " << numberOfWords << endl;
	
	document.clear();
	document.seekg(0);

	char letters;
	int numberOfLetters = 0;
	document >> noskipws;

	while (document >> letters) {
		numberOfLetters++;
	}
	cout << "NUMBER OF CHARACTERS ARE: " << numberOfLetters << endl;

	document.close();

}
