#include "Companion.h"
#include <iostream>

/**
 * @brief Konstruktor klasy Companion
 * 
 * Inicjalizuje statystyki towarzysza oraz jego początkową lojalność na poziomie 50/100.
 * Dodaje również podstawowe kwestie dialogowe.
 */
Companion::Companion(std::string name, int health, int strength, int intelligence, int dexterity, int luck)
    : Character(name, health, strength, intelligence, dexterity, luck), loyalty(50)
{
    // Inicjalizacja podstawowych dialogów
    dialogues.push_back("Chcesz? Znalazłem przy strumieniu. Nie śmierdzi aż tak bardzo, jak wygląda.");
    dialogues.push_back("Zawsze za tobą, stary.");
    dialogues.push_back("Te grzyby są chyba jadalne... chyba.");
    dialogues.push_back("...");
}

/**
 * @brief Implementacja ataku towarzysza
 * 
 * Towarzysz wykonuje podstawowy atak fizyczny na cel.
 * Obrażenia są obliczane na podstawie siły i rzutu k10.
 * 
 * @param target Cel ataku (dowolna postać)
 */
void Companion::attack(Character& target)
{
    // Podstawowa implementacja ataku
    std::uniform_int_distribution<int> d10(1, 10);
    int damage = strength / 2 + d10(rng);
    
    std::cout << name << " atakuje i zadaje " << damage << " obrażeń!" << std::endl;
    
    int targetHealth = target.getHealth() - damage;
    target.setHealth(targetHealth > 0 ? targetHealth : 0);
}

/**
 * @brief Implementacja obrony towarzysza
 * 
 * Na razie prosta implementacja bez efektów mechanicznych.
 */
void Companion::defend()
{
    std::cout << name << " przyjmuje postawę obronną." << std::endl;
}

/**
 * @brief Implementacja używania przedmiotu przez towarzysza
 * 
 * @param itemId ID przedmiotu do użycia
 */
void Companion::useItem(int itemId)
{
    std::cout << name << " używa przedmiotu." << std::endl;
}

/**
 * @brief Funkcja zbierania grzybów przez towarzysza
 * 
 * Zgodnie z instructions.md, towarzysz ma zamiłowanie do grzybów i może
 * znajdować różne ich rodzaje podczas odpoczynku. Jest to jedna z głównych
 * mechanik interakcji z tą postacią.
 * 
 * @return std::string Nazwa znalezionego grzyba
 */
std::string Companion::gatherMushroom()
{
    // Towarzysz zbiera grzyby - zgodnie z instructions.md
    std::string mushroomTypes[] = {
        "fioletowy grzyb z czerwonymi porami",
        "brązowy kapelusz z białym trzonem",
        "mały czerwony grzyb z białymi kropkami",
        "blady grzyb o błękitnym odcieniu",
        "zielonkawy grzyb z czarnym trzonem"
    };
    
    std::uniform_int_distribution<int> distribution(0, 4);
    int index = distribution(rng);
    
    std::cout << name << " znalazł " << mushroomTypes[index] << "." << std::endl;
    return mushroomTypes[index];
}

/**
 * @brief Rzut kością k6 na efekt grzyba
 * 
 * Zgodnie z instructions.md, efekt zjedzenia grzyba zależy od rzutu k6:
 * - 1-2: Trujący (-1HP, -1 do następnego testu percepcji)
 * - 3-4: Bez efektu ("Grzyb okazuje się jadalny, ale brakuje mu przypraw")
 * - 5-6: Uczucie jasności (+1 do następnego testu percepcji)
 * 
 * @return int Wynik rzutu k6 (1-6)
 */
int Companion::rollMushroomEffect()
{
    // Rzut k6 na efekt grzyba zgodnie z instructions.md
    std::uniform_int_distribution<int> d6(1, 6);
    return d6(rng);
}

/**
 * @brief Funkcja obsługująca dialogi towarzysza
 * 
 * Na razie prosta implementacja - wybiera losowy dialog z kolekcji.
 * W przyszłości można rozszerzyć o bardziej złożony system dialogowy.
 * 
 * @param dialogKey Klucz dialogu (obecnie nieużywany)
 */
void Companion::speak(const std::string& dialogKey)
{
    // Dla uproszczenia, wybieramy losowy dialog
    if (!dialogues.empty()) {
        std::uniform_int_distribution<int> distribution(0, dialogues.size() - 1);
        int index = distribution(rng);
        std::cout << name << ": \"" << dialogues[index] << "\"" << std::endl;
    }
    else {
        std::cout << name << " nie ma nic do powiedzenia." << std::endl;
    }
}
