#pragma once
#include <string>

class Weapon {
protected:
    std::string name;
    double attackDamage;
    double magicPower;
    std::string scaling;

public:
    Weapon(const std::string& name, double attackDamage, double magicPower, const std::string& scaling)
        : name(name), attackDamage(attackDamage), magicPower(magicPower), scaling(scaling) {
    }

    virtual ~Weapon() {}

    // Getters
    const std::string& getName() const { return name; }
    double getAttackDamage() const { return attackDamage; }
    double getMagicPower() const { return magicPower; }
    const std::string& getScaling() const { return scaling; }

    // Setters
    void setName(const std::string& n) { name = n; }
    void setAttackDamage(double dmg) { attackDamage = dmg; }
    void setMagicPower(double mp) { magicPower = mp; }
    void setScaling(const std::string& s) { scaling = s; }

    // Abstrakcyjna metoda
    virtual void displayStats() const = 0;
};
