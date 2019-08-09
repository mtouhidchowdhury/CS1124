#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Molecule {
	vector <string> name;
	int numberOfCarbon;
	int numberOfHydrogen;
};

void printMolecules (vector<Molecule> allMolecule, int highestCarbon){
    for (size_t i = 0; i <= highestCarbon; ++i) {
		for (Molecule x: allMolecule)
		if (x.numberOfCarbon == i) {

			cout << "C" << x.numberOfCarbon << "H" << x.numberOfHydrogen << " ";

			for (string names : x.name) {
				cout << names << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	ifstream file("hydrocarbons.txt");
	if (!file) {
		cerr << "Couldnt open file" << endl;
	}
	string name;
	char junk;
	int carbonNumber;
	int hydrogenNumber;
	bool flag = false;
	int highestCarbon = 0;
	vector <Molecule> allMolecule;
	while (file >> name >> junk >> carbonNumber >> junk >> hydrogenNumber) {
		if (highestCarbon < carbonNumber) {
			highestCarbon = carbonNumber;
		}
		flag = false;
		Molecule aMolecule;
		for (size_t i = 0; i < allMolecule.size() ; i++ ) {
			if (allMolecule[i].numberOfCarbon == carbonNumber && allMolecule[i].numberOfHydrogen == hydrogenNumber) {
				allMolecule[i].name.push_back(name);
				flag = true;
			}
		}
		if (flag == false) {
			aMolecule.numberOfCarbon = carbonNumber;
			aMolecule.numberOfHydrogen = hydrogenNumber;
			aMolecule.name.push_back(name);
			allMolecule.push_back(aMolecule);

		}

	}

	printMolecules(allMolecule, highestCarbon);
    file.close();
}

