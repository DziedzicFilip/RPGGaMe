#pragma once
#include "Character.h"
#include "Weapon.h" 
#include "Enemy.h"
class Hero : public Character {
protected:
    int endurance;
    Weapon* hand = nullptr; 
    int fullHp;
	int fullMana;
	int fullStrength;
	int fullIntelligence;
	int fullDexterity;
	int fullLuck;
	int fullEndurance;

public:
    Hero(const std::string& name, double healthPoints, int level, double XP,
        int strength, int intelligence, int dexterity, int luck, int endurance,double mana);
	Hero() = default;
    // Gettery i settery dla endurance
    int getEndurance() const;
    void setEndurance(int value);

    // Gettery i settery dla broni w rêku
    Weapon* getHand() const;
    void setHand(Weapon* weapon);
	int getFullHp() const { return fullHp; }
	int getFullMana() const { return fullMana; }
	int getFullStrength() const { return fullStrength; }
	int getFullIntelligence() const { return fullIntelligence; }
	int getFullDexterity() const { return fullDexterity; }
	int getFullLuck() const { return fullLuck; }
	int getFullEndurance() const { return fullEndurance; }
	void setFullHp(int hp) { fullHp = hp; }
	void setFullMana(int mana) { fullMana = mana; }
	void setFullStrength(int strength) { fullStrength = strength; }
	void setFullIntelligence(int intelligence) { fullIntelligence = intelligence; }
	void setFullDexterity(int dexterity) { fullDexterity = dexterity; }
	void setFullLuck(int luck) { fullLuck = luck; }
	void setFullEndurance(int endurance) { fullEndurance = endurance; }
        

	

    // Umiejêtnoœci walki
    void heavyAttack(Enemy& enemy,Hero& hero);
    void lightAttack(Enemy& enemy, Hero& hero);
    void dodge();
    void reflect();
    void ignis(Enemy& enemy, Hero& hero);
    void heal(Hero& hero);
    void waterBomb(Enemy& enemy, Hero& hero);

    // Implementacja perceptionTest
    bool perceptionTest(int event) const override;

	//level up
    void levelUp();
    void CreateHero( Weapon& sword, Weapon& bow, Weapon& magicStick);
    void CheckIfLevelUp();
};
