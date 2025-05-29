#include "Bow.h"
#include <iostream>

Bow::Bow(const std::string& name, double attackDamage, double magicPower, double value)
    : Weapon(name, attackDamage, magicPower, "dex", value, Type::Bow) {
}

void Bow::heavyAttack() const {
    std::cout << "Ci�ka strza�a przeszy�a powietrze i trafi�a cel z ogromn� si��!" << std::endl;
}

void Bow::lightAttack() const {
    std::cout << "Lekka strza�a szybko wylecia�a z �uku i zrani�a przeciwnika." << std::endl;
}

void Bow::displayStats() const {
    std::cout << "Bow: " << name << ", DMG: " << attackDamage << ", Magic: " << magicPower
        << ", Scaling: " << scaling << std::endl;
}
