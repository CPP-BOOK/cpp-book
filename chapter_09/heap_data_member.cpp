// Heap Data Member
// Demonstrates an object with a dynamically allocated data member

#include <iostream>
#include <string>

using namespace std;

class Critter {

public:
	Critter(const string& name = "", int age = 0);
	~Critter(); // destructor prototype
	Critter(const Critter& c); // copy constructor prototype
	Critter& operator=(const Critter& c); // overloaded assignment operator
	void Greet() const;

private:
	string* m_pName;
	int m_Age;
};

Critter::Critter(const string& name, int age) {
	cout << "Constructor called" << endl;
	m_pName = new string(name);
	m_Age = age;
}

Critter::~Critter() {
	cout << "Desctructor called" << endl;
	delete m_pName;
}

Critter::Critter(const Critter& c) {
	cout << "Copy Constructor called" << endl;
	m_pName = new string(*c.m_pName);
	m_Age = c.m_Age;
}

Critter& Critter::operator=(const Critter& c) {
	
	cout << "Overloaded Assignment Operator called" << endl;
	
	if(this != &c) {
		delete m_pName;
		m_pName = new string(*c.m_pName);
		m_Age = c.m_Age;
	}

	return *this;
}

void Critter::Greet() const {
	cout << "I'm " << *m_pName << " and I'm " << m_Age << " years old.";
	cout << "&m_pName: " << &m_pName << endl;
}

void testDesctructor();
void testCopyConstructor(Critter copy);
void testAssignmentOp();

int main() {

	testDesctructor();
	cout << endl;

	Critter crit("Poochie", 5);
	crit.Greet();
	testCopyConstructor(crit);
	crit.Greet();
	cout << endl;

	testAssignmentOp();

	return 0;
}

void testDesctructor() {
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter copy) {
	copy.Greet();
}

void testAssignmentOp() {
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	crit1 = crit2;
	crit1.Greet();
	crit2.Greet();
	cout << endl;

	Critter crit3("crit", 11);
	crit3 = crit3;
	crit3.Greet();
}