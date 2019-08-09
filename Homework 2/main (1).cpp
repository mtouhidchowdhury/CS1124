#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
// Mohammed Touhid Chowdhury mtc405
/* reads a file of warriors , adds warriors, creates battles
and displays the status */
// hw 2
struct Warrior{
    string name;
    int power;
};

void displayStatus(const vector<Warrior>& allWarriors);
int findWarrior(const vector<Warrior>& allWarriors,const string& nameWarrior);
void createWarrior( Warrior& aWarrior, const string& name, const  int& power);
void battle(const string& firstWarrior,const string& secondWarrior, vector<Warrior>& allWarriors);

int main()
{   //open the stream
    ifstream WarriorFile("warriors.txt");
    if (!WarriorFile) {
        cerr << "couldn't open file";
        exit(1);
    }
    string command;
    string name;
    string anotherName;
    int power;
    vector <Warrior> allWarriors;
    //loop through file and do the appropriate command
    while ( WarriorFile >> command ) {
        // check what the command is and call the specific function for that command
        if (command == "Warrior"){
            WarriorFile >> name >> power;
            Warrior aWarrior;
            createWarrior(aWarrior, name, power);
            allWarriors.push_back(aWarrior);
        }
        else if (command == "Status"){
            displayStatus(allWarriors);
        }
        else if (command == "Battle"){
            WarriorFile >> name >> anotherName;
            battle(name, anotherName, allWarriors);
        }
    }

    WarriorFile.close();

}


void displayStatus(const vector<Warrior>& allWarriors){
    //display the status's of the warriors in the vector
    cout << "There are " << allWarriors.size() << " warriors." << endl;
    for (Warrior aWarrior: allWarriors){
        cout << "Warrior: " << aWarrior.name << ", Strength: " << aWarrior.power << endl;
    }

}

int findWarrior(const vector<Warrior>& allWarriors,const string& nameWarrior){
    //find the index for a warrior
    for (size_t i = 0; i < allWarriors.size(); i++){
        if (allWarriors[i].name == nameWarrior){
            return i;
        }
    }
}

void createWarrior( Warrior& aWarrior, const string& name, const  int& power){
    //function to create a new warrior
    aWarrior.name = name;
    aWarrior.power = power;
}

void battle(const string& firstWarrior,const string& secondWarrior, vector<Warrior>& allWarriors){
    // battles between to warrior depending on the condition
    int indexFirstWarrior = findWarrior(allWarriors, firstWarrior);
    int indexSecondWarrior = findWarrior(allWarriors, secondWarrior);
    cout << allWarriors[indexFirstWarrior].name << " battles " << allWarriors[indexSecondWarrior].name << endl;
    //if power is same then two conditions; either both dead or both kill each other
    if (allWarriors[indexFirstWarrior].power == allWarriors[indexSecondWarrior].power){
        if(allWarriors[indexFirstWarrior].power == 0 && allWarriors[indexSecondWarrior].power == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else{
            cout << "Mutual Annihilation: " << allWarriors[indexFirstWarrior].name;
            cout << " and " << allWarriors[indexSecondWarrior].name << " die at each other's hands" << endl;
            allWarriors[indexFirstWarrior].power = 0;
            allWarriors[indexSecondWarrior].power = 0;
        }
    }
    // if one warrior has larger power either the larger wins or the weaker is already dead
    else if (allWarriors[indexFirstWarrior].power > allWarriors[indexSecondWarrior].power){
        if (allWarriors[indexSecondWarrior].power == 0){
            cout << "He's dead, " << allWarriors[indexFirstWarrior].name << endl;
        }
        else{
            allWarriors[indexFirstWarrior].power -= allWarriors[indexSecondWarrior].power;
            allWarriors[indexSecondWarrior].power = 0;
            cout << allWarriors[indexFirstWarrior].name << " defeats " << allWarriors[indexSecondWarrior].name << endl;
        }
    }
    //if the second warrior has larger power either larger wins or weaker is already dead
    else if (allWarriors[indexSecondWarrior].power > allWarriors[indexFirstWarrior].power){
        if (allWarriors[indexFirstWarrior].power == 0 ){
            cout << "He's dead, " << allWarriors[indexSecondWarrior].name << endl;

        }
        else{
            allWarriors[indexSecondWarrior].power -= allWarriors[indexFirstWarrior].power;
            allWarriors[indexFirstWarrior].power = 0;
            cout << allWarriors[indexSecondWarrior].name << " defeats " << allWarriors[indexFirstWarrior].name << endl;
        }
    }
}


