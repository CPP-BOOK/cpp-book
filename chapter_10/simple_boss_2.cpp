// Simple Boss 2.0
// Demonstrates access control under inheritance

#include <iostream>
using namespace std;

class Enemy {

public:
	Enemy();
	void Attack() const;

protected:
	int m_Damage;
};

Enemy::Enemy():
	m_Damage(10){
}

void Enemy::Attack() const {
	cout << "Attack inflicts " << m_Damage << " damage points!" << endl;
}

class Boss: public Enemy {

public:
	Boss();
	void SpecialAttack() const;

private:
	int m_DamageMultiplier;
};

Boss::Boss():
	m_DamageMultiplier(3) {
}

void Boss::SpecialAttack() const {
	cout << "Special Attack inflicts " << m_Damage * m_DamageMultiplier << " damage points!" << endl;
}

int main() {

	cout << "Creating an enemy." << endl;
	Enemy enemy;
	enemy.Attack();

	cout << endl << "Creating a boss." << endl;
	Boss boss;
	boss.Attack();
	boss.SpecialAttack();

	return 0;
}