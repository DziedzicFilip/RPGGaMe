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
extern "C" int PrintText(const char* text);
int main() {
    
    const char* welcome = "Witaj w swiecie RPG Game ";

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
        Game game;  
    }

  


    return 0;




}