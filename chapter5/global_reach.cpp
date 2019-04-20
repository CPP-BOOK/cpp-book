// Global Reach
// Demonstrates global variables

#include <iostream>

using namespace std;

int glob = 10; // global variable

void accessGlobal();
void hideGlobal();
void changelGlobal();

int main() {

	cout << "In main() glob is: " << glob << "\n\n";
	accessGlobal();

	hideGlobal();
	cout << "In main() glob is: " << glob << "\n\n";

	changelGlobal();
	cout << "In main() glob is: " << glob << "\n\n";

	return 0;
}

void accessGlobal() {
	cout << "In accessGlobal() glob is: " << glob << "\n\n";
}

void hideGlobal() {
	int glob = 0; // hide global variable glob
	cout << "In hideGlobal() glob is: " << glob << "\n\n";
}

void changelGlobal() {
	glob = -10; // change global variable glob
	cout << "In changeGlobal() glob is: " << glob << "\n\n";
}

