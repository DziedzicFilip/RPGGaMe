// Combat.h
#pragma once
#include "Hero.h"
#include "Enemy.h"

class Combat {
public:
    Combat(Hero& mainHero, Hero& CompanionHero, Enemy& enemy);

    void StartBattle();
    void chooseAction(Hero& hero, Enemy& enemy);
	void enemyTurn(Enemy& enemy, Hero& hero);
	void CompaionionTurn(Hero& CompanionHero, Enemy& enemy);
    
private:
    Hero& mainHero;
    Hero& CompanionHero;
    Enemy& enemy;



};

