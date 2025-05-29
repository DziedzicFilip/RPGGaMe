#pragma once
#include "Weapon.h"

class Bow : public Weapon {
public:
    // Konstruktor BEZ parametru scaling, bo zawsze "dex"
    Bow(const std::string& name, double attackDamage, double magicPower, double value);

    void heavyAttack() const;
    void lightAttack() const;
    void displayStats() const override;
};
