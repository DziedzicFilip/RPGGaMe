// Combat.h
#pragma once
#include "Hero.h"
#include "Enemy.h"

class Combat {
public:
    Combat(Hero& mainHero, Hero& CompanionHero, Enemy& enemy);

    void StartBattle();
    int chooseAction(Hero& hero);


private:
    Hero& mainHero;
    Hero& CompanionHero;
    Enemy& enemy;
};
