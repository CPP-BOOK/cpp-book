// Blackjack
// Plays a simple version of the casino game of backjack; for 1-7 players

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/*
CLASS CARD
*/
class Card {

public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

	// overloading '<<' operator so can send Card object to standard output
	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	// returns the value of a card, 1-11
	int GetValue() const;

	// flips a card; if face up, becomes face down and vice versa
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const {

	// if a card id face down, its value is 0
	int value = 0;
	if (m_IsFaceUp) {
		// value is numer showing on card
		value = m_Rank;
		// value is 10 for face cards
		if (value > 10) {
			value = 10;
		}
	}
	return value;
}

void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}

/*
CLASS HAND
*/
class Hand {

public:
	Hand();
	virtual ~Hand();

	// adds a card to the hand
	void Add(Card* pCard);

	// clears hand of all cards
	void Clear();

	// gets hand total value, intelligently treats aces as 1 or 11
	int GetTotal() const;

protected:
	vector<Card*> m_Cards;
};

Hand::Hand() {
	m_Cards.reserve(7);
}

Hand::~Hand() {
	Clear();
}

void Hand::Add(Card* pCard) {
	m_Cards.push_back(pCard);
}

void Hand::Clear() {

	// iterate through vector, freeing all memory on the heap
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
		delete *iter;
		*iter = 0;
	}

	// clera vector of pointers
	m_Cards.clear();
}

int Hand::GetTotal() const {
	// if no cards in hand, return 0
	if (m_Cards.empty()) {
		return 0;
	}

	// if a first card has value of 0, then card is face down; return 0
	if (m_Cards[0]->GetValue() == 0) {
		return 0;
	}

	// add up card values, treat each ace as 1
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
		total += (*iter)->GetValue();
	}

	// determine if hand contains an ace
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
		if ((*iter)->GetValue() == Card::ACE) {
			containsAce = true;
		}
	}

	// if hand contains ace and total is low enough, treat ace as 11
	if (containsAce && total <= 11) {
		// add only 10 since we've already added 1 for the ace
		total += 10;
	}

	return total;
}

/*
CLASS GENERIC PLAYER
*/
class GenericPlayer : public Hand {

	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();

	// indicates wether or not generic player wants to keep hitting
	virtual bool IsHitting() const = 0;

	// returns whether generic player has busted - has a total greater than 21
	bool IsBusted() const;

	// announced that the generic player busts
	void Busts() const;

protected:
	string m_Name;
};

GenericPlayer::GenericPlayer(const string& name): m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::IsBusted() const {
	return (GetTotal() > 21);
}

void GenericPlayer::Busts() const {
	cout << m_Name << " busts." << endl;
}

/*
CLASS PLAYER
*/
class Player : public GenericPlayer {

public:
	Player(const string& name = "");
	virtual ~Player();

	// returns whether or not the player wants another hit
	virtual bool IsHitting() const;

	// announces that the player wins
	void Win() const;

	// announces that the player loses
	void Lose() const;

	// announces that the player pushes
	void Push() const;
};

Player::Player(const string& name):	GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
	cout << m_Name << ", do you want a hit? (Y/N):";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const {
	cout << m_Name << " wins." << endl;
}

void Player::Lose() const {
	cout << m_Name << " loses." << endl;
}

void Player::Push() const {
	cout << m_Name << " pushes." << endl;
}

/*
CLASS HOUSE
*/

class House : public GenericPlayer {

public:
	House(const string& name = "House");
	virtual ~House();

	// indicates whether house is hitting - will always hit on 16 or less
	virtual bool IsHitting() const;

	// flips over first card
	void FlipFirstCard();
};

House::House(const string& name) : GenericPlayer(name) {}

House::~House() {}

bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

void House::FlipFirstCard() {
	if (!(m_Cards.empty())) {
		m_Cards[0]->Flip();
	} else {
		cout << "No card to flip!" << endl;
	}
}

/*
CLASS DECK
*/
class Deck : public Hand {

public:
	Deck();
	virtual ~Deck();

	// create a standard deck of 52 cards
	void Populate();

	// shuffle cards
	void Shuffle();

	// deal one card to a hand
	void Deal(Hand& hand);

	// give additional cards to a generic player
	void AdditionalCards(GenericPlayer& genericPlayer);
};

Deck::Deck() {
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck() {}

void Deck::Populate() {
	Clear();

	// create standard deck
	for (int s = Card::CLUBS; s <= Card::SPADES; s++) {
		for (int r = Card::ACE; r <= Card::KING; r++) {
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle() {
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& hand) {
	if (!m_Cards.empty()) {
		hand.Add(m_Cards.back());
		m_Cards.pop_back();
	} else {
		cout << "Out of cards. Unable to deal.";
	}
}

void Deck::AdditionalCards(GenericPlayer& genericPlayer) {
	cout << endl;
	// continue to deal a card as long as generic player isn't busted and wants another hit
	while (!genericPlayer.IsBusted() && genericPlayer.IsHitting()) {
		Deal(genericPlayer);
		cout << genericPlayer << endl;

		if (genericPlayer.IsBusted()) {
			genericPlayer.Busts();
		}
	}
}

/*
CLASS GAME
*/

class Game {

public:
	Game(const vector<string>& names);
	~Game();

	// plays the game of blackjack
	void Play();

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};

Game::Game(const vector<string>& names) {
	//create a vector of players from a vector of names
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); pName++) {
		m_Players.push_back(Player(*pName));
	}

	// seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

Game::~Game() {}

void Game::Play() {
	// deal initial 2 cards to everyone
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; i++) {
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}

	// hide house's first card
	m_House.FlipFirstCard();

	// display everyone's hand
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
		cout << *pPlayer << endl;
	}

	cout << m_House << endl;

	// deal additional cards to players
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
		m_Deck.AdditionalCards(*pPlayer);
	}

	// reveal house's first card
	m_House.FlipFirstCard();
	cout << endl << m_House;

	// deal additional cards to house
	m_Deck.AdditionalCards(m_House);

	if (m_House.IsBusted()) {
		// everyone still playing wins
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
			if (!pPlayer->IsBusted()) {
				pPlayer->Win();
			}
		}
	} else {
		// compare each player still playing to house
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
			if (!pPlayer->IsBusted()) {
				if (pPlayer->GetTotal() > m_House.GetTotal()) {
					pPlayer->Win();
				} else if (pPlayer->GetTotal() < m_House.GetTotal()) {
					pPlayer->Lose();
				} else {
					pPlayer->Push();
				}
			}
		}
	}

	// remove everyone's cards
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
		pPlayer->Clear();
	}

	m_House.Clear();
}

// function prototypes
ostream& operator<<(ostream& os, const Card& card);
ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);

int main() {
	cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7) {
		cout << "How many players? (1-7):";
		cin >> numPlayers;
	}

	vector<string> names;
	string name;

	for (int i = 0; i < numPlayers; i++) {
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}

	cout << endl;

	// the game loop
	Game game(names);
	char again = 'y';
	while (again != 'n' && again != 'N') {
		game.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}

	return 0;
}

// overloads '<<'' operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& card) {
	const string RANKS[] = {"0", "A", "2", "3" , "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	const string SUITS[] = {"c", "d", "h", "s"};

	if (card.m_IsFaceUp) {
		os << RANKS[card.m_Rank] << SUITS[card.m_Suit];
	} else {
		os << "XX";
	}

	return os;
}

// overloads '<<'' operator so a GenericPlayer object can be sent to cout
ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer) {
	os << genericPlayer.m_Name << ":\t";

	vector<Card*>::const_iterator pCard;
	if (!genericPlayer.m_Cards.empty()) {
		for (pCard = genericPlayer.m_Cards.begin(); pCard != genericPlayer.m_Cards.end(); pCard++) {
			os << *(*pCard) << "\t";
		}

		if (genericPlayer.GetTotal() != 0) {
			cout << "(" << genericPlayer.GetTotal() << ")";
		}
	} else {
		os << "<empty>";
	}

	return os;
}

