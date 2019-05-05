// Swap
// Demonstrates passing references to alter argument variables

#include <iostream>
using namespace std;

void badSwap(int x, int y);
void goodSwap(int& rX, int& rY);

int main() {

	int myScore = 150;
	int yourScore = 1000;

	cout << "Original values\n";
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling badSwap()" << endl;
	badSwap(myScore, yourScore);
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling goodSwap()" << endl;
	goodSwap(myScore, yourScore);
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << "\n\n";

	return 0;
}

void badSwap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int& rX, int& rY) {
	int temp = rX;
	rX = rY;
	rY = temp;
}