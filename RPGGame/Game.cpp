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
    // Wczytaj dane z pliku
    if (!GameState::loadGame(hero, act, filename)) {
        std::cerr << "Nie udalo sie wczytac zapisu gry. Tworze nowa gre...\n";
        start();
        return;
    }

    // Pobierz ostatni ukonczony rozdzial
    int lastCompletedChapter = act.getLastCompletedChapter();
    int nextChapter = GameState::getNextChapterFromSave(filename);

    std::cout << "Kontynuujesz gre od rozdzialu " << nextChapter << ".\n";
    Act prologue;
    Hero Companion("Bezimienny", 15, 0, 0, 10, 10, 10, 10, 10, 10);
    Goblin goblin("Rzezimieszek Starszy", "Goblin", 5, 25, 75);
    Goblin goblin2("Rzezimieszek Sredni", "Goblin", 5, 15, 25);
    Combat combat1(hero, Companion, goblin);
    Combat combat2(hero, Companion, goblin2);
    RestPoint restPoint("Odpoczynek w lesie");
    Equipment plecakSklepikarza;
    NPC kruk("Kruk", plecakSklepikarza);
    Trade trade;
    bool exit = true;
    int choice;
    switch (nextChapter) {
    case 1:
        prologue.loadFromFile("Prolog.txt");
        std::cout << prologue.getChapterContent(1) << std::endl;
        std::cout << "SYSTEM: Rzut na percepcje" << std::endl;
        if (hero.perceptionTest(5)) {
            std::cout << "Twoje palce przesuwaja sie po papierze tworzac smuge na slowach napisanych czarnym atramentem.\n Zauwazasz, ze kartka jest stara, brudna i pelna smug podobnych do tych, ktore wlasnie stworzyles.\n ";
            if (hero.perceptionTest(10)) {
                std::cout << "Po dokladniejszym zbadaniu czujesz, ze cos w Twoim wnetrzu ciagnie Cie naprzod, jakby te slowa nie byly zapisane na papierze, tylko wypalone wewnatrz Ciebie. \n";
            }
        }
        else {
            std::cout << "Nie zauwazasz niczego szczegolnego na kartce.\n";
        }
        prologue.markChapterCompleted(1);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(2) << std::endl;
        continueGame();
        prologue.markChapterCompleted(2);
        GameState::saveGame(hero, prologue, filename);

        std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - “DOSTAN SIE DO MIASTA”" << std::endl;
        std::cout << prologue.getChapterContent(3) << std::endl;
        continueGame();
        std::cout << "SYSTEM: Rzut na percepcje" << std::endl;
        if (hero.perceptionTest(15)) {
            std::cout << "W oddali slyszysz skrzypniecie - nie drewna, a buta na suchym liscu. Ktos tu jest. Zatrzymujesz sie." << std::endl;
        }
        else {
            std::cout << "Jestes zbyt pochloniety wedrowaniem, by zauwazyc cien skradajacy sie miedzy drzewami. Gdy rozlega sie pierwszy okrzyk, jestes juz otoczo" << std::endl;
        }
        prologue.markChapterCompleted(3);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(4) << std::endl;
        continueGame();
        combat1.StartBattleSolo();
        combat2.StartBattleSolo();
        prologue.markChapterCompleted(4);
        GameState::saveGame(hero, prologue, filename);

        hero.CheckIfLevelUp();
        continueGame();
        std::cout << prologue.getChapterContent(5) << std::endl;
        continueGame();
        prologue.markChapterCompleted(5);
        std::cout << "SYSTEM: Rzut szczescia" << std::endl;
        if (hero.perceptionTest(2)) {
            std::cout << "Grzyb okazuje sie jadalny, ale brakuje mu przypraw" << std::endl;
        }
        else {
            std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
            hero.setHealthPoints(hero.getHealthPoints() - 5);
            std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
        }
        std::cout << "SYSTEM : Czas na odpoczynek twoje zdrowie oraz reszta statystyk regeneruja sie" << std::endl;
        restPoint.restoreEndurance(hero, hero.getFullEndurance());
        restPoint.restoreHP(hero, hero.getFullHp());
        restPoint.restoreMana(hero, hero.getFullMana());
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(6) << std::endl;
        plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
        plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
        plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
        trade.StartTrade(kruk, hero);
        if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
            std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: “Bracie…”" << std::endl;
        }
        prologue.markChapterCompleted(6);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(7) << std::endl;
        continueGame();
        int choice;
        //bool exit = true;
        while (exit) {
            std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
            std::cout << "1. Wybierz bron" << std::endl;
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
            }
            case 3: {
                std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
                exit = false;
                break;
            }
            default: {
                std::cout << "Nieprawidlowy wybor!" << std::endl;
                break;
            }
            }
        }
        continueGame();
        prologue.markChapterCompleted(7);
        GameState::saveGame(hero, prologue, filename);
        break;
    case 2:
        std::cout << prologue.getChapterContent(2) << std::endl;
        continueGame();
        prologue.markChapterCompleted(2);
        GameState::saveGame(hero, prologue, filename);

        std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - “DOSTAN SIE DO MIASTA”" << std::endl;
        std::cout << prologue.getChapterContent(3) << std::endl;
        continueGame();
        std::cout << "SYSTEM: Rzut na percepcje" << std::endl;
        if (hero.perceptionTest(15)) {
            std::cout << "W oddali slyszysz skrzypniecie - nie drewna, a buta na suchym liscu. Ktos tu jest. Zatrzymujesz sie." << std::endl;
        }
        else {
            std::cout << "Jestes zbyt pochloniety wedrowaniem, by zauwazyc cien skradajacy sie miedzy drzewami. Gdy rozlega sie pierwszy okrzyk, jestes juz otoczo" << std::endl;
        }
        prologue.markChapterCompleted(3);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(4) << std::endl;
        continueGame();
        combat1.StartBattleSolo();
        combat2.StartBattleSolo();
        prologue.markChapterCompleted(4);
        GameState::saveGame(hero, prologue, filename);

        hero.CheckIfLevelUp();
        continueGame();
        std::cout << prologue.getChapterContent(5) << std::endl;
        continueGame();
        prologue.markChapterCompleted(5);
        std::cout << "SYSTEM: Rzut szczescia" << std::endl;
        if (hero.perceptionTest(2)) {
            std::cout << "Grzyb okazuje sie jadalny, ale brakuje mu przypraw" << std::endl;
        }
        else {
            std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
            hero.setHealthPoints(hero.getHealthPoints() - 5);
            std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
        }
        std::cout << "SYSTEM : Czas na odpoczynek twoje zdrowie oraz reszta statystyk regeneruja sie" << std::endl;
        restPoint.restoreEndurance(hero, hero.getFullEndurance());
        restPoint.restoreHP(hero, hero.getFullHp());
        restPoint.restoreMana(hero, hero.getFullMana());
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(6) << std::endl;
        plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
        plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
        plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
        trade.StartTrade(kruk, hero);
        if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
            std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: “Bracie…”" << std::endl;
        }
        prologue.markChapterCompleted(6);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(7) << std::endl;
        continueGame();
        //int choice;
        //bool exit = true;
        while (exit) {
            std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
            std::cout << "1. Wybierz bron" << std::endl;
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
            }
            case 3: {
                std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
                exit = false;
                break;
            }
            default: {
                std::cout << "Nieprawidlowy wybor!" << std::endl;
                break;
            }
            }
        }
        continueGame();
        prologue.markChapterCompleted(7);
        GameState::saveGame(hero, prologue, filename);
        break;
    case 3:
        std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - “DOSTAN SIE DO MIASTA”" << std::endl;
        std::cout << prologue.getChapterContent(3) << std::endl;
        continueGame();
        std::cout << "SYSTEM: Rzut na percepcje" << std::endl;
        if (hero.perceptionTest(15)) {
            std::cout << "W oddali slyszysz skrzypniecie - nie drewna, a buta na suchym liscu. Ktos tu jest. Zatrzymujesz sie." << std::endl;
        }
        else {
            std::cout << "Jestes zbyt pochloniety wedrowaniem, by zauwazyc cien skradajacy sie miedzy drzewami. Gdy rozlega sie pierwszy okrzyk, jestes juz otoczo" << std::endl;
        }
        prologue.markChapterCompleted(3);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(4) << std::endl;
        continueGame();
        combat1.StartBattleSolo();
        combat2.StartBattleSolo();
        prologue.markChapterCompleted(4);
        GameState::saveGame(hero, prologue, filename);

        hero.CheckIfLevelUp();
        continueGame();
        std::cout << prologue.getChapterContent(5) << std::endl;
        continueGame();
        prologue.markChapterCompleted(5);
        std::cout << "SYSTEM: Rzut szczescia" << std::endl;
        if (hero.perceptionTest(2)) {
            std::cout << "Grzyb okazuje sie jadalny, ale brakuje mu przypraw" << std::endl;
        }
        else {
            std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
            hero.setHealthPoints(hero.getHealthPoints() - 5);
            std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
        }
        std::cout << "SYSTEM : Czas na odpoczynek twoje zdrowie oraz reszta statystyk regeneruja sie" << std::endl;
        restPoint.restoreEndurance(hero, hero.getFullEndurance());
        restPoint.restoreHP(hero, hero.getFullHp());
        restPoint.restoreMana(hero, hero.getFullMana());
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(6) << std::endl;
        plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
        plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
        plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
        trade.StartTrade(kruk, hero);
        if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
            std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: “Bracie…”" << std::endl;
        }
        prologue.markChapterCompleted(6);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(7) << std::endl;
        continueGame();
        //int choice;
       // bool exit = true;
        while (exit) {
            std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
            std::cout << "1. Wybierz bron" << std::endl;
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
            }
            case 3: {
                std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
                exit = false;
                break;
            }
            default: {
                std::cout << "Nieprawidlowy wybor!" << std::endl;
                break;
            }
            }
        }
        continueGame();
        prologue.markChapterCompleted(7);
        GameState::saveGame(hero, prologue, filename);
        break;
    case 4:
        std::cout << prologue.getChapterContent(4) << std::endl;
        continueGame();
        combat1.StartBattleSolo();
        combat2.StartBattleSolo();
        prologue.markChapterCompleted(4);
        GameState::saveGame(hero, prologue, filename);

        hero.CheckIfLevelUp();
        continueGame();
        std::cout << prologue.getChapterContent(5) << std::endl;
        continueGame();
        prologue.markChapterCompleted(5);
        std::cout << "SYSTEM: Rzut szczescia" << std::endl;
        if (hero.perceptionTest(2)) {
            std::cout << "Grzyb okazuje sie jadalny, ale brakuje mu przypraw" << std::endl;
        }
        else {
            std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
            hero.setHealthPoints(hero.getHealthPoints() - 5);
            std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
        }
        std::cout << "SYSTEM : Czas na odpoczynek twoje zdrowie oraz reszta statystyk regeneruja sie" << std::endl;
        restPoint.restoreEndurance(hero, hero.getFullEndurance());
        restPoint.restoreHP(hero, hero.getFullHp());
        restPoint.restoreMana(hero, hero.getFullMana());
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(6) << std::endl;
        plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
        plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
        plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
        trade.StartTrade(kruk, hero);
        if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
            std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: “Bracie…”" << std::endl;
        }
        prologue.markChapterCompleted(6);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(7) << std::endl;
        continueGame();
        //int choice;
        //bool exit = true;
        while (exit) {
            std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
            std::cout << "1. Wybierz bron" << std::endl;
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
            }
            case 3: {
                std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
                exit = false;
                break;
            }
            default: {
                std::cout << "Nieprawidlowy wybor!" << std::endl;
                break;
            }
            }
        }
        continueGame();
        prologue.markChapterCompleted(7);
        GameState::saveGame(hero, prologue, filename);
        break;
    case 5:
        hero.CheckIfLevelUp();
        continueGame();
        std::cout << prologue.getChapterContent(5) << std::endl;
        continueGame();
        prologue.markChapterCompleted(5);
        std::cout << "SYSTEM: Rzut szczescia" << std::endl;
        if (hero.perceptionTest(2)) {
            std::cout << "Grzyb okazuje sie jadalny, ale brakuje mu przypraw" << std::endl;
        }
        else {
            std::cout << "Grzyb okazuje sie nie dobry zaczynasz odczuwac dziwne efekty" << std::endl;
            hero.setHealthPoints(hero.getHealthPoints() - 5);
            std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
        }
        std::cout << "SYSTEM : Czas na odpoczynek twoje zdrowie oraz reszta statystyk regeneruja sie" << std::endl;
        restPoint.restoreEndurance(hero, hero.getFullEndurance());
        restPoint.restoreHP(hero, hero.getFullHp());
        restPoint.restoreMana(hero, hero.getFullMana());
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(6) << std::endl;
        plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
        plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
        plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
        trade.StartTrade(kruk, hero);
        if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
            std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: “Bracie…”" << std::endl;
        }
        prologue.markChapterCompleted(6);
        GameState::saveGame(hero, prologue, filename);

        std::cout << prologue.getChapterContent(7) << std::endl;
        continueGame();
        //int choice;
       // bool exit = true;
        while (exit) {
            std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
            std::cout << "1. Wybierz bron" << std::endl;
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
            }
            case 3: {
                std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
                exit = false;
                break;
            }
            default: {
                std::cout << "Nieprawidlowy wybor!" << std::endl;
                break;
            }
            }
        }
        continueGame();
        prologue.markChapterCompleted(7);
        GameState::saveGame(hero, prologue, filename);
        break;
    case 6:
        std::cout << prologue.getChapterContent(6) << std::endl;
        plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
        plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
        plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
        trade.StartTrade(kruk, hero);
        if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
            std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: “Bracie…”" << std::endl;
        }
        prologue.markChapterCompleted(6);
        GameState::saveGame(hero, prologue, filename);

       
    case 7:
        std::cout << prologue.getChapterContent(7) << std::endl;
        continueGame();
       // int choice;
       // bool exit = true;
        while (exit) {
            std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
            std::cout << "1. Wybierz bron" << std::endl;
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
            }
            case 3: {
                std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
                exit = false;
                break;
            }
            default: {
                std::cout << "Nieprawidlowy wybor!" << std::endl;
                break;
            }
            }
        }
        continueGame();
        prologue.markChapterCompleted(7);
        GameState::saveGame(hero, prologue, filename);
        break;
    default:
        std::cout << "Wszystkie rozdzialy zostaly ukonczone! Gratulacje!\n";
        return;
    }

    GameState::saveGame(hero, act, filename);
    continueGame();
}


void Game::continueGame() {
	std::cout << "Naciœnij Enter, aby kontynuowac...";
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
    hero.CreateHero(sword, bow, magicStick);
    continueGame();
    hero.levelUp();
    continueGame();

    // rozdzial 1 
    Act prologue;
    prologue.loadFromFile("Prolog.txt");
    std::cout << prologue.getChapterContent(1) << std::endl;
    std::cout << "SYSTEM: Rzut na percepcje" << std::endl;
    if (hero.perceptionTest(5)) {
        std::cout << "Twoje palce przesuwaja sie po papierze tworzac smuge na slowach napisanych czarnym atramentem.\n Zauwazasz, ze kartka jest stara, brudna i pelna smug podobnych do tych, ktore wlasnie stworzyles.\n ";
        if (hero.perceptionTest(10)) {
            std::cout << "Po dokladniejszym zbadaniu czujesz, ze cos w Twoim wnetrzu ciagnie Cie naprzod, jakby te slowa nie byly zapisane na papierze, tylko wypalone wewnatrz Ciebie. \n";
        }
    }
    else {
        std::cout << "Nie zauwazasz niczego szczegolnego na kartce.\n";
    }
    prologue.markChapterCompleted(1);
    GameState::saveGame(hero, prologue, filename);

    // rozdzial 2
    std::cout << prologue.getChapterContent(2) << std::endl;
    continueGame();
    prologue.markChapterCompleted(2);
    GameState::saveGame(hero, prologue, filename);

    // rozdzial 3 
    std::cout << "SYSTEM: ZADANIE ZAKTUALIZOWANE - 'DOSTAN SIE DO MIASTA'" << std::endl;
    std::cout << prologue.getChapterContent(3) << std::endl;
    continueGame();
    std::cout << "SYSTEM: Rzut na percepcje" << std::endl;
    if (hero.perceptionTest(15)) {
        std::cout << "W oddali slyszysz skrzypniecie - nie drewna, a buta na suchym liscu. Ktos tu jest. Zatrzymujesz sie." << std::endl;
    }
    else {
        std::cout << "Jestes zbyt pochloniety wedrowaniem, by zauwazyc cien skradajacy sie miedzy drzewami. Gdy rozlega sie pierwszy okrzyk, jestes juz otoczony." << std::endl;
    }

    prologue.markChapterCompleted(3);
    GameState::saveGame(hero, prologue, filename);

    // rozdzial 4 
    std::cout << prologue.getChapterContent(4) << std::endl;
    continueGame();
    Hero Companion("Bezimienny", 15, 0, 0, 10, 10, 10, 10, 10, 10);
    Goblin goblin("Rzezimizeszek Starszy", "Goblin", 5, 25, 75);
    Goblin goblin2("Rzezimizeszek Sredni", "Goblin", 5, 15, 25);
    Combat combat1(hero, Companion, goblin);
    combat1.StartBattleSolo();
    Combat combat2(hero, Companion, goblin2);
    combat2.StartBattleSolo();
    prologue.markChapterCompleted(4);
    GameState::saveGame(hero, prologue, filename);

    // rozdzial 5
    hero.CheckIfLevelUp();
    continueGame();
    std::cout << prologue.getChapterContent(5) << std::endl;
    continueGame();

    prologue.markChapterCompleted(5);
    std::cout << "SYSTEM: Rzut szczescia" << std::endl;
    if (hero.perceptionTest(2)) {
        std::cout << "Grzyb okazuje sie jadalny, ale brakuje mu przypraw" << std::endl;
    }
    else {
        std::cout << "Grzyb okazuje sie niedobry, zaczynasz odczuwac dziwne efekty" << std::endl;
        hero.setHealthPoints(hero.getHealthPoints() - 5);
        std::cout << "Otrzymujesz minus 5 punktow zdrowia" << std::endl;
    }
    std::cout << "SYSTEM: Czas na odpoczynek - Twoje zdrowie oraz reszta statystyk regeneruja sie" << std::endl;
    RestPoint restPoint("Odpoczynek w lesie");
    restPoint.restoreEndurance(hero, hero.getFullEndurance());
    restPoint.restoreHP(hero, hero.getFullHp());
    restPoint.restoreMana(hero, hero.getFullMana());
    GameState::saveGame(hero, prologue, filename);

    // rozdzial 6
    std::cout << prologue.getChapterContent(6) << std::endl;
    Equipment plecakSklepikarza;
    plecakSklepikarza.addWeapon(new Sword("zmatowialy medalion", 0, 0, 1));
    plecakSklepikarza.addWeapon(new Bow("Zardzewialy luk", 15, 1, 5));
    plecakSklepikarza.addPotion(new Potion(Potion::Type::Health, 20, 8));
    NPC kruk("Kruk", plecakSklepikarza);
    Trade trade;
    trade.StartTrade(kruk, hero);
    if (hero.getEquipment().getWeapon(0)->getName() == "zmatowialy medalion" || hero.getEquipment().getWeapon(1)->getName() == "zmatowialy medalion") {
        std::cout << "Gdy tylko przedmiot znajdzie sie w Twojej dloni, swiat sie przechyla. Przez sekunde jestes gdzies indziej. Krew na dloniach, czyjs krzyk. Obraz zbroi, w ktora wgniatasz ostrze. Czule slowo, szept: 'Bracie...'" << std::endl;
    }
    prologue.markChapterCompleted(6);
    GameState::saveGame(hero, prologue, filename);

    // rozdzial 7
    std::cout << prologue.getChapterContent(7) << std::endl;
    continueGame();
    int choice;
    bool exit = true;
    while (exit) {
        std::cout << "SYSTEM: Wybierz co chcesz zrobic" << std::endl;
        std::cout << "1. Wybierz bron" << std::endl;
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
        }
        case 3: {
            std::cout << "Nic nie robisz, odpoczywasz w lesie." << std::endl;
            exit = false;
            break;
        }
        default:
            std::cout << "Nieprawidlowy wybor!" << std::endl;
            break;
        }
    }

    continueGame();
    prologue.markChapterCompleted(7);
    GameState::saveGame(hero, prologue, filename);
}

