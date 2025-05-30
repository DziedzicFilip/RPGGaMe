#pragma once
#include <string>

class Weapon {
public:
    enum class Type { Sword, Bow, MagicStick };

protected:
    std::string name;
    double attackDamage;
    double magicPower;
    std::string scaling;
    double value;
    Type type; 

public:
    Weapon(const std::string& name, double attackDamage, double magicPower, const std::string& scaling, double value, Type type)
        : name(name), attackDamage(attackDamage), magicPower(magicPower), scaling(scaling), value(value), type(type) {
    }

    virtual ~Weapon() {}

    // Getters
    const std::string& getName() const { return name; }
    double getAttackDamage() const { return attackDamage; }
    double getMagicPower() const { return magicPower; }
    const std::string& getScaling() const { return scaling; }
    double getValue() const { return value; }
    Type getType() const { return type; } 

    // Setters
    void setName(const std::string& n) { name = n; }
    void setAttackDamage(double dmg) { attackDamage = dmg; }
    void setMagicPower(double mp) { magicPower = mp; }
    void setScaling(const std::string& s) { scaling = s; }
    void setType(Type t) { type = t; } 

    // Abstract method
    virtual void displayStats() const = 0;
};
