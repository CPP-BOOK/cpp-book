// High Scores
// Demonstrates algorithms

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

void printItems(vector<int> scores) {
	cout << "\nHigh Scores:\n";
	vector<int>::const_iterator iter;
	for (iter = scores.begin(); iter != scores.end() ; iter++) {
		cout << *iter << endl;
	}
}

int main() {

	vector<int>::const_iterator iter;

	cout << "Creating a list of scores.";
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	printItems(scores);

	cout << "\nFinding a score.";
	int score;
	cout << "\nEnter a score to find: ";
	cin >> score;
	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end()) {
		cout << "Score found.\n";
	} else {
		cout << "Score not found.\n";
	}

	cout << "\nRandomizing scores.";
	srand(static_cast<unsigned int> (time(0)));
	random_shuffle(scores.begin(), scores.end());
	printItems(scores);

	cout << "\nSorting scores.";
	sort(scores.begin(), scores.end());
	printItems(scores);

	return 0;
}