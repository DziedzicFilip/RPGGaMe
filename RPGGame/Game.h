#pragma once
#include <string>
#include "Hero.h"
#include "Act.h"

class Game {
public:
    Game(); 
    Game(const std::string& saveFile); 
    void continueLoadedGame(); 
    void start(); 

private:
    Hero hero;
    Act act;
    std::string filename = "save.txt";

    void createNewGame(); 
    
	void continueGame(); 
};
