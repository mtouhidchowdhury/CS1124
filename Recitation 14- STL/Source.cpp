#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void listDisplay(const list<int>& lc) {
	for (list<int>::const_iterator l = lc.begin(); l != lc.end(); l++) {
		cout << *l << ' ';
	}
	cout << endl;
}

void listDisplay2(const list<int>& lc) {
	for (int l : lc) {
		cout << l << ' ';
	}
	cout << endl;
}

void listDisplay3(const list<int>& lc) {
	for (auto l = lc.begin(); l != lc.end(); ++(++l)) {
		cout << *l << ' ';
	}
	cout << endl;
}

list<int>::const_iterator findInList(list<int>::const_iterator b, list<int>::const_iterator e, int findInt) {
	for (list<int>::const_iterator l = b; l != e; ++l) {
		if ((*l) == findInt) return l;
	}
	return e;
}


template <typename it, typename type>
it ourFInd(it start, it end, type target) {
	cout << "This is our find: " << endl;
	for (it l = start; l != end; ++l) {
		if (*l == target) return l;
	}
	return end;
}

bool isEven(int a) { return a % 2 == 0; }

int main() {
	// //1
	// vector<int> vi{21,1,3,8,5,34,2,1};
	// for(int a : vi) {
	// 	cout << a << ' ';
	// }
	// cout << endl;
	// //2 - 3
	// list<int> lc(vi.begin(), vi.end());
	// for(int a : lc) {
	// 	cout << a << ' ';
	// }
	// cout << endl;
	// sort(vi.begin(), vi.end());
	// for(int a : vi) {
	// 	cout << a << ' ';
	// }
	// cout << endl;
	// //sort(lc.begin(), lc.end()) //doesnt work
	// //4 - 5
	// for(size_t i = 0; i < vi.size(); i+=2) {
	// 	cout << vi[i] << ' ';
	// }
	// cout << endl;
	// lc.sort();
	// 	for(int a : lc) {
	// 	cout << a << ' ';
	// }
	// cout << endl;
	// //6
	// for(vector<int>::iterator i = vi.begin(); i != vi.end(); i+=2) {
	// 	cout << *i << ' ';
	// }
	// //7
	// cout << endl;
	// for(list<int>::iterator l = lc.begin(); l != lc.end(); ++(++l)) {
	// 	cout << *l << ' ';
	// }
	// cout << endl;
	// //8
	// listDisplay(lc);
	// //9
	// listDisplay2(lc);
	// //10
	// listDisplay3(lc);
	// //11
	// cout << "Found: " << *(findInList(lc.begin(),lc.end(),3)) << endl;
	// //12
	// cout << "Found: " << *findInList2(lc.begin(),lc.end(), 3) << endl;
	// //13
	// cout << "Found: " << *find(lc.begin(),lc.end(),3) << endl;
	// //14
	// cout << "Found: " << *find_if(vi.begin(), vi.end(), isEven) << endl;
	// cout << "Found: " << *find_if(lc.begin(), lc.end(), isEven) << endl;
	// //15
	// cout << "Found: " << *find_if(vi.begin(), vi.end(), [] (int n) {return n%2 == 0;}) << endl;
	// cout << "Found: " << *find_if(lc.begin(), lc.end(), [] (int n) {return n%2 == 0;}) << endl;
	// //16
	// int arr[8];
	// copy(lc.begin(), lc.end(), arr);
	// for(auto a: arr) {
	// 	cout << a << ' ';
	// }
	// cout << endl;
	// cout << *find(arr, arr+8, 3) << endl;
	// //17-18
	// cout << *ourFInd(arr, arr+8, 3) << endl;
	// cout << *ourFInd(lc.begin(), lc.end(), 3) << endl;



	//19
	ifstream ifs("pooh-nopunc.txt");
	if (!ifs) {
		cerr << "No file found";
		exit(1);
	}
	// vector<string> theDoc;
	string word;
	// while(ifs >> word) {
	// 	vector<string>::iterator v = find(theDoc.begin(),theDoc.end(),word);
	// 	if(v == theDoc.end()) {
	// 		theDoc.push_back(word);
	// 	}
	// }
	// for(string& aWord: theDoc) {
	// 	cout << aWord << ' ';
	// }
	// cout << endl;
	// ifs.close();

	//20
	// set<string> theWords;
	// while(ifs >> word) {
	// 	theWords.insert(word);
	// }
	// for(const string& aWord: theWords) {cout << aWord << ' ';}
	// cout << endl;
	// ifs.close();

	//21
	int i = 0;

	map<string, vector<int>> wordMap;
	while (ifs >> word) {
		wordMap[word].push_back(i);
		i++;
	}
	for (auto s : wordMap) {
		cout << s.first << ":" << endl;
		for (auto x : s.second) {
			cout << x << ", ";
		}
		cout << endl;
	}
}