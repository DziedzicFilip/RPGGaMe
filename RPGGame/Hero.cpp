#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string& name, double healthPoints, int level, double XP,
    int strength, int intelligence, int dexterity, int luck, int endurance)
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

bool Hero::perceptionTest() const {
    // Przyk³adowa implementacja
    return (dexterity + luck) > 10;
}
