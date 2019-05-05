//Designers Network
// Demonstrates logical operators

#include <iostream>
#include <string>

using namespace std;

int main() {

	string username;
	string password;
	bool success = false;

	cout << "\tGame Designer's Network\n";

	do {

		cout << "\nUsername: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		if (username == "Meier" && password == "civilization") {
			cout << "\nHey, Sid.";
			success = true;
		} else if (username == "Miyamoto" && password == "mario") {
			cout << "\nHey, Miyamoto.";
			success = true;
		} else if (username == "Wright" && password == "sims") {
			cout << "\nHey, Will.";
			success = true;
		} else if (username == "guest" || password == "guest") {
			cout << "\nWelcome, guest.";
			success = true;
		} else {
			cout << "\nYour login failed.";
			success = false;
		}

	} while (!success);

	return 0;
}