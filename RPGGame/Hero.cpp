#include "Hero.h"
#include <iostream>
#include "random"
Hero::Hero(const std::string& name, double healthPoints, int level, double XP,
    int strength, int intelligence, int dexterity, int luck, int endurance,double mana)
    : Character(name, healthPoints, level, XP, strength, intelligence, dexterity, luck, endurance, 0.0),
    endurance(endurance), hand(nullptr) {
}


int Hero::getEndurance() const {
    return endurance;
}

void Hero::setEndurance(int value) {
    endurance = value;
}

// Gettery i settery dla broni w rêku
Weapon* Hero::getHand() const {
    return hand;
}

void Hero::setHand(Weapon* weapon) {
    hand = weapon;
}

void Hero::heavyAttack(Enemy& enemy) {
	enemy.setHealthPoints(enemy.getHealthPoints() - (strength * 2 + dexterity));
}

void Hero::lightAttack(Enemy& enemy) {
    // Implementacja póŸniej
    enemy.setHealthPoints(enemy.getHealthPoints() - (strength + dexterity / 2));
}


void Hero::dodge() {
    // Implementacja póŸniej

}

void Hero::reflect() {
    // Implementacja póŸniej

}

void Hero::ignis(Enemy& enemy) {
    // Implementacja póŸniej
	enemy.setHealthPoints(enemy.getHealthPoints() - (intelligence * 1.5 + dexterity / 2));
}

void Hero::heal(Hero& hero) {
    // Implementacja póŸniej
	
}

void Hero::waterBomb(Enemy& enemy) {
    // Implementacja póŸniej
	enemy.setHealthPoints(enemy.getHealthPoints() - (intelligence * 1.2 + dexterity / 3));
}

bool Hero::perceptionTest(int event) const {
	int random = std::rand() % 20 + 1; 
	if (random < event) {
		std::cout << "Perception test failed." << std::endl;
		return false;
	}
    return true;
}
void Hero::CreateHero( Weapon& sword, Weapon& bow, Weapon& magicStick) {
	std::string name;
	std::cout << "Podaj imiê bohatera: ";
	std::cin >> name;
	setName(name);
	setHealthPoints(5);
	setLevel(0);
	setXP(0);
	setStrength(5);
	setIntelligence(5);
	setDexterity(5);
	setLuck(5);
	setEndurance(5);
	setMana(5);
	std::cout << "Wybierz broñ:\n";
	std::cout << "1. Miecz\n";
	std::cout << "2. £uk\n";
	std::cout << "3. Ró¿d¿ka\n";
	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		setHand(&sword);
		break;
	case 2:
		setHand(&bow);
		break;
	case 3:
		setHand(&magicStick);
		break;
	default:
		std::cout << "Nieprawid³owy wybór. Domyœlnie wybrano miecz.\n";
		setHand(&sword);
		break;
	}
	std::cout << "Bohater stworzony pomyœlnie!\n";
}

void Hero:: levelUp() {
	int newPointsLVL = 5;
	int newHP;
	int newStrength;
	int newIntelligence;
	int newDexterity;
	int newLuck;
	int newEndurance;
	int newMana;

	while (newPointsLVL > 0) {
		std::cout << "Masz " << newPointsLVL << " punktów do rozdania.\n";
		std::cout << "Aktualne statystyki:\n";
		displayStats();
		std::cout << "Wybierz, które statystyki chcesz zwiêkszyæ:\n";
		std::cout << "1. Health Points\n";
		std::cout << "2. Strength\n";
		std::cout << "3. Intelligence\n";
		std::cout << "4. Dexterity\n";
		std::cout << "5. Luck\n";
		std::cout << "6. Endurance\n";
		std::cout << "7. Mana\n";


		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Podaj wartoœæ Health Points do dodania: ";
			std::cin >> newHP;
			setHealthPoints(getHealthPoints() + newHP);
			newPointsLVL -= newHP;
			break;
		case 2:
			std::cout << "Podaj wartoœæ Strength do dodania: ";
			std::cin >> newStrength;
			setStrength(getStrength() + newStrength);
			newPointsLVL -= newStrength;
			break;
		case 3:
			std::cout << "Podaj wartoœæ Intelligence do dodania: ";
			std::cin >> newIntelligence;
			setIntelligence(getIntelligence() + newIntelligence);
			newPointsLVL -= newIntelligence;
			break;
		case 4:
			std::cout << "Podaj wartoœæ Dexterity do dodania: ";
			std::cin >> newDexterity;
			setDexterity(getDexterity() + newDexterity);
			newPointsLVL -= newDexterity;
			break;
		case 5:
			std::cout << "Podaj wartoœæ Luck do dodania: ";
			std::cin >> newLuck;
			setLuck(getLuck() + newLuck);
			newPointsLVL -= newLuck;
			break;
		case 6:
			std::cout << "Podaj wartoœæ Endurance do dodania: ";
			std::cin >> newEndurance;
			setEndurance(getEndurance() + newEndurance);
			newPointsLVL -= newEndurance;
			break;
		case 7:
			std::cout << "Podaj wartoœæ Mana do dodania: ";
			std::cin >> newMana;
			setMana(getMana() + newMana);
			newPointsLVL -= newMana;
			break;

		default:
			std::cout << "Nieprawid³owy wybór. Spróbuj ponownie.\n";
			break;
		}


	}


}
