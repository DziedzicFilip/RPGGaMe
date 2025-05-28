#pragma once
#include "Weapon.h"

class Sword : public Weapon {
public:
    Sword(const std::string& name, double attackDamage, double magicPower, const std::string& scaling, double value);

    void heavyAttack() const;
    void lightAttack() const;
    void displayStats() const override;
};
