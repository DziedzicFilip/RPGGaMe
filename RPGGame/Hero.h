#pragma once
#include "Character.h"
#include "Weapon.h" // Dodaj ten include, jeœli nie ma

class Hero : public Character {
protected:
    int endurance;
    Weapon* hand = nullptr; // Aktualnie u¿ywana broñ

public:
    Hero(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance);

    // Gettery i settery dla endurance
    int getEndurance() const;
    void setEndurance(int value);

    // Gettery i settery dla broni w rêku
    Weapon* getHand() const;
    void setHand(Weapon* weapon);

    // Umiejêtnoœci walki
    void heavyAttack();
    void lightAttack();
    void dodge();
    void reflect();
    void ignis();
    void heal();
    void waterBomb();

    // Implementacja perceptionTest
    bool perceptionTest() const override;
};
