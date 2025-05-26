#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string& name, double healthPoints, int level, double XP,
    int strength, int intelligence, int dexterity, int luck, int endurance)
    : Character(name, healthPoints, level, XP, strength, intelligence, dexterity, luck),
    endurance(endurance) {
}

int Hero::getEndurance() const {
    return endurance;
}

void Hero::setEndurance(int value) {
    endurance = value;
}

void Hero::heavyAttack() {
    // Implementacja póŸniej
}

void Hero::lightAttack() {
    // Implementacja póŸniej
}

void Hero::dodge() {
    // Implementacja póŸniej
}

void Hero::reflect() {
    // Implementacja póŸniej
}

void Hero::ignis() {
    // Implementacja póŸniej
}

void Hero::heal() {
    // Implementacja póŸniej
}

void Hero::waterBomb() {
    // Implementacja póŸniej
}

bool Hero::perceptionTest() const {
    // Przyk³adowa implementacja
    return (dexterity + luck) > 10;
}
