#pragma once
#include <string>
#include "Sword.h"
#include "Bow.h"
#include "MagicStick.h"

inline Weapon* createWeaponFromType(const std::string& type,
    const std::string& name,
    double attackDamage,
    double magicPower,
    const std::string& scaling,
    double value)
{
    if (type == "Sword")
        return new Sword(name, attackDamage, magicPower, scaling, value);
    else if (type == "Bow")
        return new Bow(name, attackDamage, magicPower, scaling, value);
    else if (type == "MagicStick")
        return new MagicStick(name, attackDamage, magicPower, scaling, value);
    else
        return nullptr;
}
