#pragma once
#include "Weapon.h"

class Sword : public Weapon {
public:
    Sword(const std::string& name, double attackDamage, double magicPower, double value);

    void heavyAttack() const;
    void lightAttack() const;
    void displayStats() const override;
};
