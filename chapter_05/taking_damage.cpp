// Taking Damage
// Demonstrates function inlining

#include <iostream>
using namespace std;

int radiation(int health);

int main() {

	const int RADIATION_HITS = 3; // Times hit by the radiation
	int health = 80;
	cout << "Your health is " << health << "\n\n";

	for (int i = 0; i < RADIATION_HITS; i ++) {
		health = radiation(health);
		cout << "After radiation exposure your health is " << health << "\n\n";
	}

	return 0;
}

inline int radiation(int health) {
	return (health / 2);
}
