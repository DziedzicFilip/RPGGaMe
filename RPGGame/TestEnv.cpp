#include <iostream>
#include <cstdlib>
#include "Combat.h"
#include "Hero.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Bow.h"
#include "Sword.h"
#include "MagicStick.h"
#include "Enemy.h"
#include "Goblin.h"
#include "NPC.h"
#include "Potion.h"
#include "Trade.h"
#include "Act.h"
using namespace std;
// Menu przy starcie i zapis w obiekcie po  kadzym punkcie wykonanym 
// 
// Import assembly functions
extern "C" int PrintText(const char* text);
void continueGame() {
	std::cout << "Naciœnij Enter, aby kontynuowaæ...";
	std::cin.ignore();
	std::cin.get();
	system("cls");
}
int main() {
    // Welcome message using our assembly function
    const char* welcome = "Witaj w œwiecie RPG Game - Las Cieni";
    PrintText(welcome);
	Bow bow("Longbow", 15.0, 5.0,10);
	Sword sword("Excalibur", 20.0, 10.0,10);
	MagicStick magicStick("Elder Wand", 25.0, 15.0,10);
	Bow bow2("NPC-merch-bow", 15.0, 5.0, 10);
	Sword sword2("NPC-merch-sword", 20.0, 10.0, 10);
	MagicStick magicStick2("NPC-merch-wand", 25.0, 15.0, 10);
	// Create a hero
	Hero hero;
	Hero CompanionHero("Przydupas",9999,0,0,10,10,10,10,10,10);
	//hero.CreateHero(bow, sword, magicStick);
	//hero.displayStats();
	//continueGame();
	// Create an enemy
	const char* odzielenie = "####################\n---------------------------------------- \n ######################################";
	Goblin goblin("Goblin", "Monster", 50.0, 5.0, 10.0);
	Combat combat(hero, CompanionHero, goblin);
	//combat.StartBattle();
	Equipment equipment;
	Potion healthPotion(Potion::Type::Health, 20.0,10);
	equipment.addWeapon(&bow);
	equipment.addWeapon(&sword);
	equipment.addPotion(&healthPotion);
	Equipment equipment2;
	equipment2.addWeapon(&bow2);
	equipment2.addWeapon(&sword2);
	equipment2.addPotion(&healthPotion);

	NPC npc("Astarion",equipment2);
	//npc.getEquipment().displayWeapons();
	//npc.getEquipment().displayPotions();
	/*hero.getEquipment().addWeapon(&bow);
	hero.getEquipment().addWeapon(&sword);
	hero.getEquipment().displayWeapons();
	hero.getEquipment().displayGold();
	hero.getEquipment().displayPotions();
	hero.getEquipment().setGold(100);
	hero.getEquipment().displayGold();
	Trade trade;
	trade.StartTrade(npc, hero);
	hero.getEquipment().displayWeapons();
	hero.getEquipment().displayPotions();
	npc.getEquipment().displayWeapons();
	npc.getEquipment().displayPotions();*/
	Act act;
	if (act.loadFromFile("Text.txt")) {
		act.printAllChaptersStatus();
		std::cout << act.getChapterContent(1) << std::endl;
		act.markChapterCompleted(1);
		act.printAllChaptersStatus();
	}
    return 0;
}