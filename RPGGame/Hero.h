#pragma once
#include "Character.h"
#include "Weapon.h" // Dodaj ten include, je�li nie ma
#include "Enemy.h"
class Hero : public Character {
protected:
    int endurance;
    Weapon* hand = nullptr; // Aktualnie u�ywana bro�

public:
    Hero(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance,double mana);
	Hero() = default; // Domy�lny konstruktor
    // Gettery i settery dla endurance
    int getEndurance() const;
    void setEndurance(int value);

    // Gettery i settery dla broni w r�ku
    Weapon* getHand() const;
    void setHand(Weapon* weapon);

    // Umiej�tno�ci walki
    void heavyAttack(Enemy& enemy);
    void lightAttack(Enemy& enemy);
    void dodge();
    void reflect();
    void ignis(Enemy& enemy);
    void heal(Hero& hero);
    void waterBomb(Enemy& enemy);

    // Implementacja perceptionTest
    bool perceptionTest(int event) const override;

	//level up
    void levelUp();
    void CreateHero( Weapon& sword, Weapon& bow, Weapon& magicStick);
};
