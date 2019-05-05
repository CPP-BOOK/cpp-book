// Menu Chooser
// Demonstrates the switch statement
// (this version uses an enum for 'difficulty')

#include <iostream>
using namespace std;

int main() {

	enum difficulty {EASY=1, NORMAL, HARD};

	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n";

	int choice;
	cout << "Choice: ";
	cin >> choice;

	switch (choice) {
	case difficulty::EASY:
		cout << "You picked Easy.\n";
		break;
	case difficulty::NORMAL:
		cout << "You picked Normal.\n";
		break;
	case difficulty::HARD:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice.\n";
	}

	return 0;
}