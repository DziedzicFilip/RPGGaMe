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
    std::cout << hero.getName() << " odzyskuje " << value << " punkt�w wytrzyma�o�ci w punkcie odpoczynku: " << name << std::endl;
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

void RestPoint::chooseEquipment(Character& hero) const {
    Equipment& eq = hero.getEquipment();
    eq.displayWeapons(); // Wy�wietl dost�pne bronie

    std::cout << "Wybierz numer broni, kt�r� chcesz za�o�y�: ";
    int index;
    std::cin >> index;

    // Zak�adamy, �e Character/Hero ma setHand(Weapon*) i Equipment ma showWeaponDetails(int)
    Weapon* selected = eq.getWeapon(index); // Dodaj getWeapon(int) je�li nie istnieje
    if (selected) {
        // Je�li to Hero:
        Hero* h = dynamic_cast<Hero*>(&hero);
        if (h) {
            h->setHand(selected);
            std::cout << "Za�o�ono bro�: " << selected->getName() << std::endl;
        }
    }
    else {
        std::cout << "Nieprawid�owy wyb�r!" << std::endl;
    }
}
