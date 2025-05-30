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
#include "GameState.h"
#include <filesystem>
#include <iostream>
#include "Game.h"
using namespace std;
// Menu przy starcie i zapis w obiekcie po  kadzym punkcie wykonanym 
// 
// Import assembly functions
extern "C" int PrintText(const char* text);
int main() {
    // Welcome message using our assembly function
    const char* welcome = "Witaj w œwiecie RPG Game - Las Cieni";

	PrintText(welcome);
    Game* game;
   const std::string saveFile = "save.txt";

  if (GameState::hasSaveFile(saveFile)) {

		GameState::shouldLoadGame(saveFile);
       Game game(saveFile);
       game.continueLoadedGame();
   }
   else {
      std::cout << "Nie znaleziono zapisu gry. Rozpoczynam now¹ grê.\n";
       Game game;  // sam odpali start()
    }

   /* Hero hero;
    Sword sword("Excalibur", 20, 10, 10);
    Bow bow("Longbow", 15, 5, 10);
    MagicStick magicStick("Elder Wand", 25, 15, 10);
    hero.CreateHero(sword,bow,magicStick);
	for (int i = 0; i < 5; i++)
	{
        hero.perceptionTest(10);
	}*/

	

    



}