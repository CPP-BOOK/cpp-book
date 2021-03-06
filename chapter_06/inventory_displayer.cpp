// Inventory Displayer
// Demonstrates constant references
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//parameter vec is a constant reference to a vector of strings
void display(const vector<string>& vec);

int main() {

	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	display(inventory);

	return 0;
}

void display(const vector<string>& vec) {
	
	cout << "Your items: " << endl;
	vector<string>::const_iterator iter;

	for (iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << endl;
	}
}