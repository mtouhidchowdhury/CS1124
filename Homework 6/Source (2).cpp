#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Touhid Chowdhury
hw 6 
N14108583 mtc405
*/
class Noble {
public:
	//constructor for noble
	Noble(const string& aName) : name(aName), isAlive(true) {}
	string getName() { return name; }
	virtual double getPower() const = 0;
	void kill() { isAlive = false; }
	bool checkLife() const { return isAlive; }
	virtual void display() const = 0;
	// battle between nobles
	void battle(Noble& aNoble) {
		cout << getName() << " battles " << aNoble.getName() << endl;
		//if both are alive
		if (this->checkLife() == true && aNoble.checkLife() == true) {
			if (this->getPower() > aNoble.getPower()) {
				this->display();
				aNoble.display();
				aNoble.kill();
				cout << this->getName() << " defeats " << aNoble.getName() << endl;
			}
			else if (this->getPower() < aNoble.getPower()) {
				aNoble.display();
				this->display();
				this->kill();
				cout << aNoble.getName() << " defeats " << this->getName() << endl;

			}
			//if both have equal power
			else if (this->getPower() == aNoble.getPower()) {
				cout << " Mutual Annihalation: " << aNoble.getName() << " and " <<this->getName() << " at each other's hands" << endl;
			}

		}
		//if one is dead and another alive
		else if (this->checkLife() == false && aNoble.checkLife() == true){
			cout << "He' s dead, " << aNoble.getName() << endl;
		}
		else if (this->checkLife() == true && aNoble.checkLife() == false) {
			cout << "He's dead, " << this->getName() << endl;
		}
		// if both already dead
		else {
			cout << "OH, NO. Their both dead! YUCK!" << endl;
		}
	}
private:
	string name;
	bool isAlive;
};

class Protector {
public:
	//protector constructor
	Protector(const string& aName, double aPower) : name(aName), power(aPower), isHired(false), life(true), boss(nullptr){}
	bool checkHired() const { return isHired; }
	bool checkLife() const { return life; }
	double getPower() const { return power; }
	virtual void display() const = 0;
	string getName() const { return name; }
	//method to kill a protector
	void kill() {
		life = false;
		power = 0;
	}
	//getting hired
	void hire(Noble* aNoble) { boss = aNoble; }
	string getBossName() const { return boss->getName(); }
private:
	string name;
	double power;
	bool isHired;
	bool life;
	Noble* boss;

};
//wizard inherited from protector
class Wizard : public Protector {
public:
	Wizard (const string& aName, double aPower): Protector(aName, aPower){}
	void display() const { cout << "POOF" << endl; }
};
//warrior inherited from protector
class Warrior : public Protector {
public:
	Warrior(const string& aName, double aPower): Protector(aName, aPower){}
private:
};

class Archer : public Warrior {
public:
	Archer(const string& aName, double aPower) : Warrior(aName, aPower) {}
	void display() const {
		cout << "TWANG!" << getName() << " says: Take that in the name of my lord, " << getBossName() << endl;
	}
private:
};

class Swordsman : public Warrior {
public:
	Swordsman(const string& aName, double aPower) : Warrior(aName, aPower) {}
	void display() const {
		cout << "CLANG!" << getName() << "says: Take that in the name of my lord, " << getBossName() << endl;
	}
private:
};

//type of noble
class PersonWithStrengthToFight : public Noble {
public:
	PersonWithStrengthToFight(const string& name, double power): Noble(name), strength(power){}
	void display() const {}
	//get power
	double getPower() const { return strength; }
	//when die strength is zero
	void kill() {
		strength = 0;
		Noble::kill();
	}
private:
	double strength; 
};
//type of lord
class Lord : public Noble {
public:
	Lord(const string& aName): Noble(aName){}
	//hire a protector
	bool hires( Protector& aProtector) {
		if (aProtector.checkHired() == true) {
			return false;
		}
		else if (aProtector.checkLife() == false) {
			return false;
		}
		else {
			aProtector.hire(this);
			allProtectors.push_back(&aProtector);
			return true;
		}
	}
	//get total power
	double getPower() const {
		double totalPower = 0;
		for (size_t i = 0; i < allProtectors.size(); ++i) {
			totalPower += allProtectors[i]->getPower();
		}
		return totalPower;
	}
	//when die army die
	void kill() {
		for (size_t i = 0; i < allProtectors.size(); ++i) {
			allProtectors[i]->kill();
			Noble::kill();
		}
	}
	//display warriors
	void display() const {
		for (size_t i = 0; i < allProtectors.size(); ++i) {
			allProtectors[i]->display();
		}
	}
private:
	vector<Protector*> allProtectors;
};




int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}