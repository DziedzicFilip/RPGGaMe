// Combat.h
#pragma once
#include "Hero.h"
#include "Enemy.h"

class Combat {
public:
    Combat(Hero& mainHero, Hero& CompanionHero, Enemy& enemy);
	
    int StartBattle();
    void chooseAction(Hero& hero, Enemy& enemy);
	void enemyTurn(Enemy& enemy, Hero& hero);
	void CompaionionTurn(Hero& CompanionHero, Enemy& enemy);
    int StartBattleSolo();
	bool result(bool result);
private:
    Hero& mainHero;
    Hero& CompanionHero;
    Enemy& enemy;



};

