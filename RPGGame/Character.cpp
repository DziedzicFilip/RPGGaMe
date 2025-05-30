#include "Character.h"
#include <iostream>

// Konstruktor
Character::Character(const std::string& name, double healthPoints, int level, double XP,
    int strength, int intelligence, int dexterity, int luck, int endurance, double mana)
    : name(name), HealthPoints(healthPoints), level(level), XP(XP),
    strength(strength), intelligence(intelligence), dexterity(dexterity), luck(luck), endurance(endurance), mana(mana) {
}

// Wirtualny destruktor
Character::~Character() {}

// Wyswietlanie statystyk
void Character::displayStats() const {
    std::cout << "Imie: " << name << std::endl;
    std::cout << "Punkty zycia: " << HealthPoints << std::endl;
    std::cout << "Poziom: " << level << std::endl;
    std::cout << "Punkty doswiadczenia: " << XP << std::endl;
    std::cout << "Sila: " << strength << std::endl;
    std::cout << "Inteligencja: " << intelligence << std::endl;
    std::cout << "Zrecznosc: " << dexterity << std::endl;
    std::cout << "Szczescie: " << luck << std::endl;
    std::cout << "Wytrzymalosc: " << endurance << std::endl;
}
