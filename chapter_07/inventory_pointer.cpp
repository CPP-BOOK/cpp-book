// Inventory Pointer
// Demonstrates returning a pointer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// returns a pointer to a string element
string* ptrToElement(vector<string>* const pVec, int i);

int main() {

	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	// displays string object that the returned pointer points to
	cout << "Sending the object pointed to by returned pointer to cout:" << endl;
	cout << *(ptrToElement(&inventory, 0)) << "\n\n";

	// assigns one pointer to another -- inexpensive assignment
	cout << "Assigning the returned pointer to another pointer." << endl;
	string* pStr = ptrToElement(&inventory, 1);
	cout << "Sending the object pointed to by new pointer to cout:" << endl;
	cout << *pStr << "\n\n";

	// copies a tring object -- expensive assignment
	cout << "Assigning object pointed to by pointer to a string object." << endl;
	string str = *(ptrToElement(&inventory, 2));
	cout << "Sending the new string object to cout:" << endl;
	cout << str << "\n\n";

	// altering the string object through a returned pointer
	cout << "Altering an object through a returned pointer." << endl;
	*pStr = "Healing Potion";
	cout << "Segind te altered object to cout:" << endl;
	cout << inventory[1] << endl;

	return 0;
}

string* ptrToElement(vector<string>* const pVec, int i) {
	// returns address of the string in position i of vector that pVec points to
	return &(*pVec)[i];
}