#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
/*
Mohammed Touhid Chowdhury
mtc405
reads a file of warriors and creates objects of warriors with objects of weapons with
attributes of name and power. Warriors can battle each other as well.
*/

class Weapon{
public:
    // constructor to initialize the name and power
    Weapon( const string& name, int& power):weaponName(name), weaponPower(power) {}
    //methods to change the weapons power
    void powerReduced(const int& power){
        weaponPower -= power;
    }
    void removeAllPower(){
        weaponPower = 0;
    }
    //returns the name and power so the Warrior can display
    string getName() const {
        return weaponName;
    }
    int getPower() const {
        return weaponPower;
    }

private:
    string weaponName;
    int weaponPower;


};


class Warrior{

public:
    //constructor to initialize the warrior name and the weapon class's power and name
    Warrior(const string& name,const string& weaponName, int& weaponPower): warriorName(name), warriorWeapon(weaponName, weaponPower) {}
    //display method
    void displayWarrior() const {
        cout << "Warrior: " << warriorName << ", Weapon: " << warriorWeapon.getName() << ", " << warriorWeapon.getPower() << endl;
    }
    //delegate by calling function in weapon
    void changeWeaponPower(int powerReduced){
        warriorWeapon.powerReduced(powerReduced);
    }
    void removePower(){
        warriorWeapon.removeAllPower();
    }
    //return name and power for displaying and checking
    string getWarriorName() const {
        return warriorName;
    }
    int getWarriorPower() const{
        return warriorWeapon.getPower();
    }
private:
    string warriorName;
    Weapon warriorWeapon;

};

void battle (const string& firstWarrior, const string& secondWarrior, vector<Warrior>& allWarriors);
int findWarrior(const vector<Warrior>& allWarriors, const string& nameWarrior);
void displayAllWarriors(const vector<Warrior>& allWarriors);

int main(){
    //opening file and checking if successful
    ifstream warriorFile("warriors.txt");
    if (!warriorFile) {
        cerr << "couldn't open file";
        exit(1);
    }
    string command;
    string name;
    string anotherName;
    int power;
    string weapon;
    vector <Warrior> allWarriors;
    //loop through file and do the appropriate command
    while ( warriorFile >> command ) {
        // check what the command is and call the specific function for that command
        if (command == "Warrior"){
            warriorFile >> name >> weapon >> power;
            Warrior aWarrior(name,weapon,power);
            allWarriors.push_back(aWarrior);
        }
        else if (command == "Status"){
            displayAllWarriors(allWarriors);
        }
        else if (command == "Battle"){
            warriorFile >> name >> anotherName;
            battle(name, anotherName, allWarriors);
        }
    }
    warriorFile.close();

}




void displayAllWarriors(const vector<Warrior>& allWarriors){
    cout << "There are " << allWarriors.size() << " warriors. " << endl;
    for (size_t i = 0; i < allWarriors.size(); i++){
        allWarriors[i].displayWarrior();
    }
}

int findWarrior(const vector<Warrior>& allWarriors, const string& nameWarrior){
    //find the index for a warrior
    for (size_t i = 0; i < allWarriors.size(); i++){
        string theName = allWarriors[i].getWarriorName();
        if (theName == nameWarrior){
            return i;
        }
    }
}

void battle (const string& firstWarrior, const string& secondWarrior, vector<Warrior>& allWarriors){
    int indexFirstWarrior = findWarrior(allWarriors, firstWarrior);
    int indexSecondWarrior = findWarrior(allWarriors, secondWarrior);
    cout << allWarriors[indexFirstWarrior].getWarriorName();
    cout << " battles " << allWarriors[indexSecondWarrior].getWarriorName() << endl;
    //if power is same then two conditions; either both dead or both kill each other
    if (allWarriors[indexFirstWarrior].getWarriorPower() == allWarriors[indexSecondWarrior].getWarriorPower()){
        if(allWarriors[indexFirstWarrior].getWarriorPower() == 0 && allWarriors[indexSecondWarrior].getWarriorPower() == 0){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else{
            cout << "Mutual Annihilation: " << allWarriors[indexFirstWarrior].getWarriorName();
            cout << " and " << allWarriors[indexSecondWarrior].getWarriorName() << " die at each other's hands" << endl;
            allWarriors[indexFirstWarrior].removePower();
            allWarriors[indexSecondWarrior].removePower();
        }
    }
    // if one warrior has larger power either the larger wins or the weaker is already dead
    else if (allWarriors[indexFirstWarrior].getWarriorPower() > allWarriors[indexSecondWarrior].getWarriorPower()){
        if (allWarriors[indexSecondWarrior].getWarriorPower() == 0){
            cout << "He's dead, " << allWarriors[indexFirstWarrior].getWarriorName() << endl;
        }
        else{
            allWarriors[indexFirstWarrior].changeWeaponPower(allWarriors[indexSecondWarrior].getWarriorPower());
            allWarriors[indexSecondWarrior].removePower();
            cout << allWarriors[indexFirstWarrior].getWarriorName() << " defeats " << allWarriors[indexSecondWarrior].getWarriorName() << endl;
        }
    }
    //if the second warrior has larger power either larger wins or weaker is already dead
    else if (allWarriors[indexSecondWarrior].getWarriorPower() > allWarriors[indexFirstWarrior].getWarriorPower()){
        if (allWarriors[indexFirstWarrior].getWarriorPower() == 0 ){
            cout << "He's dead, " << allWarriors[indexSecondWarrior].getWarriorName() << endl;

        }
        else{
            allWarriors[indexSecondWarrior].changeWeaponPower(allWarriors[indexFirstWarrior].getWarriorPower());
            allWarriors[indexFirstWarrior].removePower();
            cout << allWarriors[indexSecondWarrior].getWarriorName() << " defeats " << allWarriors[indexFirstWarrior].getWarriorName() << endl;
        }
    }
}

