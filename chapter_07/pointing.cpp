// Pointing
// Demonstrates using pointers

#include <iostream>
#include <string>

using namespace std;

int main() {

	int* pAPointer; // declare a pointer

	int* pScore = 0; // declare and initialize a pointer

	int score = 1000;
	pScore = &score; // assign pointer pScore address of variable score

	cout << "Assigning &score to pScore" << endl;
	cout << "&score is: " << &score << endl; // address of score variable
	cout << "pScore is: " << pScore << endl; // address stored in pointer
	cout << "score is: " << score << endl;
	cout << "*pScore is: " << *pScore << "\n\n"; // value pointed to by pointer

	cout << "Adding 500 to score" << endl;
	score += 500;
	cout << "score is: " << score << endl;
	cout << "*pScore is: " << *pScore << "\n\n";

	cout << "Adding 500 to *pScore" << endl;
	*pScore += 500;
	cout << "score is: " << score << endl;
	cout << "*pScore is: " << *pScore << "\n\n";

	cout << "Assigning &newScore to pScore" << endl;
	int newScore = 5000;
	pScore = &newScore;
	cout << "&newScore is: " << &newScore << endl;
	cout << "pScore is: " << pScore << endl;
	cout << "newScore is: " << newScore << endl;
	cout << "*pScore is: " << *pScore << "\n\n";

	cout << "Assigning &str to pStr" << endl;
	string str = "score";
	string* pStr = &str; // pointer to string object
	cout << "str is: " << str << endl;
	cout << "*pStr is: " << *pStr << endl;
	cout << "(*pStr).size() is: " << (*pStr).size() << endl;
	cout << "pStr->size() is: " << pStr->size() << endl;

	return 0;
}