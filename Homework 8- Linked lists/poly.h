

#ifndef POLY_H
#define POLY_H
#include <vector>
#include <iostream>
#include <string>


struct Node {
	Node(int data, Node*);
	int data;
	Node* next;
};

void addNodeToHead(Node*& list, int data);
void deleteNode(Node*& list);
Node* listCopy(Node* list);

class Polynomial {
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
	friend std::ostream& operator<<(std::ostream& lhs, const Polynomial& rhs);
public:
	Polynomial();
	Polynomial(std::vector<int> coeff);
	~Polynomial();
	Polynomial(const Polynomial& rhs);
	Polynomial& operator=(const Polynomial& rhs);
	Polynomial& operator+=(const Polynomial& rhs);
	int evaluate(const int x);
private:
	int k = 0;
	Node* coefficients = nullptr;
};

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);


#endif