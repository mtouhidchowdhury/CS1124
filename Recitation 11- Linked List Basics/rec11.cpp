/*
Mohammed Touhid Chowdhury
mtc405
N14108583
recitation 11
*/

#include <cstdlib> // To allow NULL if no other includes
#include <iostream>
using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

Node* findNode(int data, Node* headPtr) {
	Node* temp = headPtr;
	while (temp) {
		if (temp->data == data) {
			return temp;
		}
		else {
			temp = temp->link;
		}
	}
	return NULL;
}

void spliceList(Node* iniPtr, Node* splPtr) {
	if (splPtr != NULL) { // Check if even need to do this
		if (iniPtr->link == NULL) { // If the pointer is at the end, just link to splice
			iniPtr->link = splPtr;
		}
		else {
			Node* lastPtr = iniPtr->link;
			iniPtr->link = splPtr; // Redirect original pointer to first splice pointer
			Node* p = splPtr;
			while (p->link != NULL) { // Loop splice to end
				p = p->link;
			}
			p->link = lastPtr; // Redirect end splice pointer to pointer after original
		}
	}
}

Node* findMatch(Node* listPtr, Node* matchPtr) {
		Node* p1 = listPtr;
		Node* p2 = matchPtr;
		while (p1 != NULL)
		{
			if (p1->data == p2->data)
			{
				// First condition, if the data does not equal each other in each list
				Node* temp = p1;
				while (p1 != NULL && p2 != NULL)
				{
					if (p1->data != p2->data)
					{
						break;
					}
					else
					{
						p1 = p1->link;
						p2 = p2->link;
					}
				}
				// Second condition, if the data in list 2 runs out and hits NULL first
				if (p2 == NULL)
				{
					return temp;
				}
				else
					// Third condition, if the data in list 1 runs out and hits NUll first
				{
					p2 = matchPtr;
					p1 = temp;
				}
			}
			p1 = p1->link;
		}
		cout << "Failed to match";
		return NULL;
}

int main() {
	cout << "Part One: " << endl;
	Node* listOne = NULL;
	Node* listTwo = NULL;
	listInsertHead(1, listOne);
	listInsertHead(9, listOne);
	listInsertHead(7, listOne);
	listInsertHead(5, listOne);

	listInsertHead(2, listTwo);
	listInsertHead(3, listTwo);
	listInsertHead(6, listTwo);

	cout << "L1: ";
	Node* coutList = listOne;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	cout << "L2: ";
	coutList = listTwo;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	cout << "Target: ";
	coutList = findNode(7, listOne);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "Splicing L2 at target in L1" << endl;
	spliceList(findNode(7, listOne), listTwo);

	cout << "L1: ";
	coutList = listOne;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	cout << "L2: ";
	coutList = listTwo;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << "\n\n=====================\n\n";

	cout << "Part Two: " << endl;
	Node* listThree = NULL;
	Node* listFour = NULL;
	Node* listFive = NULL;
	Node* listSix = NULL;
	Node* listSeven = NULL;
	Node* listEight = NULL;
	Node* listNine = NULL;
	listInsertHead(6, listThree);
	listInsertHead(5, listThree);
	listInsertHead(4, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(1, listThree);

	listInsertHead(1, listFour);

	listInsertHead(9, listFive);
	listInsertHead(3, listFive);

	listInsertHead(3, listSix);
	listInsertHead(2, listSix);

	listInsertHead(6, listSeven);
	listInsertHead(5, listSeven);
	listInsertHead(4, listSeven);
	listInsertHead(2, listSeven);

	listInsertHead(4, listEight);
	listInsertHead(2, listEight);
	listInsertHead(3, listEight);
	listInsertHead(2, listEight);

	listInsertHead(7, listNine);
	listInsertHead(6, listNine);
	listInsertHead(5, listNine);

	cout << "Target: ";
	coutList = listThree;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\nAttempt Match: ";
	coutList = listFour;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	coutList = findMatch(listThree, listFour);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\nAttempt Match: ";
	coutList = listFive;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	coutList = findMatch(listThree, listFive);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\nAttempt Match: ";
	coutList = listSix;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	coutList = findMatch(listThree, listSix);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\nAttempt Match: ";
	coutList = listSeven;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
	coutList = findMatch(listThree, listSeven);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\nAttempt Match: ";
	coutList = listEight;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	coutList = findMatch(listThree, listEight);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\nAttempt Match: ";
	coutList = listNine;
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	coutList = findMatch(listThree, listNine);
	while (coutList) {
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
}
