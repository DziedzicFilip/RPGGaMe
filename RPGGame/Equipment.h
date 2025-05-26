#pragma once
#include "Weapon.h"
#include "Potion.h"
#include <iostream>

class Equipment {
private:
    Weapon* weapons[2] = { nullptr, nullptr };
    Potion* potions[5] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // 5 miejsc na potki
    int gold = 0;

public:
    // Dodawanie broni
    bool addWeapon(Weapon* weapon);
    // Usuwanie broni
    bool removeWeapon(int index);
    // Wyœwietlanie broni
    void displayWeapons() const;
    // Szczegó³y broni
    void showWeaponDetails(int index) const;

    // Dodawanie potki
    bool addPotion(Potion* potion);
    // Usuwanie potki
    bool removePotion(int index);
    // Wyœwietlanie potek
    void displayPotions() const;
    // Szczegó³y potki
    void showPotionDetails(int index) const;

    // Gold
    void setGold(int value) { gold = value; }
    int getGold() const { return gold; }
    void displayGold() const { std::cout << "Gold: " << gold << std::endl; }
};
