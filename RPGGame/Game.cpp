#include "Game.h"
#include "GameState.h"
#include "Sword.h"
#include "Bow.h"
#include "MagicStick.h"
#include <iostream>
#include <cstdlib>
#include "Combat.h"
#include "Goblin.h" 
Game::Game() {
	start(); 
}

Game::Game(const std::string& saveFile) {
    filename = saveFile;
    if (!GameState::loadGame(hero, act, filename)) {
        std::cerr << "Nie uda³o siê wczytaæ gry. Tworzê now¹ grê...\n";
		start();
    }
}

void Game::createNewGame() {
    Sword sword("Excalibur", 20, 10, 10);
    Bow bow("Longbow", 15, 5, 10);
    MagicStick magicStick("Elder Wand", 25, 15, 10);
    hero.CreateHero(sword, bow, magicStick);

    if (!act.loadFromFile("Text.txt")) {
        std::cerr << "Nie uda³o siê za³adowaæ fabu³y.\n";
    }

    GameState::saveGame(hero, act, filename);
}

void Game::continueLoadedGame() {
    int chapterToPlay = act.getFirstIncompleteChapter();

    if (chapterToPlay > 0) {
        std::cout << "Kontynuujesz grê od rozdzia³u " << chapterToPlay << ".\n";
        std::cout << act.getChapterContent(chapterToPlay) << "\n";

        act.markChapterCompleted(chapterToPlay);

        // Zapis po ukoñczeniu rozdzia³u
        GameState::saveGame(hero, act, filename);
    }
    else {
        std::cout << "Wszystkie rozdzia³y zosta³y ukoñczone! Gratulacje!\n";
    }
}
void Game::continueGame() {
	std::cout << "Naciœnij Enter, aby kontynuowaæ...";
	std::cin.ignore();
	std::cin.get();
	system("cls");
}
void Game::start() {
	std::cout << "Galdurs Bate 4 \n";
	Hero hero;
	Sword sword("Sword", 20, 10, 10);
	Bow bow("Longbow", 15, 5, 10);
	MagicStick magicStick("Elder Wand", 25, 15, 10);

    hero.CreateHero(sword,bow,magicStick);
	GameState::saveGame(hero, act, filename);
	continueGame();
	hero.levelUp();
    GameState::saveGame(hero, act, filename);
	continueGame();
	Act prologue;
	prologue.loadFromFile("Prolog.txt");
	std::cout<<prologue.getChapterContent(1)<<std::endl;
    std::cout << "SYSTEM: Rzut na percepcje"<<std::endl;;
    if (hero.perceptionTest(5))
    {
        std::cout << "Twoje palce przesuwaj¹ siê po papierze tworz¹c smugê na s³owach napisanych czarnym atramentem.\n Zauwa¿asz, ¿e kartka jest stara, brudna i pe³na smug podobnych do tych, które w³aœnie stworzy³eœ.\n ";
        if (hero.perceptionTest(10))
        {
            std::cout << "Po dok³adniejszym zbadaniu czujesz, ¿e coœ w Twoim wnêtrzu ci¹gnie Ciê naprzód, jakby te s³owa nie by³y zapisane na papierze, tylko wypalone wewn¹trz Ciebie. \n";
        }
    }
    else
    {
        std::cout << "Nie zauwa¿asz niczego szczególnego na kartce.\n";
    }
	prologue.markChapterCompleted(1);
    GameState::saveGame(hero, act, filename);
    std::cout << prologue.getChapterContent(2) << std::endl;;
    continueGame();
    prologue.markChapterCompleted(2);
    GameState::saveGame(hero, act, filename);
	std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - “DOSTAÑ SIÊ DO MIASTA”" << std::endl;
    
    Act act1;
	act1.loadFromFile("Akt1.txt");
	std::cout << act1.getChapterContent(1) << std::endl;
    continueGame();
    std::cout << "SYSTEM: Rzut na percepcje" << std::endl;;
    if (hero.perceptionTest(15))
    {
        std::cout << "W oddali s³yszysz skrzypniêcie - nie drewna, a buta na suchym liœciu. Ktoœ tu jest. Zatrzymujesz siê." << std::endl;
    }
    else
    {
        std::cout << " Jesteœ zbyt poch³oniêty wêdrowaniem, by zauwa¿yæ cieñ skradaj¹cy siê miêdzy drzewami. Gdy rozlega siê pierwszy okrzyk, jesteœ ju¿ otoczo" << std::endl;

    }
	act1.markChapterCompleted(1);
	GameState::saveGame(hero, act1, filename);
	std::cout << act1.getChapterContent(2) << std::endl;
    continueGame();
	Hero Companion("Bezimienny", 15, 0, 0,10,10,10,10,10,10);
	Goblin goblin("Rzezimieszek Starszy", "Goblin", 5, 25 , 75);
    Goblin goblin2("Rzezimieszek Œredni", "Goblin", 5, 15, 25);
	Combat combat1(hero, Companion,goblin);
	combat1.StartBattleSolo();
	Combat combat2(hero, Companion, goblin2);
	combat2.StartBattleSolo();
	act1.markChapterCompleted(2);
	GameState::saveGame(hero, act1, filename);
	hero.CheckIfLevelUp();
    continueGame();
    std::cout << act1.getChapterContent(3) << std::endl;
    continueGame();
	act1.markChapterCompleted(3);
	std::cout << "SYSTEM: Rzut szczêscia" << std::endl;
	if (hero.perceptionTest(2)) {
		std::cout << "Grzyb okazuje siê jadalny, ale brakuje mu przypraw" << std::endl;
	}
	else {
		std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
		hero.setHealthPoints(hero.getHealthPoints() - 5);
		std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
	}
	std::cout << "SYSTEM : Czas na odpoczynek towje zdrowie oraz reszta statystyk regenruj sie" << std::endl;
	//dodac odnawianie statystyk
    // handlarz 
    // wybranie co w rece 
	// akt 2
    //nie dziala wczytwanie gry


    
}
