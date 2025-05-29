#pragma once
#include <string>
#include "Hero.h"
#include "Act.h"

class Game {
public:
    Game(); // nowa gra
    Game(const std::string& saveFile); // wczytanie gry z pliku
    void continueLoadedGame(); // pomocnicza do kontynuacji gry
    void start(); // odpala g³ówn¹ pêtlê gry

private:
    Hero hero;
    Act act;
    std::string filename = "save.txt";

    void createNewGame(); // pomocnicza do nowej gry
    
	void continueGame(); // pomocnicza do kontynuacji gry po ka¿dym rozdziale
};
