#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//Mohammed Touhid Chowdhury mtc405
//HW01
/* This program takes an encrypted text file and
shifts the lower case letters to the indicated amount in the file */

char characterDecoder(char letter, const int& increment);
void stringTaker (string& line, const int& increment);


int main()
{
    ifstream encryptedFile("encrypted.txt");
    if (!encryptedFile) {
        cerr << "couldn't open file";
        exit(1);
    }

    string line;
    vector <string> vectorOfLines;
    int increment = 0;

    encryptedFile >> increment;
    getline(encryptedFile, line);
    // looping through each line applying change
    //adding each line to the vector
    while ( getline(encryptedFile, line) ) {
        stringTaker(line,increment);
        vectorOfLines.push_back(line);
    }
    //displaying vector from the end to beginning
    for (size_t i = vectorOfLines.size() - 1; i >= 0 && i < vectorOfLines.size(); i--) {
        cout << vectorOfLines[i] << endl;
    }
    encryptedFile.close();
}

char characterDecoder(char letter, const int& increment){
    // takes each letter and the increment number and applies increment
    // returns the original value if its not lower case
     if (letter > 'a' + increment - 1 && letter <= 'z') {
		letter = letter - increment; // minus the increment without wrap
		return letter;
	}
	else if (letter <= 'a' + increment - 1 && letter >= 'a') {
		letter = letter - increment + 26; // wrap around
		return letter;
    }else{
        return letter; // not a lower case letter
    }

}


void stringTaker (string& line, const int& increment){
    //takes line by line and modifies each character in the string
     for (int i = 0; i < line.size(); i++ ){
        line[i]= characterDecoder(line[i], increment);
     }
}


