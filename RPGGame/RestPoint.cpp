#include "RestPoint.h"
#include <iostream>

RestPoint::RestPoint(const std::string& name)
    : name(name) {
}

const std::string& RestPoint::getName() const {
    return name;
}

void RestPoint::restoreEndurance(Character& hero, int value) const {
    hero.setEndurance(hero.getEndurance() + value);
    std::cout << hero.getName() << " odzyskuje " << value << " punktów wytrzyma³oœci w punkcie odpoczynku: " << name << std::endl;
}

void RestPoint::restoreHP(Character& hero, double value) const {
    hero.setHealthPoints(hero.getHealthPoints() + value);
    std::cout << hero.getName() << " odzyskuje " << value << " HP w punkcie odpoczynku: " << name << std::endl;
}

void RestPoint::restoreMana(Character& hero, double value) const {
    hero.setMana(hero.getMana() + value);
    std::cout << hero.getName() << " odzyskuje " << value << " many w punkcie odpoczynku: " << name << std::endl;
}

void RestPoint::dialogue(Character& hero1, Character& hero2, const std::string& text1, const std::string& text2) const {
    std::cout << hero1.getName() << ": " << text1 << std::endl;
    std::cout << hero2.getName() << ": " << text2 << std::endl;
}
