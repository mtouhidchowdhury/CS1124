#include <iostream>
#include <string>
#include <vector>




/* 
Mohammed Touhid Chowdhury 
mtc405
N14108583
*/
using namespace std;

//class instrument is virtual 
class Instrument {
public:
	virtual void makeSound() const = 0 {};
	virtual void play() const = 0 {};
private:

};
//class Brass inherit from instrument 
class Brass : public Instrument {
public:
	Brass( unsigned aSize): mouthPiece(aSize) {}
	virtual void makeSound() const {
		cout << "To make a sound blow on mouthpiece of size " << mouthPiece << endl;
	}
private:
	unsigned mouthPiece;
};

//class string inherit from instrument 

class String : public Instrument {
public:
	String(unsigned sound): pitch(sound){}
	virtual void makeSound()const {
		cout << "To make a sound bow a string with pitch " << pitch << endl;
	}
private:
	unsigned pitch;
};


///class precussion inherit from instrument 
class Percussion : public Instrument {
public:
	
	virtual void makeSound() const {
		cout << "To make a sound hit me! " << endl;
	}
private:

};

//class trumpet inherit from brass
class Trumpet : public Brass {
public:
	Trumpet(unsigned aSize) : Brass(aSize) {}
	void play() const { cout << "Toot" << endl; }
private:

};

//class trumbone inherit from brass

class Trombone : public Brass {
public:
	Trombone (unsigned aSize) : Brass(aSize) {}
	void play() const { cout << "Blat" << endl; }
private:

};

//violin inherit from string 
class Violin : public String {
public:
	class Violin(unsigned sound): String(sound) {}
	void play() const { cout << "Screech" << endl; }
private:

};

//cello inherit from string
class Cello : public String {
public:
	Cello(unsigned sound): String(sound) {}
	void play()const { cout << "Squawk" << endl; }
private:

};

//drum inherit from precussion
class Drum : public Percussion {
public:
	void play() const { cout << "Boom" << endl; }
private:

};

//class cymball inherit from percussion
class Cymbal : public Percussion {
public:
	void play() const { cout << "Crash" << endl; }
private:

};


//class musician  takes instrument from the MILL
class Musician {
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	//it tests the instrument 
	void testPlay() const {
		if (instr)
			instr->play();
		else
			cerr << "have no instr\n";
	}
private:
	Instrument* instr;
};

//mill gives out instruments 
class MILL {
public:
	bool receiveInstr(Instrument& anInstrument) {
		anInstrument.makeSound();
		for (size_t i = 0; i < allInstruments.size(); ++i) {
			if (allInstruments[i] == nullptr) {
				allInstruments[i] = &anInstrument;
				return true;
			}
		}
		allInstruments.push_back(&anInstrument);
		return false;
	}
	//tests each instrument every day 
	void dailyTestPlay() const {
		for (size_t i = 0; i < allInstruments.size(); ++i) {
			if (allInstruments[i] != nullptr) {
				allInstruments[i]->play();
			}
		}
	}
	Instrument* loanOut() {
		for (size_t i = 0; i < allInstruments.size(); ++i) {
			if (allInstruments[i] != nullptr) {
				Instrument* temp = allInstruments[i];
				allInstruments[i] = nullptr;
				return temp;

			}
		}
		return nullptr;
	}
private:
	vector<Instrument*> allInstruments;

};

//orchestra has max 25 players 
class Orch {
public:
	Orch() : allMusicians(25, nullptr) {}
	bool addPlayer(Musician& aMusician) {
		for (size_t i = 0; i < allMusicians.size(); ++i) {
			if (allMusicians[i] == nullptr) {
				allMusicians[i] = &aMusician;
				return true;
			}
		}
		return false;
	}
	//orchestra can play 
	void play() {
		for (size_t i = 0; i < allMusicians.size(); ++i) {
			if (allMusicians[i] != nullptr) {
				allMusicians[i]->testPlay();
			}
		}
	}
private:
	vector<Musician*> allMusicians;
};

// PART ONE
int main()
{

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

}






























