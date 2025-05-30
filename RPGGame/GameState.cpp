#include "GameState.h"
#include <fstream>
#include <iostream>
#include "Equipment.h"
#include "Weapon.h"
#include "Potion.h"
#include "Sword.h"
#include "Bow.h"
#include "MagicStick.h"
#include "Act.h"

bool GameState::saveGame(const Hero& hero, const Act& act, const std::string& filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu: " << filename << std::endl;
        return false;
    }

    ofs << "Name " << hero.getName() << "\n";
    ofs << "HealthPoints " << hero.getHealthPoints() << "\n";
    ofs << "Level " << hero.getLevel() << "\n";
    ofs << "XP " << hero.getXP() << "\n";
    ofs << "Strength " << hero.getStrength() << "\n";
    ofs << "Intelligence " << hero.getIntelligence() << "\n";
    ofs << "Dexterity " << hero.getDexterity() << "\n";
    ofs << "Luck " << hero.getLuck() << "\n";
    ofs << "Endurance " << hero.getEndurance() << "\n";
    ofs << "Mana " << hero.getMana() << "\n";

    saveEquipment(ofs, hero.getEquipment());

    ofs << "StoryProgress\n";
    for (int i = 0; i < 100; ++i) {
        if (act.isChapterCompleted(i)) {
            ofs << "ChapterCompleted " << i << "\n";
        }
    }

    ofs << "EndStory\n";
    ofs.close();
    return true;
}

bool GameState::loadGame(Hero& hero, Act& act, const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do odczytu: " << filename << std::endl;
        return false;
    }

    std::string key;
    while (ifs >> key) {
        if (key == "Name") {
            std::string value; ifs >> value; hero.setName(value);
        }
        else if (key == "HealthPoints") {
            double val; ifs >> val; hero.setHealthPoints(val);
        }
        else if (key == "Level") {
            int val; ifs >> val; hero.setLevel(val);
        }
        else if (key == "XP") {
            double val; ifs >> val; hero.setXP(val);
        }
        else if (key == "Strength") {
            int val; ifs >> val; hero.setStrength(val);
        }
        else if (key == "Intelligence") {
            int val; ifs >> val; hero.setIntelligence(val);
        }
        else if (key == "Dexterity") {
            int val; ifs >> val; hero.setDexterity(val);
        }
        else if (key == "Luck") {
            int val; ifs >> val; hero.setLuck(val);
        }
        else if (key == "Endurance") {
            int val; ifs >> val; hero.setEndurance(val);
        }
        else if (key == "Mana") {
            double val; ifs >> val; hero.setMana(val);
        }
        else if (key == "EquipmentStart") {
            loadEquipment(ifs, hero);
        }
        else if (key == "StoryProgress") {
            std::string subkey;
            while (ifs >> subkey && subkey != "EndStory") {
                if (subkey == "ChapterCompleted") {
                    int chapterId; ifs >> chapterId;
                    act.markChapterCompleted(chapterId);
                }
            }
        }
    }

    ifs.close();
    return true;
}

void GameState::saveEquipment(std::ofstream& ofs, const Equipment& equipment) {
    ofs << "EquipmentStart\n";
    int weaponCount = equipment.getWeaponCount();
    ofs << "WeaponsCount " << weaponCount << "\n";
    for (int i = 0; i < 2; ++i) {
        Weapon* w = equipment.getWeapon(i);
        if (w) {
            ofs << "Weapon " << i << " " << w->getName() << " " << w->getAttackDamage() << " "
                << w->getMagicPower() << " " << w->getValue() << "\n";
        }
    }

    int potionCount = equipment.getPotionCount();
    ofs << "PotionsCount " << potionCount << "\n";
    for (int i = 0; i < 5; ++i) {
        Potion* p = equipment.getPotion(i);
        if (p) {
            ofs << "Potion " << i << " "
                << (p->getType() == Potion::Type::Health ? "Health" : "Mana") << " "
                << p->getAmount() << "\n";
        }
    }
    ofs << "EquipmentEnd\n";
}

void GameState::loadEquipment(std::ifstream& ifs, Hero& hero) {
    Equipment& equipment = hero.getEquipment();
    std::string key;
    while (ifs >> key) {
        if (key == "EquipmentEnd") break;
        else if (key == "Weapon") {
            int index; std::string name; double attackDamage, magicPower, value;
            ifs >> index >> name >> attackDamage >> magicPower >> value;
            Weapon* weapon = createWeaponByName(name);
            if (!weapon) weapon = new Sword(name, attackDamage, magicPower, value);
            equipment.addWeapon(weapon);
            if (index == 0) hero.setHand(weapon);
        }
        else if (key == "Potion") {
            int index; std::string typeStr; double amount;
            ifs >> index >> typeStr >> amount;
            Potion::Type type = (typeStr == "Health") ? Potion::Type::Health : Potion::Type::Mana;
            equipment.addPotion(new Potion(type, amount, 0));
        }
    }
}

Weapon* GameState::createWeaponByName(const std::string& name) {
    if (name == "Excalibur") {
        return new Sword("Excalibur", 20.0, 10.0, 10);
    }
    else if (name == "Longbow") {
        return new Bow("Longbow", 15.0, 5.0, 10);
    }
    else if (name == "Elder Wand") {
        return new MagicStick("Elder Wand", 25.0, 15.0, 10);
    }
    // Jesli nazwa nieznana, mozesz zwrocic nullptr lub domyslna bron
    return nullptr;
}

bool GameState::hasSaveFile(const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

bool GameState::shouldLoadGame(const std::string& filename) {
    if (hasSaveFile(filename)) {
        std::cout << "Znaleziono zapis gry.\n";
        std::cout << "1. Wczytaj gre\n";
        std::cout << "2. Nowa gra\n";
        std::cout << "Wybierz opcje: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // czysci enter po cin

        if (choice == 1) {
            return true;
        }
        else {
            // Usun plik save.txt jesli istnieje
            if (std::remove(filename.c_str()) == 0) {
                std::cout << "Poprzedni zapis gry zostal usuniety.\n";
            }
            else {
                std::cerr << "Nie udalo sie usunac pliku zapisu.\n";
            }
            return false;
        }
    }
    else {
        std::cout << "Nie znaleziono zapisu gry. Tworze nowa gre...\n";
        return false;
    }
}

int GameState::getNextChapterFromSave(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return 1;
    }

    std::string line;
    int lastChapter = 0;

    while (std::getline(file, line)) {
        if (line.find("ChapterCompleted") == 0) {
            size_t spacePos = line.find(' ');
            if (spacePos != std::string::npos) {
                std::string numberStr = line.substr(spacePos + 1);
                try {
                    lastChapter = std::stoi(numberStr);
                }
                catch (...) {
                    // ignoruj blad konwersji
                }
            }
        }
    }

    file.close();
    return lastChapter + 1; // nastepny do rozegrania
}
