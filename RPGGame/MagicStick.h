#pragma once
#include "Weapon.h"

class MagicStick : public Weapon {
public:
    MagicStick(const std::string& name, double attackDamage, double magicPower, const std::string& scaling, double value);

    void ignis() const;
    void waterBomb() const;
    void displayStats() const override;
};
