#pragma once
#include <string>
#include "Hero.h"

class GameState {
public:
    // Zapis stanu do pliku
    static bool saveGame(const Hero& hero, const std::string& filename);

    // Wczytanie stanu z pliku
    static bool loadGame(Hero& hero, const std::string& filename);

private:
    // Pomocnicze metody do zapisu / odczytu ekwipunku
    static void saveEquipment(std::ofstream& ofs, const Equipment& equipment);
    static void loadEquipment(std::ifstream& ifs, Hero& hero);

    // Pomocnicze do broni
    static Weapon* createWeaponByName(const std::string& name);
};
