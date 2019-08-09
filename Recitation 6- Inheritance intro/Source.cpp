#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned pages): numberOfPages(pages){}
	virtual void displayNumPages() const = 0{ cout <<"Number of pages" <<  numberOfPages << endl; }
protected:
private:
	unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned pages):PrintedMaterial(pages){}
	void displayNumPages() const { 
		cout << "Number of pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned pages): PrintedMaterial(pages){}
	void displayNumPages() const {
		cout << "Number of pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned pages, unsigned numberIndex):Book(pages), numberOfIndexPages(numberIndex) {}
	void displayNumPages() const {
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "index pages: ";
		cout << numberOfIndexPages << endl;
	}

protected:
private:
	unsigned numberOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned pages):Book(pages) {}
	void displayNumPages() const {
		cout << "Number of pages: ";
		PrintedMaterial::displayNumPages();
	}
protected:
private:

};

void displayNumberOfPages(const PrintedMaterial& anyPM){
	anyPM.displayNumPages();
}






// tester/modeler code
int main()
{
	
	TextBook t(150,50);
	Novel n(100);
	Magazine m(100);
	cout << "DISPLAYING TEXBOOK" << endl;
	t.displayNumPages();
	cout << "DISPLAY NOVEL" << endl;
	n.displayNumPages();
	cout << "DISPLAY MAGAZINE" << endl;
	m.displayNumPages();
	//PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
	//pm.displayNumPages();
	PrintedMaterial* pmPtr;
	pmPtr = &t;
	cout << "Display a textbook " << endl;
	pmPtr->displayNumPages();
	cout << "using the function to print" << endl;
	displayNumberOfPages(t);
	displayNumberOfPages(m);


	vector< PrintedMaterial* > allType;
	allType.push_back(&t);
	allType.push_back(&n);
	allType.push_back(&m);
	for (size_t index = 0; index < allType.size(); ++index){
		allType[index]->displayNumPages();
		cout << endl;
	}
}

