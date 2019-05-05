// Dice Roller
// Demonstrates generating random numbers

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	// seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	// generate random number
	int randomNumber = rand();

	// get a number between 1 and 6
	int dice = (randomNumber % 6) + 1;

	cout << "You rolled a " << dice << endl;

	return 0;
}