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

// Wyswietlanie broni
void Equipment::displayWeapons() const {
    std::cout << "Bronie:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        if (weapons[i]) {
            std::cout << i << ": ";
            weapons[i]->displayStats();
        }
    }
}

// Szczegoly broni
void Equipment::showWeaponDetails(int index) const {
    if (index >= 0 && index < 2 && weapons[index]) {
        weapons[index]->displayStats();
    }
    else {
        std::cout << "Brak broni na indeksie " << index << std::endl;
    }
}

Weapon* Equipment::getWeapon(int index) const {
    if (index >= 0 && index < 2) {
        return weapons[index];
    }
    return nullptr;
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

// Wyswietlanie potek
void Equipment::displayPotions() const {
    std::cout << "Potki:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        if (potions[i]) {
            std::cout << i << ": ";
            std::cout << "Typ potki: " << (potions[i]->getType() == Potion::Type::Health ? "Zdrowie" : "Mana")
                << ", ilosc: " << potions[i]->getAmount() << std::endl;
        }
    }
}

Potion* Equipment::getPotion(int index) const {
    if (index >= 0 && index < 5) {
        return potions[index];
    }
    return nullptr;
}

// Szczegoly potki
void Equipment::showPotionDetails(int index) const {
    if (index >= 0 && index < 5 && potions[index]) {
        std::cout << "Typ potki: " << (potions[index]->getType() == Potion::Type::Health ? "Zdrowie" : "Mana")
            << ", ilosc: " << potions[index]->getAmount() << std::endl;
    }
    else {
        std::cout << "Brak potki na indeksie " << index << std::endl;
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

int Equipment::getWeaponCount() const {
    int count = 0;
    for (int i = 0; i < 2; ++i) {
        if (weapons[i] != nullptr) {
            count++;
        }
    }
    return count;
}

int Equipment::getPotionCount() const {
    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if (potions[i] != nullptr) {
            count++;
        }
    }
    return count;
}
