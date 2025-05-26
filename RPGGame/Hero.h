#pragma once
#include "Character.h"

class Hero : public Character {
protected:
    int endurance;

public:
    Hero(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance);

    // Gettery i settery dla endurance
    int getEndurance() const;
    void setEndurance(int value);

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