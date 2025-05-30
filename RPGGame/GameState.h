// GameState.h
#include  "Hero.h"
#include "Act.h"
class GameState {
public:
    static bool saveGame(const Hero& hero, const Act& act, const std::string& filename);
    static bool loadGame(Hero& hero, Act& act, const std::string& filename);
    static bool hasSaveFile(const std::string& filename);  // <-- NOWA
    static bool shouldLoadGame(const std::string& filename);
    static int getNextChapterFromSave(const std::string& filename);
private:
    static void saveEquipment(std::ofstream& ofs, const Equipment& equipment);
    static void loadEquipment(std::ifstream& ifs, Hero& hero);
    static Weapon* createWeaponByName(const std::string& name);
    
};
