// Inventory Referencer
// Demonstrates returning a reference

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// returns a reference to a string
string& refToELement(vector<string>& rInventory, int i);

int main() {

	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	// displays string that the returned reference refers to
	cout << "Sending the return reference to cout:" << endl;
	cout << refToELement(inventory, 0) << "\n\n";

	// assingns one reference to another -- inexpensive assignment
	cout << "Assigning the returned reference to another reference." << endl;
	string& rStr = refToELement(inventory, 1);
	cout << "Sending the new reference to cout:" << endl;
	cout << rStr << "\n\n";

	// copies a string object -- expensive assignment
	cout << "Assigning the returned reference to a string object." << endl;
	string str = refToELement(inventory, 2);
	cout << "Sending the new string object to cout:" << endl;
	cout << str << "\n\n";

	// altering the string object thorugh a returned reference
	cout << "Altering an object through a returned reference." << endl;
	rStr = "Healing Potion";
	cout << "Sending the altered object to cout:" << endl;
	cout << inventory[1] << endl;

	return 0;
}

string& refToELement(vector<string>& rInventory, int i) {
	return rInventory[i];
}