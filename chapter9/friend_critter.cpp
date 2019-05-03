// Friend Critter
// Demonstrates friend functions and operator overloading

#include <iostream>
#include <string>

using namespace std;

class Critter {

	// make following global functions friends of the Critter class
	friend void Peek(const Critter& critter);
	friend ostream& operator<<(ostream& os, const Critter& critter);

public:
	Critter(const string& name = "");

private:
	string m_Name;
};

Critter::Critter(const string& name):
	m_Name(name) {
}

// Global functions
void Peek(const Critter& critter);
ostream& operator<<(ostream& os, const Critter& critter);

int main() {

	Critter crit("Poochie");

	cout << "Calling Peek() to access crit's private data member, m_Name: " << endl;
	Peek(crit);

	cout << "\nSending crit object to cout with the << operator:" << endl;
	cout << crit;

	return 0;
}

// global friend function that can access all of a Critter object's members
void Peek(const Critter& critter) {
	cout << critter.m_Name << endl;
}

// global friend function that can access all of Critter object's members
// overloads the '<<' operator so you cand send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& critter) {
	os << "Critter Object - ";
	os << "m_Name: " << critter.m_Name;
	return os;
}