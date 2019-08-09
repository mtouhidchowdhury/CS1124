#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Mohammed Touhid Chowdhury 
mtc405
hw04
*/

class Warrior {
public:
	//constructor for warrior initializes using name and power
	Warrior(const string& aName, const double& aPower) : warriorName(aName), warriorPower(aPower) {}
	//methods to get name power and change power or kill warrior 
	string getWarriorName() const  { return warriorName; }
	double getWarriorPower() const  { return warriorPower; }
	void changePower(const double& damage) {
		warriorPower = warriorPower *(1 - damage) ;
	}
	void killWarrior() { warriorPower = 0; }
private:
	string warriorName;
	double warriorPower;
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
		allWarriors.push_back(warriorPtr);
	}
	//get noble name and status to display 
	string getNobleName() const  { return nobleName; }
	bool getNobleStatus() const  { return nobleDead; }
	//if noble dies status goes to true
	void killNoble() { nobleDead = true; }
	//noble can fire a warrior
	void fire(Warrior& theWarrior) {
		cout << theWarrior.getWarriorName() << ", you're fired! -- " << nobleName << endl;
		for (size_t i = 0; i < allWarriors.size(); ++i) {
			if (allWarriors[i]->getWarriorName() == theWarrior.getWarriorName()) {
				allWarriors[i] = allWarriors[i + 1];
			}
			allWarriors.pop_back();
		}
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
			cout << "Mutual Annihalation : " << getNobleName() << "and ";
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


int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}