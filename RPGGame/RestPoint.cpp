#include "RestPoint.h"
#include "Hero.h"

#include <iostream>

RestPoint::RestPoint(const std::string& name)
    : name(name) {
}

const std::string& RestPoint::getName() const {
    return name;
}

void RestPoint::restoreEndurance(Character& hero, int value) const {
    hero.setEndurance(value);
    std::cout << hero.getName() << " odzyskuje " << value << " punktow wytrzymalosci w punkcie odpoczynku: " << name << std::endl;
}

void RestPoint::restoreHP(Character& hero, double value) const {
    hero.setHealthPoints(value);
    std::cout << hero.getName() << " odzyskuje " << value << " HP w punkcie odpoczynku: " << name << std::endl;
}

void RestPoint::restoreMana(Character& hero, double value) const {
    hero.setMana(value);
    std::cout << hero.getName() << " odzyskuje " << value << " many w punkcie odpoczynku: " << name << std::endl;
}

void RestPoint::dialogue(Character& hero1, Character& hero2, const std::string& text1, const std::string& text2) const {
    std::cout << hero1.getName() << ": " << text1 << std::endl;
    std::cout << hero2.getName() << ": " << text2 << std::endl;
}

void RestPoint::chooseEquipment(Character& hero) const {
    Equipment& eq = hero.getEquipment();
    eq.displayWeapons(); 

    std::cout << "Wybierz numer broni, ktora chcesz zalozyc: ";
    int index;
    std::cin >> index;

    Weapon* selected = eq.getWeapon(index);
    if (selected) {
        Hero* h = dynamic_cast<Hero*>(&hero);
        if (h) {
            h->setHand(selected);
            std::cout << "Zalozono bron: " << selected->getName() << std::endl;
        }
    }
    else {
        std::cout << "Nieprawidlowy wybor!" << std::endl;
    }
}
