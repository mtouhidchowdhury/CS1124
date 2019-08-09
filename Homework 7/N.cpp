#include "N.h"
#include "W.h"
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft {
	Noble::Noble(const string& name) : name(name), alive(true) {}

	void Noble::hire(Warrior& toHire) {
		if (!toHire.isHired() && alive) {
			army.push_back(&toHire);
			toHire.getHired(*this);
		}
	}

	void Noble::fire(Warrior& toFire) {
		// Find the warrior to be fired in the vector army
		int indexToRemove = 0;
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &toFire) {
				// Once found, fire the warrior, and remove the warrior from the army vector
				cout << "You don't work for me anymore " << toFire.getName() << "!\t-- " << name << endl;
				army[i]->getFired();
				indexToRemove = i;

			}
		}
		army[indexToRemove] = army[army.size() - 1];
		army.pop_back();
	}

	void Noble::runaway(const Warrior& awol) {
		// Find the warrior to be fired in the vector army
		int indexToRemove = 0;
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &awol) {
				// Once found, fire the warrior, and remove the warrior from the army vector
				cout << awol.getName() << " flees in terror, abandoning his lord, " << name << endl;
				indexToRemove = i;

			}
		}
		army[indexToRemove] = army[army.size() - 1];
		army.pop_back();
	}

	void Noble::display() const {
		cout << name << " has an army of " << army.size() << endl;
		// Iterate through each warrior and display the warrior
		for (Warrior* w : army) {
			cout << "\t";
			w->display();
		}
	}

	double Noble::getTotalStrength() const {
		double tStrength = 0;
		// Sum the strength of each warrior
		for (Warrior* w : army) {
			tStrength += w->getStrength();
		}
		return tStrength;
	}

	void Noble::battle(Noble& enemy) {
		cout << name << " battles " << enemy.name << endl;
		if (!alive && !enemy.alive) {
			cout << "Oh, NO! They're both dead! Yuck!\n";
		}
		else if (!alive) {
			cout << "He's dead, " << enemy.name << endl;
		}
		else if (!enemy.alive) {
			cout << "He's dead, " << name << endl;
		}
		else if (getTotalStrength() == enemy.getTotalStrength()) {
			cout << "Mutual Annihalation: " << name << " and " << enemy.name << " die at each other's hands\n";
			die();
			enemy.die();
		}
		else if (getTotalStrength() > enemy.getTotalStrength()) {
			cout << name << " defeats " << enemy.name << endl;
			weaken(enemy.getTotalStrength() / getTotalStrength());
			enemy.die();
		}
		else if (enemy.getTotalStrength() > getTotalStrength()) {
			cout << enemy.name << " defeats " << name << endl;
			enemy.weaken(getTotalStrength() / enemy.getTotalStrength());
			die();
		}
	}

	void Noble::weaken(double factor) {
		// Iterate through each warrior and weaken them
		//    cout << "Weakening by " << factor << endl;
		for (Warrior* w : army) {
			w->weaken(factor);
		}
	}

	void Noble::die() {
		// Kill each warrior, then the noble dies
		for (Warrior* w : army) {
			w->die();
		}
		alive = false;
	}

	string Noble::getName() const { return name; }

	ostream& operator<<(ostream& os, const Noble& rhs) {
		os << rhs.name << " has an army of " << rhs.army.size();
		// Iterate through each warrior and display the warrior
		for (Warrior* w : rhs.army) {
			os << "\n\t" << *w;
		}
		return os;
	}
}