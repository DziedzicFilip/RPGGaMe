#include "GameState.h"
#include "Hero.h"
#include "Equipment.h"
#include "Weapon.h"
#include "Sword.h"
#include "Bow.h"
#include "MagicStick.h"
#include "Potion.h"
#include <fstream>
#include <iostream>

// --- Zapis stanu gry ---
bool GameState::saveGame(const Hero& hero, const std::string& filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu: " << filename << std::endl;
        return false;
    }

    // Zapis podstawowych statystyk
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

    // Zapis ekwipunku
    saveEquipment(ofs, hero.getEquipment());

    ofs.close();
    return true;
}

// --- Wczytanie stanu gry ---
bool GameState::loadGame(Hero& hero, const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do odczytu: " << filename << std::endl;
        return false;
    }

    std::string key;
    while (ifs >> key) {
        if (key == "Name") {
            std::string value;
            ifs >> value;
            hero.setName(value);
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
    }

    ifs.close();
    return true;
}

// --- Zapis ekwipunku ---
void GameState::saveEquipment(std::ofstream& ofs, const Equipment& equipment) {
    ofs << "EquipmentStart\n";

    // Bronie
    int weaponCount = equipment.getWeaponCount();
    ofs << "WeaponsCount " << weaponCount << "\n";
    for (int i = 0; i < 2; ++i) {
        Weapon* w = equipment.getWeapon(i);
        if (w) {
            ofs << "Weapon " << i << " " << w->getName() << " " << w->getAttackDamage() << " "
                << w->getMagicPower() << " " << w->getScaling() << " " << w->getValue() << "\n";
        }
    }

    // Mikstury
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

// --- Wczytanie ekwipunku ---
void GameState::loadEquipment(std::ifstream& ifs, Hero& hero) {
    Equipment& equipment = hero.getEquipment();

    std::string key;
    while (ifs >> key) {
        if (key == "EquipmentEnd") {
            break;
        }
        else if (key == "WeaponsCount") {
            int count; ifs >> count;
            // Nie potrzebujemy tego do wczytania, ale mo¿na zachowaæ
        }
        else if (key == "Weapon") {
            int index;
            std::string name;
            double attackDamage, magicPower, value;
            std::string scaling;

            ifs >> index >> name >> attackDamage >> magicPower >> scaling >> value;
            Weapon* weapon = createWeaponByName(name);
            if (weapon == nullptr) {
                // Jeœli nie ma takiej broni, stworzymy "domyœln¹"
                // np. miecz z podanymi statystykami
                weapon = new Sword(name, attackDamage, magicPower, value);
            }
            // Ustaw statystyki broni w razie potrzeby, tutaj pomijamy dla uproszczenia
            equipment.addWeapon(weapon);

            // Jeœli indeks 0 to ustawiamy rêkê bohatera
            if (index == 0) {
                hero.setHand(weapon);
            }
        }
        else if (key == "PotionsCount") {
            int count; ifs >> count;
            // Mo¿na wykorzystaæ jeœli potrzebne
        }
        else if (key == "Potion") {
            int index; std::string typeStr; int amount;
            ifs >> index >> typeStr >> amount;

            Potion::Type type = (typeStr == "Health") ? Potion::Type::Health : Potion::Type::Mana;
            Potion* potion = new Potion(type, amount,10);
            equipment.addPotion(potion);
        }
    }
}

// --- Tworzenie broni na podstawie nazwy (proste mapowanie) ---
Weapon* GameState::createWeaponByName(const std::string& name) {
    // Mo¿esz tutaj zaimplementowaæ mapowanie nazw na klasy
    // Na przyk³ad:
    if (name.find("Sword") != std::string::npos) {
        return new Sword(name, 10, 0, 100);  // statyczne dummy wartoœci
    }
    else if (name.find("Bow") != std::string::npos) {
        return new Bow(name, 8, 0, 50);
    }
    else if (name.find("MagicStick") != std::string::npos) {
        return new MagicStick(name, 5, 15, 75);
    }
    return nullptr;
}
