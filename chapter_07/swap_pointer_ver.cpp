// Swap Pointer
// Demonstrates passing constant pointers to alter argument variables

#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main() {

	int myScore = 150;
	int yourScore = 1000;
	cout << "Original values" << endl;
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling badSwap()" << endl;
	badSwap(myScore, yourScore);
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling goodSwap()" << endl;
	goodSwap(&myScore, &yourScore);
	cout << "myScore: " << myScore << endl;
	cout << "yourScore: " << yourScore << endl;

	return 0;
}

void badSwap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;

}

void goodSwap(int* const pX, int* const pY) {
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}