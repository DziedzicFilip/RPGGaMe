#include "Equipment.h"

// Dodawanie broni
bool Equipment::addWeapon(Weapon* weapon) {
    for (int i = 0; i < 2; ++i) {
        if (weapons[i] == nullptr) {
            weapons[i] = weapon;
            return true;
        }
    }
    return false;
}

// Usuwanie broni
bool Equipment::removeWeapon(int index) {
    if (index >= 0 && index < 2 && weapons[index] != nullptr) {
        weapons[index] = nullptr;
        return true;
    }
    return false;
}

// Wyœwietlanie broni
void Equipment::displayWeapons() const {
    std::cout << "Weapons:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        if (weapons[i]) {
            std::cout << i << ": ";
            weapons[i]->displayStats();
        }
    }
}

// Szczegó³y broni
void Equipment::showWeaponDetails(int index) const {
    if (index >= 0 && index < 2 && weapons[index]) {
        weapons[index]->displayStats();
    }
    else {
        std::cout << "No weapon at index " << index << std::endl;
    }
}

// Dodawanie potki
bool Equipment::addPotion(Potion* potion) {
    for (int i = 0; i < 5; ++i) {
        if (potions[i] == nullptr) {
            potions[i] = potion;
            return true;
        }
    }
    return false;
}

// Usuwanie potki
bool Equipment::removePotion(int index) {
    if (index >= 0 && index < 5 && potions[index] != nullptr) {
        potions[index] = nullptr;
        return true;
    }
    return false;
}

// Wyœwietlanie potek
void Equipment::displayPotions() const {
    std::cout << "Potions:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        if (potions[i]) {
            std::cout << i << ": ";
            std::cout << "Potion type: " << (potions[i]->getType() == Potion::Type::Health ? "Health" : "Mana")
                << ", amount: " << potions[i]->getAmount() << std::endl;
        }
    }
}

// Szczegó³y potki
void Equipment::showPotionDetails(int index) const {
    if (index >= 0 && index < 5 && potions[index]) {
        std::cout << "Potion type: " << (potions[index]->getType() == Potion::Type::Health ? "Health" : "Mana")
            << ", amount: " << potions[index]->getAmount() << std::endl;
    }
    else {
        std::cout << "No potion at index " << index << std::endl;
    }
}

bool Equipment::hasPotion() const {
    for (int i = 0; i < 5; ++i) {
        if (potions[i] != nullptr) {
            return true;
        }
    }
    return false;
}