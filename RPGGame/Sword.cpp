#include "Sword.h"
#include <iostream>

Sword::Sword(const std::string& name, double attackDamage, double magicPower, const std::string& /*scaling*/)
    : Weapon(name, attackDamage, magicPower, "ad") {
}

void Sword::heavyAttack() const {
    std::cout << "Potê¿ne ciêcie mieczem rozcina powietrze i przeciwnika!" << std::endl;
}

void Sword::lightAttack() const {
    std::cout << "Szybkie pchniêcie mieczem trafia wroga." << std::endl;
}

void Sword::displayStats() const {
    std::cout << "Sword: " << name << ", DMG: " << attackDamage << ", Magic: " << magicPower
        << ", Scaling: " << scaling << std::endl;
}
