#pragma once
#include "Character.h"
#include "Weapon.h" // Dodaj ten include, je�li nie ma

class Hero : public Character {
protected:
    int endurance;
    Weapon* hand = nullptr; // Aktualnie u�ywana bro�

public:
    Hero(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance);

    // Gettery i settery dla endurance
    int getEndurance() const;
    void setEndurance(int value);

    // Gettery i settery dla broni w r�ku
    Weapon* getHand() const;
    void setHand(Weapon* weapon);

    // Umiej�tno�ci walki
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
