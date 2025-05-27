#pragma once
#include "Weapon.h"
#include "Potion.h"
#include <iostream>

class Equipment {
private:
    Weapon* weapons[2] = { nullptr, nullptr };
    Potion* potions[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    int gold = 0;

public:
    bool addWeapon(Weapon* weapon);
    bool removeWeapon(int index);
    void displayWeapons() const;
    void showWeaponDetails(int index) const;
    Weapon* getWeapon(int index) const;

    bool addPotion(Potion* potion);
    bool removePotion(int index);
    void displayPotions() const;
    void showPotionDetails(int index) const;
    bool hasPotion() const;

    void setGold(int value) { gold = value; }
    int getGold() const { return gold; }
    void displayGold() const { std::cout << "Gold: " << gold << std::endl; }
};
