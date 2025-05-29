#include "Bow.h"
#include <iostream>

Bow::Bow(const std::string& name, double attackDamage, double magicPower, double value)
    : Weapon(name, attackDamage, magicPower, "dex", value, Type::Bow) {
}

void Bow::heavyAttack() const {
    std::cout << "Ciê¿ka strza³a przeszy³a powietrze i trafi³a cel z ogromn¹ si³¹!" << std::endl;
}

void Bow::lightAttack() const {
    std::cout << "Lekka strza³a szybko wylecia³a z ³uku i zrani³a przeciwnika." << std::endl;
}

void Bow::displayStats() const {
    std::cout << "Bow: " << name << ", DMG: " << attackDamage << ", Magic: " << magicPower
        << ", Scaling: " << scaling << std::endl;
}
