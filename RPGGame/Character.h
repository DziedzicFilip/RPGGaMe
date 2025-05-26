#pragma once
#include <string>
#include <iostream>
#include "Equipment.h" // Dodaj ten include

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
    Equipment eq; // Dodaj pole ekwipunku

public:
    Character(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance, double mana)
        : name(name), HealthPoints(healthPoints), level(level), XP(XP),
        strength(strength), intelligence(intelligence), dexterity(dexterity), luck(luck), endurance(endurance), mana(mana) {
    }

    virtual ~Character() {}

    // Getters
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
    Equipment& getEquipment() { return eq; } // Getter do ekwipunku
    const Equipment& getEquipment() const { return eq; }

    // Setters
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

    // Display stats
    virtual void displayStats() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health Points: " << HealthPoints << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "XP: " << XP << std::endl;
        std::cout << "Strength: " << strength << std::endl;
        std::cout << "Intelligence: " << intelligence << std::endl;
        std::cout << "Dexterity: " << dexterity << std::endl;
        std::cout << "Luck: " << luck << std::endl;
        std::cout << "Endurance: " << endurance << std::endl;
        std::cout << "Mana: " << mana << std::endl;
    }

    // Abstract method
    virtual bool perceptionTest() const = 0;
};
