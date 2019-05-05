// Referencing
// Demonstrates using references

#include <iostream>
using namespace std;

int main() {

	int score = 1000;
	int& rScore = score; // create reference

	cout << "score is: " << score << "\n";
	cout << "rScore is: " << rScore << "\n\n";

	cout << "Adding 500 to score\n";
	score += 500;
	cout << "score is: " << score << "\n";
	cout << "rScore is: " << rScore << "\n\n";

	cout << "Adding 500 to rScore\n";
	rScore += 500;
	cout << "score is: " << score << "\n";
	cout << "rScore is: " << rScore << "\n\n";

	return 0;
}