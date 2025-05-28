#include "Hero.h"

double Enemy::heavyAttack(Enemy& enemy) {
	
	return enemy.getDamage() + 10; 
}
double Enemy::lightAttack(Enemy& enemy) {
	return enemy.getDamage();
}
double Enemy::specialAttack(Enemy& enemy) {
	return enemy.getDamage()/2 + 2;
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
void Enemy::dialogue(const std::string& text) const {
	std::cout << "" << text <<"\n";
}