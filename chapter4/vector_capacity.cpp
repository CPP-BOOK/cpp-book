// Vector Capacity
// Demonstrates vector's capacity

#include <iostream>
#include <vector>

using namespace std;

int main() {

	cout << "Creating a 10 element vector.\n";
	vector<int> scores(10, 0); // initialize all 10 elements to 0
	cout << "Vector size is: " << scores.size() << endl;
	cout << "Vector capacity is: " << scores.capacity() << endl;

	cout << "Adding a score.\n";
	scores.push_back(0); // memory is reallocated to accommodate growth
	cout << "Vector size is: " << scores.size() << endl;
	cout << "Vector capacity is: " << scores.capacity() << endl;

	cout << "\n\nCreating another 10 element vector.\n";
	vector<int> scores2(10, 0); // initialize all 10 elements to 0
	cout << "Vector size is: " << scores2.size() << endl;
	cout << "Vector capacity is: " << scores2.capacity() << endl;

	cout << "Reserving memory for vector.\n";
	scores2.reserve(11);
	cout << "Vector capacity is: " << scores2.capacity() << endl;
	cout << "Adding a score.\n";
	scores2.push_back(0); // memory is reallocated to accommodate growth
	cout << "Vector size is: " << scores2.size() << endl;
	cout << "Vector capacity is: " << scores2.capacity() << endl;

	return 0;
}