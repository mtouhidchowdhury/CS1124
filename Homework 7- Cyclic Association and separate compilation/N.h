#ifndef N_H
#define N_H

#include <string>
#include <vector>

namespace WarriorCraft {
	class Warrior;

	class Noble {
	public:
		Noble(const std::string& name);
		void hire(Warrior& toHire);
		void fire(Warrior& toFire);
		void display() const;
		double getTotalStrength() const;
		void battle(Noble& enemy);
		void weaken(double factor);
		void die();
		std::string getName() const;
		void runaway(const Warrior& awol);
		friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
	private:
		std::string name;
		std::vector<Warrior*> army;
		bool alive;
	};
}
#endif

