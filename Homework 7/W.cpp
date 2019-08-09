#include "W.h"
#include "N.h"
#include <string>
#include <iostream>
using namespace std;

namespace WarriorCraft {
	Warrior::Warrior(const string& name, double strength) : name(name), strength(strength), noble(nullptr) {}
	void Warrior::getHired(Noble& n) { noble = &n; }
	void Warrior::getFired() { noble = nullptr; }
	bool Warrior::isHired() const { return noble; }
	void Warrior::display() const {
		cout << name << ": " << strength << endl;
	}
	void Warrior::runaway() {
		noble->runaway(*this);
		noble = nullptr;
	}
	double Warrior::getStrength() const { return strength; }
	void Warrior::die() { strength = 0; }
	void Warrior::weaken(double factor) {
		strength -= strength*factor;
	}
	string Warrior::getName() const { return name; }
	std::ostream& operator<<(std::ostream& os, const Warrior& rhs) {
		os << rhs.name << ": " << rhs.strength;
		return os;
	}
}
