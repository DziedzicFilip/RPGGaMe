#include "Game.h"
#include "GameState.h"
#include "Sword.h"
#include "Bow.h"
#include "MagicStick.h"
#include <iostream>
#include <cstdlib>
#include "Combat.h"
#include "Goblin.h" 
#include "RestPoint.h"
#include "NPC.h"
#include "Potion.h"
#include "Trade.h"
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
    // Wczytaj dane z pliku
    if (!GameState::loadGame(hero, act, filename)) {
        std::cerr << "Nie uda�o si� wczyta� zapisu gry. Tworz� now� gr�...\n";
        start();
        return;
    }

    // Pobierz ostatni uko�czony rozdzia�
    int lastCompletedChapter = act.getLastCompletedChapter(); 
    int nextChapter = GameState::getNextChapterFromSave(filename);

    std::cout << "Kontynuujesz gr� od rozdzia�u " << nextChapter << ".\n";
    Act prologue;
    Hero Companion("Bezimienny", 15, 0, 0, 10, 10, 10, 10, 10, 10);
    Goblin goblin("Rzezimieszek Starszy", "Goblin", 5, 25, 75);
    Goblin goblin2("Rzezimieszek �redni", "Goblin", 5, 15, 25);
    Combat combat1(hero, Companion, goblin);
    Combat combat2(hero, Companion, goblin2);

    switch (nextChapter) {
    
    default:
        std::cout << "Wszystkie rozdzia�y zosta�y uko�czone! Gratulacje!\n";
        return;
    }

    GameState::saveGame(hero, act, filename);
    continueGame();
}

void Game::continueGame() {
	std::cout << "Naci�nij Enter, aby kontynuowa�...";
	std::cin.ignore();
	std::cin.get();
	system("cls");
}
void Game::start() {
    const std::string filename = "save.txt";
	std::cout << "Galdurs Bate 4 \n";
	Hero hero;
	Sword sword("Sword", 20, 10, 10);
	Bow bow("Longbow", 15, 5, 10);
	MagicStick magicStick("Elder Wand", 25, 15, 10);
    hero.CreateHero(sword,bow,magicStick);
	continueGame();
    hero.levelUp();
	continueGame();
    GameState::saveGame(hero, act, filename);
    //rodzial 1 
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
    GameState::saveGame(hero, prologue, filename);
    //Zapis rodzial 1
    //rodzial 2
    std::cout << prologue.getChapterContent(2) << std::endl;;
    continueGame();
    prologue.markChapterCompleted(2);
    GameState::saveGame(hero, prologue, filename);
	//Zapis rodzial 2

	std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - �DOSTA� SI� DO MIASTA�" << std::endl;
 
   //Rodzia� 3 
	std::cout << prologue.getChapterContent(3) << std::endl;
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
    
	prologue.markChapterCompleted(3);
	GameState::saveGame(hero, prologue, filename);
    //Zapis rodzial 3 
    //Rodzial 4 
	std::cout << prologue.getChapterContent(4) << std::endl;
    continueGame();
	Hero Companion("Bezimienny", 15, 0, 0,10,10,10,10,10,10);
	Goblin goblin("Rzezimieszek Starszy", "Goblin", 5, 25 , 75);
    Goblin goblin2("Rzezimieszek �redni", "Goblin", 5, 15, 25);
	Combat combat1(hero, Companion,goblin);
	combat1.StartBattleSolo();
	Combat combat2(hero, Companion, goblin2);
	combat2.StartBattleSolo();
	prologue.markChapterCompleted(4);
	GameState::saveGame(hero, prologue, filename);
	//Zapis rodzial 4 
	
	hero.CheckIfLevelUp();
    continueGame();
    
    //Rodzial 5
    std::cout << prologue.getChapterContent(5) << std::endl;
    continueGame();
   
	prologue.markChapterCompleted(5);
	std::cout << "SYSTEM: Rzut szcz�scia" << std::endl;
	if (hero.perceptionTest(2)) {
		std::cout << "Grzyb okazuje si� jadalny, ale brakuje mu przypraw" << std::endl;
	}
	else {
		std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
		hero.setHealthPoints(hero.getHealthPoints() - 5);
		std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
	}
	std::cout << "SYSTEM : Czas na odpoczynek towje zdrowie oraz reszta statystyk regenruja  sie" << std::endl;
	RestPoint restPoint("Odpoczynek w lesie");
	restPoint.restoreEndurance(hero,hero.getFullEndurance());
	restPoint.restoreHP(hero,hero.getFullHp());
	restPoint.restoreMana(hero, hero.getFullMana());
	GameState::saveGame(hero, prologue, filename);

	//Zapis rodzial 5
	prologue.getChapterContent(6);
	Equipment plecakSklepikarza;
	plecakSklepikarza.addWeapon(new Sword("zmatowia�y medalion", 0, 0, 1));
	plecakSklepikarza.addWeapon(new Bow("Zardzewia�y �uk", 15, 1, 5));
	plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20,8));
	NPC kruk("Kruk", plecakSklepikarza );
    Trade trade;
	trade.StartTrade(kruk, hero);
    if (hero.getEquipment().getWeapon(0)->getName() == "zmatowia�y medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowia�y medalion")
    {
        std::cout << "Gdy tylko przedmiot znajdzie si� w Twojej d�oni, �wiat si� przechyla. Przez sekund� jeste� gdzie� indziej. Krew na d�oniach, czyj� krzyk. Obraz zbroi, w kt�r� wgniatasz ostrze. Czu�e s�owo, szept: �Bracie��" << std::endl;
    }
	prologue.markChapterCompleted(6);
	GameState::saveGame(hero, prologue, filename);
	prologue.getChapterContent(7);
	/*std::cout << "SYSTEM: Wybierz co chcesz zrobi�" << std::endl;
	std::cout << "1. Wybierz bro�" << std::endl;
	std::cout << "2. Wyswietl ekwipunek" << std::endl;
	std::cout << "3. Nic nie rob" << std::endl;
	int choice;
	bool exit = true;
    while (exit) {
        std::cout << "SYSTEM: Wybierz co chcesz zrobi�" << std::endl;
        std::cout << "1. Wybierz bro�" << std::endl;
        std::cout << "2. Wyswietl ekwipunek" << std::endl;
        std::cout << "3. Nic nie rob" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            restPoint.chooseEquipment(hero);
            break;
        }
        case 2: {
            hero.getEquipment().displayWeapons();
            break;
        case 3: {
            std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
            exit = false;
            break;
        default:
            std::cout << "Nieprawid�owy wyb�r!" << std::endl;
            break;
        }
        }





        }*/
    }
