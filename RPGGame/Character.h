#pragma once
#include <string>
#include <iostream>
#include "Equipment.h" 

class Character {
protected:
    double HealthPoints;
    std::string name;
    int level;
    double XP;
    int strength;
    int intelligence;
    int dexterity;
    int luck;
    int endurance;
    double mana;
    Equipment eq; 

public:
    Character(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance, double mana);
	Character() = default;
    virtual ~Character();

    double getHealthPoints() const { return HealthPoints; }
    const std::string& getName() const { return name; }
    int getLevel() const { return level; }
    double getXP() const { return XP; }
    int getStrength() const { return strength; }
    int getIntelligence() const { return intelligence; }
    int getDexterity() const { return dexterity; }
    int getLuck() const { return luck; }
    int getEndurance() const { return endurance; }
    double getMana() const { return mana; } 
    Equipment& getEquipment() { return eq; }
    const Equipment& getEquipment() const { return eq; }

    void setHealthPoints(double hp) { HealthPoints = hp; }
    void setName(const std::string& n) { name = n; }
    void setLevel(int lvl) { level = lvl; }
    void setXP(double xp) { XP = xp; }
    void setStrength(int str) { strength = str; }
    void setIntelligence(int intel) { intelligence = intel; }
    void setDexterity(int dex) { dexterity = dex; }
    void setLuck(int l) { luck = l; }
    void setEndurance(int e) { endurance = e; }
    void setMana(double m) { mana = m; }

    virtual void displayStats() const;

    virtual bool perceptionTest(int event) const = 0;
};
