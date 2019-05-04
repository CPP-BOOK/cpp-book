// Game Lobby
// Simulates a game lobby where players wait

#include <iostream>
#include <string>

using namespace std;

class Player {

public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

private:
	string m_Name;
	Player* m_pNext; // pointer to next player in list
};

Player::Player(const string& name):
	m_Name(name),
	m_pNext(0) {
}

string Player::GetName() const {
	return m_Name;
}

Player* Player::GetNext() const {
	return m_pNext;
}

void Player::SetNext(Player* next) {
	m_pNext = next;
}

class Lobby {

	friend ostream& operator<<(ostream& os, const Lobby& lobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;
};

Lobby::Lobby():
	m_pHead(0) {
}

Lobby::~Lobby() {
	Clear();
}

void Lobby::AddPlayer() {

	// create a new player node
	cout << "Please enter the name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);

	// if list is empty, make head of list this new player
	if (m_pHead == 0) {
		m_pHead = pNewPlayer;
	} else { // otherwise find the end of the list and add the player there
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0) {
			pIter = pIter->GetNext();
		}

		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer() {
	if (m_pHead == 0) {
		cout << "The game lobby is empty. No one to remove!" << endl;
	} else {
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear() {
	while (m_pHead != 0) {
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& lobby) {
	Player* pIter = lobby.m_pHead;
	os << "\nHere's who's in the game lobby:" << endl;
	if (pIter == 0) {
		os << "The lobby is empty." << endl;
	} else {
		while (pIter != 0) {
			os << pIter->GetName() << endl;
			pIter = pIter->GetNext();
		}
	}

	return os;
}

int main() {

	Lobby myLobby;
	int choice;

	do {
		cout << myLobby;
		cout << endl << "GAME LOBBY" << endl;
		cout << "0 - Exit the program" << endl;
		cout << "1 - Add a player to the lobby" << endl;
		cout << "2 - Remove a player from the lobby" << endl;
		cout << "3 - Clear the lobby" << endl;
		cout << endl << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 0: cout << "Good-bye." << endl; break;
		case 1: myLobby.AddPlayer(); break;
		case 2: myLobby.RemovePlayer(); break;
		case 3: myLobby.Clear(); break;
		default: cout << "That was not a valid choice." << endl;
		}

	} while (choice != 0);
}