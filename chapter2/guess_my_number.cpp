// Guess My Number
// The classic number guessing game

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	srand(static_cast<unsigned int> (time(0)));

	int randomRumber = (rand() % 100) + 1 ;
	int guess;
	int tries = 0;

	cout << "\tWelcome to Guess My Number!\n\n";

	do {
		cout << "Enter a guess: ";
		cin >> guess;
		tries++;

		if (guess < randomRumber) {
			cout << "Too low!\n\n";
		} else if (guess > randomRumber) {
			cout << "Too high!\n\n";
		}

	} while (guess != randomRumber);

	cout << "\n\nThat's it! You got it in " << tries << " guesses!";

	return 0;
}