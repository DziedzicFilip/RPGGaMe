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
using namespace std;
// Menu przy starcie i zapis w obiekcie po  kadzym punkcie wykonanym 
// 
// Import assembly functions
extern "C" int PrintText(const char* text);
void continueGame() {
	std::cout << "Naci�nij Enter, aby kontynuowa�...";
	std::cin.ignore();
	std::cin.get();
	system("cls");
}
int main() {
    // Welcome message using our assembly function
    const char* welcome = "Witaj w �wiecie RPG Game - Las Cieni";
    PrintText(welcome);
	Bow bow("Longbow", 15.0, 5.0, "Dexterity");
	Sword sword("Excalibur", 20.0, 10.0, "Strength");
	MagicStick magicStick("Elder Wand", 25.0, 15.0, "Intelligence");
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
	Potion healthPotion(Potion::Type::Health, 20.0);
	equipment.addWeapon(&bow);
	equipment.addWeapon(&sword);
	equipment.addPotion(&healthPotion);
	NPC npc("Astarion",equipment);
	npc.getEquipment().displayWeapons();
	npc.getEquipment().displayPotions();
    return 0;
}