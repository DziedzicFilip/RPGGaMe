#pragma once
#include "NPC.h"
#include "Hero.h"
class Trade
{
public:
	void virtual StartTrade(NPC& npc, Hero& hero);
	void virtual BuyItem(NPC& npc, Hero& hero);
	void virtual SellItem(NPC& npc, Hero& hero);
	void virtual ShowInventoryNpc(NPC& npc);
	void virtual ShowInventoryHero(Hero& hero);
	void virtual BuyPotion(NPC& npc, Hero& hero);
	void virtual SellPotion(NPC& npc, Hero& hero);
};

