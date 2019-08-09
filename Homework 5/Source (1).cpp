#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*
Mohammed Touhid Chowdhury
mtc405
N14108583
hw05

*/

class Warrior {
public:
	//constructor for warrior initializes using name and power
	Warrior(const string& aName, const double& aPower) : warriorName(aName), warriorPower(aPower), hired(false) {}
	//methods to get name power and change power or kill warrior 
	string getWarriorName() const { return warriorName; }
	double getWarriorPower() const { return warriorPower; }
	void getHired() { hired = true; }
	void getFired() { hired = false; }
	bool getEmploymentStatus() { return hired; }
	void changePower(const double& damage) {
		warriorPower = warriorPower *(1 - damage);
	}
	void killWarrior() { warriorPower = 0; }
private:
	string warriorName;
	double warriorPower;
	bool hired;
};

class Noble {
public:
	//constructor to initialize noble with name and automatic death status
	Noble(const string& aName) : nobleName(aName), nobleDead(false) {}
	//function to display noble's army 
	void display() const {
		cout << nobleName << " has an army of " << allWarriors.size() << endl;
		for (size_t index = 0; index < allWarriors.size(); ++index) {
			cout << allWarriors[index]->getWarriorName() << " : " << allWarriors[index]->getWarriorPower() << endl;
		}
	}
	//noble can hire warriors
	void hire(Warrior& aWarrior) {
		Warrior* warriorPtr;
		warriorPtr = &aWarrior;
		warriorPtr->getHired();
		allWarriors.push_back(warriorPtr);
	}
	//get noble name and status to display 
	string getNobleName() const { return nobleName; }
	bool getNobleStatus() const { return nobleDead; }
	//if noble dies status goes to true
	void killNoble() { nobleDead = true; }
	//noble can fire a warrior
	void fire(Warrior& theWarrior) {
		cout << theWarrior.getWarriorName() << ", you're fired! -- " << nobleName << endl;
		theWarrior.getFired();
		int indexToFire = 0;
		int indexOfLast = allWarriors.size() - 1;
		for (size_t i = 0; i < allWarriors.size(); ++i) {
			if (allWarriors[i]->getWarriorName() == theWarrior.getWarriorName()) {
				indexToFire = i;
			}
		}
		allWarriors[indexToFire] = allWarriors[indexOfLast];
		allWarriors.pop_back();
	}
	//method for army total strength 
	double getArmyStrength() {
		double strength = 0;
		for (size_t i = 0; i < allWarriors.size(); ++i) {
			strength += allWarriors[i]->getWarriorPower();
		}
		return strength;
	}
	//battle between nobles with conditions
	void battle(Noble& aNoble) {
		cout << nobleName << " battles " << aNoble.getNobleName() << endl;
		if (getNobleStatus() == true && aNoble.getNobleStatus() == true) {
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
		}
		else if (getNobleStatus()) {
			cout << "He's dead " << aNoble.getNobleName() << endl;
		}
		else if (aNoble.getNobleStatus()) {
			cout << "He's dead " << getNobleName() << endl;
		}
		else if (getArmyStrength() == aNoble.getArmyStrength()) {
			cout << "Mutual Annihalation : " << getNobleName() << " and ";
			cout << aNoble.getNobleName() << " die at each other's hands" << endl;
			for (size_t i = 0; i < aNoble.allWarriors.size(); ++i) {
				aNoble.allWarriors[i]->killWarrior();
			}
			for (size_t i = 0; i < allWarriors.size(); ++i) {
				allWarriors[i]->killWarrior();
			}
			aNoble.killNoble();
			killNoble();
		}
		else if (aNoble.getArmyStrength() > getArmyStrength()) {
			double damage = getArmyStrength() / aNoble.getArmyStrength();
			for (size_t i = 0; i < aNoble.allWarriors.size(); ++i) {
				aNoble.allWarriors[i]->changePower(damage);
			}
			for (size_t i = 0; i < allWarriors.size(); ++i) {
				allWarriors[i]->killWarrior();
			}
			killNoble();
			cout << aNoble.getNobleName() << "haha defeats " << getNobleName() << endl;
		}
		else if (aNoble.getArmyStrength() < getArmyStrength()) {
			double damage = aNoble.getArmyStrength() / getArmyStrength();
			for (size_t i = 0; i < allWarriors.size(); ++i) {
				allWarriors[i]->changePower(damage);
			}
			for (size_t i = 0; i < aNoble.allWarriors.size(); ++i) {
				aNoble.allWarriors[i]->killWarrior();
			}
			aNoble.killNoble();
			cout << getNobleName() << " defeats " << aNoble.getNobleName() << endl;
		}
	}
private:
	string nobleName;
	vector <Warrior*> allWarriors;
	bool nobleDead;
};

// prototype the functions
void checkWarrior(vector<Warrior*>& allWarriors, const string& name, const double& power);
void createBattle(vector<Noble*>& allNobles, string& nobleName, string& anotherNoble);
void displayStatus(const vector<Warrior*>& allWarrior, const vector<Noble*>& allnobles);
void checkHire(vector<Warrior*>& allWarriors, vector<Noble*>& allNobles, const string& nobleName, const string& warriorName);
void checkFire(vector<Warrior*>& allWarriors, vector<Noble*>& allNobles, const string& nobleName, const string& warriorName);
size_t getIndexByNameW(const string& name, const vector<Warrior*>& warriors);
size_t getIndexByNameN(const string& name, const vector<Noble*>& nobles);
void clear(vector<Warrior*>& allWarrior, vector<Noble*>& allNoble);
void checkNoble(vector<Noble*>& allNobles, const string& name);


int main() {
	//open file
	ifstream document("nobleWarriors.txt");
	if (!document) {
		cerr << "Couldnt open file! ";
	}
	vector<Warrior*> allWarriors;
	vector<Noble*> allNobles;
	string command;
	//check commmand to do appropriate task
	while (document >> command) {
		if (command == "Noble") {
			string name;
			document >> name;
			checkNoble(allNobles, name);
			//allNoble.push_back(new Noble(name));
		}
		else if (command == "Warrior") {
			string name;
			double power;
			document >> name >> power;
			checkWarrior(allWarriors, name, power);
			//allWarriors.push_back(new Warrior(name, power));
		}
		else if (command == "Hire") {
			string nobleName;
			string warriorName;
			document >> nobleName >> warriorName;
			checkHire(allWarriors, allNobles, nobleName, warriorName);
		}
		else if (command == "Fire") {
			string nobleName;
			string warriorName;
			document >> nobleName >> warriorName;
			checkFire(allWarriors, allNobles, nobleName, warriorName);
		}
		else if (command == "Status") {
			displayStatus(allWarriors, allNobles);
		}
		else if (command == "Battle") {
			string nobleOne;
			string nobleTwo;
			document >> nobleOne >> nobleTwo;
			createBattle(allNobles, nobleOne, nobleTwo);
		}
		else if (command == "Clear") {
			clear(allWarriors, allNobles);
		}
	}
}

// checks waarrior before hiring
void checkWarrior(vector<Warrior*>& allWarriors, const string& name, const double& power) {
	bool exist = false;
	for (size_t i = 0; i < allWarriors.size(); ++i) {
		if (allWarriors[i]->getWarriorName() == name) {
			exist = true;
		}
	}
	if (exist == false) {
		allWarriors.push_back(new Warrior(name, power));
	}
}

//creates battle if the nobles exist 
void createBattle(vector<Noble*>& allNobles, string& nobleName, string& anotherNoble) {
	size_t indexNobleTwo = getIndexByNameN(anotherNoble, allNobles);
	size_t indexNoble = getIndexByNameN(nobleName, allNobles);
	if (indexNoble != allNobles.size() && indexNobleTwo != allNobles.size()) {
		allNobles[indexNoble]->battle(*allNobles[indexNobleTwo]);
	}
}

//checks before adding a noble into the heap 
void checkNoble(vector<Noble*>& allNobles, const string& name) {
	bool exist = false;
	for (size_t i = 0; i < allNobles.size(); ++i) {
		if (allNobles[i]->getNobleName() == name) {
			exist = true;
		}
	}
	if (exist == false) {
		allNobles.push_back(new Noble(name));
	}
}

//displays the status  of how many warriors, nobles there are 
void displayStatus(const vector<Warrior*>& allWarrior, const vector<Noble*>& allnobles) {
	cout << "Status\n";
	cout << "======" << endl;
	if (allnobles.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (Noble* aNoble : allnobles) {
			aNoble->display();
		}
	}
	cout << "UNEMPLOYED WARRIORS: " << endl;
	int numberOfUnemployed = 0;
	for (Warrior* aWarrior : allWarrior) {
		if (aWarrior->getEmploymentStatus() == false) {
			cout << aWarrior->getWarriorName() << ": " << aWarrior->getWarriorPower() << endl;
			numberOfUnemployed++;
		}
	}
	if (numberOfUnemployed == 0) {
		cout << "NONE" << endl;
	}
}

//checks before hiring a warrior
void checkHire(vector<Warrior*>& allWarriors, vector<Noble*>& allNobles,const string& nobleName,const string& warriorName) {
	size_t indexWarrior = getIndexByNameW(warriorName, allWarriors);
	size_t indexNoble = getIndexByNameN(nobleName, allNobles);
	if (indexNoble != allNobles.size() && indexWarrior != allWarriors.size()) {
		allNobles[indexNoble]->hire(*allWarriors[indexWarrior]);
		allWarriors[indexWarrior]->getHired();
	}
}

//checks before firing a warrior
void checkFire(vector<Warrior*>& allWarriors, vector<Noble*>& allNobles, const string& nobleName, const string& warriorName) {
	size_t indexWarrior = getIndexByNameW(warriorName, allWarriors);
	size_t indexNoble = getIndexByNameN(nobleName, allNobles);
	if (indexNoble != allNobles.size() && indexWarrior != allWarriors.size()) {
		allNobles[indexNoble]->fire(*allWarriors[indexWarrior]);
	}
}

//function get the index of warrior and if doesnt exist then the size of vector
size_t getIndexByNameW(const string& name, const vector<Warrior*>& warriors) {
	for (size_t i = 0; i < warriors.size(); ++i) {
		if (warriors[i]->getWarriorName() == name) { return i; }
	}
	return warriors.size();
}
//function get the index of noble and if doesnt exist then the size of vector
size_t getIndexByNameN(const string& name, const vector<Noble*>& nobles) {
	for (size_t i = 0; i < nobles.size(); ++i) {
		if (nobles[i]->getNobleName() == name) { return i; }
	}
	return nobles.size();
}

//deletes all the warrior and noble from the heap 
void clear(vector<Warrior*>& allWarrior, vector<Noble*>& allNoble) {
	
	for (Warrior*& aWarrior : allWarrior){
		delete aWarrior;
	}
	for (Noble*& aNoble: allNoble) {
		delete aNoble;
	}
	allNoble.clear();
	allWarrior.clear();
}