#pragma once
#include "Enemy.h"
#include <iostream>
class Goblin :
    public Enemy
{
public:
	Goblin(const std::string& name, const std::string& type, double healthPoints, double damage, double xp)
		: Enemy(name, type, healthPoints, damage, xp) {
	}
	// Implementacja metod wirtualnych
	void dialogue(const std::string& text) const override {
		std::cout << "Goblin says: " << text << "\n";
	}
	double heavyAttack(Enemy& enemy) override {
		return enemy.getDamage() + 10;
	}
	double lightAttack(Enemy& enemy) override {
		return enemy.getDamage();
	}
	double specialAttack(Enemy& enemy) override {
		return enemy.getDamage() / 2 + 2;
	}
	void Enemy::heal(int amout) {

		if (getHealthPoints() > 100)
		{
			setHealthPoints(100);
		}
		else {
			setHealthPoints(amout);
		}
	}
};

