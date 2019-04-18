// Hero's Inventory 2.0
// Demonstrates vectors

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This function is not in the original book's exercise
void printItems(vector<string> inventory) {
	cout << "\nYour items:\n";
	for (unsigned int i = 0; i < inventory.size(); i++) {
		cout << inventory[i] << endl;
	}
}

int main() {

	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	cout << "You have " << inventory.size() << " items.\n";

	printItems(inventory);

	cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	
	printItems(inventory);

	cout << "\nThe item name '" << inventory[0] << "' has ";
	cout << inventory[0].size() << " letters in it.\n";

	cout << "\nYour shield is destroyed in a fierce battle.";
	inventory.pop_back();

	printItems(inventory);

	cout << "\nYou were robbed of all of your possessions by a thief.";
	inventory.clear();

	if(inventory.empty()) {
		cout << "\nYou have nothing.\n";
	} else {
		cout << "\nYou have at least one item.\n";
	}

	return 0;
}


