#include "Character.h"
#include <iostream>

// Konstruktor
Character::Character(const std::string& name, double healthPoints, int level, double XP,
    int strength, int intelligence, int dexterity, int luck, int endurance, double mana)
    : name(name), HealthPoints(healthPoints), level(level), XP(XP),
    strength(strength), intelligence(intelligence), dexterity(dexterity), luck(luck), endurance(endurance), mana(mana){
}


// Wirtualny destruktor
Character::~Character() {}

// Wyœwietlanie statystyk
void Character::displayStats() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health Points: " << HealthPoints << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "XP: " << XP << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Intelligence: " << intelligence << std::endl;
    std::cout << "Dexterity: " << dexterity << std::endl;
    std::cout << "Luck: " << luck << std::endl;
    std::cout << "Endurance: " << endurance << std::endl;
}

