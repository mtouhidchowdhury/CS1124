#ifndef W_H
#define W_H

#include <string>

namespace WarriorCraft {
	class Noble;
	class Warrior {
	public:
		Warrior(const std::string& name, double strength);
		void getHired(Noble& n);
		void getFired();
		bool isHired() const;
		void display() const;
		double getStrength() const;
		void die();
		void weaken(double factor);
		std::string getName() const;
		void runaway();
		friend std::ostream& operator<<(std::ostream& os, const Warrior& rhs);
	private:
		std::string name;
		double strength;
		Noble* noble;
	};
}
#endif

