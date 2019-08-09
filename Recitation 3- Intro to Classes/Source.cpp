#include <iostream>
#include <vector>

using namespace std;
// Mohammed Touhid Chowdhury 
// mtc405
// Lab 3 
class Sandwich {
public:
	Sandwich(const double& aMayo): mayo(aMayo){}
	Sandwich( int aTomato = 2, int aCheese = 1,double aMustard = 1, double aMayo =  0.5) :
		tomato(aTomato), cheese(aCheese), mustard(aMustard), mayo(aMayo) {}
	void display() const{
		cout << "tomato: " << tomato << endl;
		cout << "bread: " << bread << endl;
		cout << "cheese: " << cheese << endl;
		cout << "mayonaise: " << mayo << endl;
		cout << "mustard: " << mustard << endl;
		
	}
	//to get the info of each ingredient 
	int getBread() const { return bread; }
	int getCheese() const { return cheese; }
	double getMayo() const { return mayo; }
	int getTomato() const { return tomato;  }
	double getMustard() const { return mustard; }
	// mutator 
	void changeCheese(const int& numberOfCheese) { cheese = numberOfCheese; }
	void changeMayo(const int& numberOfMayo) { mayo = numberOfMayo; }
	void changeTomato(const int& numberOfTomato) { tomato = numberOfTomato; }
	void changeMustard(const int& numberOfMustard) { mustard = numberOfMustard; }
	
private:
	const int bread = 2;
	int cheese;
	double mayo;
	int tomato;
	double mustard;
};


class SandwichTruck {
public:
	void addSandwich(const Sandwich& aSandwich) {
		sandwichList.push_back(aSandwich);
	}
	void display() const {
		int sandwichNumber = 1;
		for (size_t i = 0; i < sandwichList.size(); i++) {
			cout << "Sandwich Number: " << sandwichNumber++ << endl;
			sandwichList[i].display();
		}
	}

private:
	vector<Sandwich> sandwichList;
};

int main() {
	//Sandwich aSandwich;
	//aSandwich.display();
	//Sandwich anotherSandwich(0.1);
	//anotherSandwich.display();
	//Sandwich oneSandwich(2, 2, 0.6, 0.5);
	//oneSandwich.display();
	//Sandwich s1;
	//s1.display();
	//Sandwich modifiedSandwich(4,2);
	//modifiedSandwich.display();
	//int numberOfTomato = modifiedSandwich.getTomato();
	//cout << "Number of tomato in this sandwich is: " << numberOfTomato << endl;
	//modifiedSandwich.changeTomato(100);
	//int newTomato = modifiedSandwich.getTomato();
	//cout << "Number of tomato is now: " << newTomato << endl;
	Sandwich firstSandwich;
	SandwichTruck insideTruck;
	insideTruck.addSandwich(firstSandwich);
	Sandwich secondSandwich;
	secondSandwich.changeMayo(0);
	insideTruck.addSandwich(secondSandwich);
	Sandwich thirdSandwich;
	thirdSandwich.changeCheese(2);
	insideTruck.addSandwich(thirdSandwich);
	Sandwich fourthSandwich;
	insideTruck.addSandwich(fourthSandwich);
	insideTruck.display();

}