#include <string>
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

void addNode(Node*& list, int data) {
	if(list == nullptr) {
		list = new Node(data, nullptr);
	}
	else {
		Node* temp = list;
		while(temp->next!=nullptr) {
			temp = temp->next;
		}
		temp->next = new Node(data, nullptr);
	}
}

void deleteNode(Node*& list, int data) {
	if(list == nullptr) {
		cout << "Nothing to delete" << endl;
		return;
	}
	else if(list->next == nullptr) {
		Node* temp = list;
		list = nullptr;
		delete temp;
	}
	else {
		Node* temp = list;
		while(temp->next->data!=data) {
			temp = temp->next;
		}
		Node* temp2;
		temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;
	}
}

void displayList(Node* list) {
	Node* temp = list;
	while(temp!=nullptr) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

unsigned intBinary(int bin) {
	if(bin < 2) {cout << "RIGHT NOW, FUNCTION IS WHERE BIN = " << bin << endl; cout << bin << endl;
	cout << "RIGHT NOW, FUNCTION RETURNS AND IS WHERE BIN = " << bin << endl;}
	else {
		cout << "RIGHT NOW, FUNCTION IS WHERE BIN = " << bin << endl;
		intBinary(bin/2);
		cout << "RIGHT NOW, FUNCTION RETURNS AND IS WHERE BIN = " << bin << endl;
		cout << bin%2 << endl;
	}
}

int sumLists(Node* list1, Node* list2) {
	if (list1->next == nullptr) return (list1->data + list2->data);
	else return list1->data + list2->data + sumLists(list1->next, list2->next);
}

Node* addList(Node* list1, Node* list2) {
	if(list1==nullptr) return nullptr;
	Node* dup = addList(list1->next, list2->next);
	return new Node(list1->data + list2->data, dup);
}

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
	if(root->left == nullptr && root->right == nullptr) {
		return root->data;
	}
	else {
		if(root->right ==nullptr) return root->left->data;
		else if(root->left == nullptr) return root->right->data;
		else {
			int r = max(root->right);
			int l = max(root->left);
			if(r>l) {
				if(r> root->data) return r;
				else return root->data;
			}
			else {
				if(l > root->data) return l;
				else return root->data;
			}
		}
	}
}

int charSum(char* arr) {
	if(*(arr+1) == '\0') return int(*arr);
	else return int(*arr) + charSum(arr+1);
}

int charSearch(char* arr, int start, int end, char letter) {
	int mid = (end + (start-end) / 2);
	if(start > end) return -1;
	if(int(arr[mid]) < int(letter))
		charSearch(arr,mid+1, end, letter);
	else if(int(arr[mid]) == int(letter)) {
		return mid;
	}
	else {
		charSearch(arr,start,mid-1, letter);
	}
}

void foo(int n) { 
   if (n > 1) { 
      cout << 'a'; 
      foo(n/2); 
      cout << 'b'; 
      foo(n/2); 
   } 
   cout << 'c'; 
}

int main() {
	//test binary
	int n = 11;
	intBinary(n);
	//test add lists
	Node* list1=nullptr;
	addNode(list1, 1);
	addNode(list1, 1);
	addNode(list1, 1);
	Node* list2=nullptr;
	addNode(list2, 8);
	addNode(list2, 9);
	addNode(list2, 10);
	displayList(list1);
	displayList(list2);
	cout << "The sum of the lists are: " << sumLists(list1,list2) << endl;
	//add two lists together
	displayList(addList(list1, list2));
	//max in a binary tree
	TNode q(1), w(2), r(4), d(8, &q, &w), z(39), e(16, &r, &z), f(32, &d, &e);
 	cout << "The max in this tree is: " << max(&f) << endl;
 	//c strings
 	char a('A'), b;
	// a contains 'A' whose ASCII value is 65
	cout << "a contains '" << a
	     << "' whose ASCII value is " << int(a) << endl;  // note the cast to int on this line
	b = a + 1;
	// b contains 'B' whose ASCII value is 66
	cout << "b contains '" << b
	     << "' whose ASCII value is " << int(b) << endl;  // note the cast to int on this line
	char c( 'a' - 17 + 's'-'a' ); // not sure what number will be stored or what character it represents but let's see
	cout << "b contains '" << b
	     << "' whose ASCII value is " << int(b) << endl;  // note the cast to int on this line
	cout << "c contains '" << c
	<< "' whose ASCII value is " << int(c) << endl;  // note the cast to int on this line

	//total sum of ascii values in a c-string
	cout << int('a'+'b'+'c') << endl;
	char arr[20]="abcdef";
	cout << "The sum is: " << charSum(arr) << endl;

	//binary character array search
	cout << "The index for the letter d is: " << charSearch(arr, 0, 9, 'd');

	//part 6
	foo(4);
}
