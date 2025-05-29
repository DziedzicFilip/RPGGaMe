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
        std::cerr << "Nie uda�o si� wczyta� gry. Tworz� now� gr�...\n";
		start();
    }
}

void Game::createNewGame() {
    Sword sword("Excalibur", 20, 10, 10);
    Bow bow("Longbow", 15, 5, 10);
    MagicStick magicStick("Elder Wand", 25, 15, 10);
    hero.CreateHero(sword, bow, magicStick);

    if (!act.loadFromFile("Text.txt")) {
        std::cerr << "Nie uda�o si� za�adowa� fabu�y.\n";
    }

    GameState::saveGame(hero, act, filename);
}

void Game::continueLoadedGame() {
    int chapterToPlay = act.getFirstIncompleteChapter();

    if (chapterToPlay > 0) {
        std::cout << "Kontynuujesz gr� od rozdzia�u " << chapterToPlay << ".\n";
        std::cout << act.getChapterContent(chapterToPlay) << "\n";

        act.markChapterCompleted(chapterToPlay);

        // Zapis po uko�czeniu rozdzia�u
        GameState::saveGame(hero, act, filename);
    }
    else {
        std::cout << "Wszystkie rozdzia�y zosta�y uko�czone! Gratulacje!\n";
    }
}
void Game::continueGame() {
	std::cout << "Naci�nij Enter, aby kontynuowa�...";
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
        std::cout << "Twoje palce przesuwaj� si� po papierze tworz�c smug� na s�owach napisanych czarnym atramentem.\n Zauwa�asz, �e kartka jest stara, brudna i pe�na smug podobnych do tych, kt�re w�a�nie stworzy�e�.\n ";
        if (hero.perceptionTest(10))
        {
            std::cout << "Po dok�adniejszym zbadaniu czujesz, �e co� w Twoim wn�trzu ci�gnie Ci� naprz�d, jakby te s�owa nie by�y zapisane na papierze, tylko wypalone wewn�trz Ciebie. \n";
        }
    }
    else
    {
        std::cout << "Nie zauwa�asz niczego szczeg�lnego na kartce.\n";
    }
	prologue.markChapterCompleted(1);
    GameState::saveGame(hero, act, filename);
    std::cout << prologue.getChapterContent(2) << std::endl;;
    continueGame();
    prologue.markChapterCompleted(2);
    GameState::saveGame(hero, act, filename);
	std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - �DOSTA� SI� DO MIASTA�" << std::endl;
    
    Act act1;
	act1.loadFromFile("Akt1.txt");
	std::cout << act1.getChapterContent(1) << std::endl;
    continueGame();
    std::cout << "SYSTEM: Rzut na percepcje" << std::endl;;
    if (hero.perceptionTest(15))
    {
        std::cout << "W oddali s�yszysz skrzypni�cie - nie drewna, a buta na suchym li�ciu. Kto� tu jest. Zatrzymujesz si�." << std::endl;
    }
    else
    {
        std::cout << " Jeste� zbyt poch�oni�ty w�drowaniem, by zauwa�y� cie� skradaj�cy si� mi�dzy drzewami. Gdy rozlega si� pierwszy okrzyk, jeste� ju� otoczo" << std::endl;

    }
	act1.markChapterCompleted(1);
	GameState::saveGame(hero, act1, filename);
	std::cout << act1.getChapterContent(2) << std::endl;
    continueGame();
	Hero Companion("Bezimienny", 15, 0, 0,10,10,10,10,10,10);
	Goblin goblin("Rzezimieszek Starszy", "Goblin", 5, 25 , 75);
    Goblin goblin2("Rzezimieszek �redni", "Goblin", 5, 15, 25);
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
	std::cout << "SYSTEM: Rzut szcz�scia" << std::endl;
	if (hero.perceptionTest(2)) {
		std::cout << "Grzyb okazuje si� jadalny, ale brakuje mu przypraw" << std::endl;
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
