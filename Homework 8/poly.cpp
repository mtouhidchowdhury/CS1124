
#include "poly.h"
using namespace std;

Node::Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

void addNodeToHead(Node*& list, int data) {
	if (list == nullptr) {
		list = new Node(data, nullptr);
	}
	else list = new Node(data, list);
}

Node* listCopy(Node* list) {
	if (list == nullptr) return nullptr;
	Node* dup = listCopy(list->next);
	return new Node(list->data, dup);
}

void deleteNode(Node*& list) { //deleting from the front
	if (list == nullptr) delete list;
	else if (list->next == nullptr) {
		delete list;
		return;
	}
	else {
		Node* temp = list;
		list = list->next;
		delete temp;
	}
}

void reverseDisplayPoly(Node* list, int power) { //recrusive function 
	if (list == nullptr) return;
	else {
		if (list->data != 0) {
			reverseDisplayPoly(list->next, ++power); //power starts as -1
			if (power == 0) { 
				cout << list->data; 
			}
			else if (power == 1) { //if power is 1, x is the first power
				cout << list->data << "x + ";
			}
			else if (power > 1) { 
				cout << list->data << "x^" << power << " + ";
			}
		}
	}
}

Polynomial::Polynomial() {
	coefficients = new Node(0, nullptr);
}

Polynomial::Polynomial(vector<int> coeff) : k(0) {
	for (size_t i = 0; i < coeff.size(); i++) {
		addNodeToHead(coefficients, coeff[i]);
	}
	k = coeff.size() - 1;
}

Polynomial::~Polynomial() {
	for (int i = 0; i <= k; i++) { //used this instead of while loop, because less lines to type and always works.
		deleteNode(coefficients);
	}
}

Polynomial::Polynomial(const Polynomial& rhs) {
	k = rhs.k;
	coefficients = listCopy(rhs.coefficients);
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this != &rhs) {
		for (int i = 0; i <= k; i++) {
			deleteNode(coefficients);
		}
		k = rhs.k;
		coefficients = listCopy(rhs.coefficients);
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	Node* temp1 = coefficients;
	Node* temp2 = rhs.coefficients;
	while (temp1 != nullptr || temp2 != nullptr) {
		if (temp1 == nullptr) {
			temp1 = new Node(temp2->data, nullptr);
		}
		else if (temp2 == nullptr) {
			temp1 = nullptr;
		}
		else {
			temp1->data += temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	return *this;
}

int Polynomial::evaluate(const int x) {
	int sum = 0;
	int power = 0;
	Node* temp = coefficients;
	while (temp != nullptr) {
		sum += (temp->data)*(pow(x, power));
		power++;
		temp = temp->next;
	}
	return sum;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
	if (lhs.k != rhs.k) return false;
	else {
		bool yes = true;
		Node* temp1 = lhs.coefficients;
		Node* temp2 = rhs.coefficients;
		while (yes == true && temp1 != nullptr) {
			if (temp1->data == temp2->data) {
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else yes = false;
		}
		return yes;
	}
}

ostream& operator<<(ostream& lhs, const Polynomial& rhs) {
	if (rhs.coefficients->data != 0) {
		reverseDisplayPoly(rhs.coefficients, -1); //prints backwards, and needs to start off with -1 so when called in recursion func, it increments to 0.
	}
	else lhs << 0;
	lhs << endl;
	return lhs;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
	return !(lhs == rhs);
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial p = lhs;
	p += rhs;
	return p;

}